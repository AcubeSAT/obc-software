#include "CAN/ApplicationLayer.hpp"
#include "CAN/Driver.hpp"
#include "CAN/TPMessage.hpp"
#include "CAN/TPProtocol.hpp"
#include "CANGatekeeperTask.hpp"

namespace CAN::Application {
    ActiveBus switchBus(ActiveBus bus = PlatformParameters::obcCANBUSActive.getValue()) {
        if (bus == Main) {
            PlatformParameters::obcCANBUSActive.setValue(Redundant);
        } else {
            PlatformParameters::obcCANBUSActive.setValue(Main);
        }
        CAN::Driver::toggleActiveBus(PlatformParameters::obcCANBUSActive.getValue());
        return PlatformParameters::obcCANBUSActive.getValue();
    }

    void sendPingMessage(uint8_t destinationAddress, bool isMulticast) {
        TPMessage message = {{NodeID, destinationAddress, isMulticast}};

        message.appendUint8(Ping);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void sendPongMessage() {
        TPMessage message = {{NodeID, OBC, false}};

        message.appendUint8(Pong);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void sendHeartbeatMessage() {
        canGatekeeperTask->send({MessageIDs::Heartbeat + CAN::NodeID});
    }

    void sendBusSwitchoverMessage() {
        etl::array<uint8_t, CAN::Frame::MaxDataLength> data = {switchBus()};

        canGatekeeperTask->send({MessageIDs::BusSwitchover + CAN::NodeID, data});
    }

    void sendUTCTimeMessage() {
        auto now = TimeGetter::getCurrentTimeDefaultCUC();

        std::chrono::duration<uint64_t, std::milli> msOfDay = now.asDuration(); //TODO: This doesn't reset every day, only since epoch.

        UTCTimestamp utc = now.toUTCtimestamp();
        etl::array<uint8_t, CAN::Frame::MaxDataLength> data = {0, 0, static_cast<uint8_t>(msOfDay.count()),
                                                               static_cast<uint8_t>(msOfDay.count() >> 8),
                                                               static_cast<uint8_t>(msOfDay.count() >> 16),
                                                               static_cast<uint8_t>(msOfDay.count() >> 24), 0,
                                                               utc.day}; //TODO: days parameter should not be uint8_t

        canGatekeeperTask->send({MessageIDs::UTCTime + CAN::NodeID, data});
    }

    void createSendParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                     const etl::vector<uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs) {
        CAN::TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::SendParameters);
        message.appendUint16(parameterIDs.size());
        for (auto parameterID: parameterIDs) {
            if (Services.parameterManagement.getParameter(parameterID)) {
                message.append(parameterID);
                Services.parameterManagement.getParameter(parameterID)->get().appendValueToMessage(message);
            } else {
                LOG_ERROR << "Requested parameter that doesn't exist! ID: " << parameterID;
            }
        }

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createRequestParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                        const etl::vector<uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs) {
        CAN::TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::RequestParameters);
        message.appendUint16(parameterIDs.size());

        if constexpr (Logger::isLogged(Logger::debug)) {
            String<128> logString = "Requesting parameters with ID: ";
            for (auto parameterID: parameterIDs) {
                etl::to_string(parameterID, logString, true);
                message.append(parameterID);
            }
            LOG_DEBUG << logString.c_str();
        } else {
            for (auto parameterID: parameterIDs) {
                message.append(parameterID);
            }
        }

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createPerformFunctionMessage(uint8_t destinationAddress, bool isMulticast, uint64_t functionId,
                                      const etl::map<uint8_t, uint64_t, TPMessageMaximumArguments> &arguments) {
        CAN::TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::PerformFunction);

        //TODO Find a more readable way to append a 6 byte variable to this message
        message.appendUint16(functionId >> 4 * 8);
        message.appendUint32(functionId & 0xffffffff);

        message.appendUint16(arguments.size());

        for (auto argument: arguments) {
            message.appendUint8(argument.first);
            message.appendUint64(argument.second);
        }

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createEventReportMessage(uint8_t destinationAddress, bool isMulticast, EventReportType type, uint16_t eventID,
                                  const Message &eventData) {
        CAN::TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::EventReport);
        message.appendEnum8(type);
        message.appendUint16(eventID);
        message.appendMessage(eventData, eventData.dataSize);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createPacketMessage(uint8_t destinationAddress, bool isMulticast, const Message &incomingMessage) {
        CAN::TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        etl::string<ECSSMaxMessageSize> messageHeader = MessageParser::composeECSS(incomingMessage);

        if (message.packetType == Message::TM) {
            message.appendUint8(MessageIDs::TMPacket);
        } else {
            message.appendUint8(MessageIDs::TCPacket);
        }

        //TODO Check how this should be done, I feel like it's not correct
        message.appendString(messageHeader);
        message.appendMessage(incomingMessage, incomingMessage.dataSize);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createCCSDSPacketMessage(uint8_t destinationAddress, bool isMulticast, const Message &incomingMessage) {
        CAN::TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        auto ccsdsMessage = MessageParser::compose(incomingMessage);

        message.appendUint8(MessageIDs::CCSDSPacket);
        message.appendString(ccsdsMessage);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createLogMessage(uint8_t destinationAddress, bool isMulticast, const String<LOGGER_MAX_MESSAGE_SIZE> &log) {
        CAN::TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::LogMessage);
        message.appendString(log);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void parseMessage(const CAN::Frame &message) {
        uint32_t id = filterMessageID(message.id);
        if (id == Heartbeat) {
//            registerHeartbeat();
        } else if (id == BusSwitchover) {
            switchBus(static_cast<ActiveBus>(message.data[0]));
        } else if (id == UTCTime) {
//            registerUTCTime();
        }
    }

    void parseSendParametersMessage(TPMessage &message) {
        uint8_t messageType = message.readUint8();
        if (ErrorHandler::assertInternal(messageType == SendParameters, ErrorHandler::UnknownMessageType)) {
            return;
        }
        uint16_t parameterCount = message.readUint16();

        for (uint16_t idx = 0; idx < parameterCount; idx++) {
            uint16_t parameterID = message.readUint16();
            if (Services.parameterManagement.parameterExists(parameterID)) {
                if constexpr (Logger::isLogged(Logger::debug)) {
                    String<64> logString = "The value for parameter with ID ";
                    etl::to_string(parameterID, logString, true);
                    logString.append(" was ");

                    auto parameter = Services.parameterManagement.getParameter(parameterID);
                    etl::to_string(parameter->get().getValueAsDouble(), logString, true);

                    parameter->get().setValueFromMessage(message);
                    logString.append(" and is now ");
                    etl::to_string(parameter->get().getValueAsDouble(), logString, true);

                    LOG_DEBUG << logString.c_str();
                } else {
                    Services.parameterManagement.getParameter(parameterID)->get().setValueFromMessage(message);
                }
            }
        }
    }

    void parseRequestParametersMessage(TPMessage &message) {
        uint8_t messageType = message.readUint8();
        if (ErrorHandler::assertInternal(messageType == RequestParameters, ErrorHandler::UnknownMessageType)) {
            return;
        }
        uint16_t parameterCount = message.readUint16();
        etl::vector<uint16_t, TPMessageMaximumArguments> parameterIDs;

        for (uint16_t idx = 0; idx < parameterCount; idx++) {
            parameterIDs.push_back(message.readUint16());
        }

        createSendParametersMessage(message.idInfo.sourceAddress, message.idInfo.isMulticast, parameterIDs);
    }

    void parseTMMessage(TPMessage &message) {
        uint8_t messageType = message.readUint8();
        if (ErrorHandler::assertInternal(messageType == TMPacket, ErrorHandler::UnknownMessageType)) {
            return;
        }

        Message telemetry;
    }

    void parseTCMessage(TPMessage &message) {
        uint8_t messageType = message.readUint8();
        if (ErrorHandler::assertInternal(messageType == TCPacket, ErrorHandler::UnknownMessageType)) {
            return;
        }

        Message telecommand;
    }
}
