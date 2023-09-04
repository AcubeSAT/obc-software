#include "CAN/ApplicationLayer.hpp"
#include "CAN/Driver.hpp"
#include "CAN/TPMessage.hpp"
#include "CAN/TPProtocol.hpp"
#include "CANGatekeeperTask.hpp"

namespace CAN::Application {
    Driver::ActiveBus switchBus(Driver::ActiveBus newBus) {
        AcubeSATParameters::obcCANBUSActive.setValue(newBus);
        return AcubeSATParameters::obcCANBUSActive.getValue();
    }

    void sendPingMessage(NodeIDs destinationAddress, bool isMulticast) {
        TPMessage message = {{NodeID, destinationAddress, isMulticast}};

        message.appendUint8(Ping);

        CAN::TPProtocol::createCANTPMessage(message, false);
    }

    void sendPongMessage() {
        TPMessage message = {{NodeID, OBC, false}};

        message.appendUint8(Pong);

        CAN::TPProtocol::createCANTPMessage(message, true);
    }

    void sendHeartbeatMessage() {
        canGatekeeperTask->send({MessageIDs::Heartbeat + CAN::NodeID}, false);
    }

    void sendBusSwitchoverMessage() {
        Driver::ActiveBus newBus = Driver::Redundant;
        if (AcubeSATParameters::obcCANBUSActive.getValue() == Driver::Redundant) {
            newBus = Driver::Main;
        }

        etl::array<uint8_t, CAN::Frame::MaxDataLength> data = {switchBus(newBus)};

        canGatekeeperTask->send({MessageIDs::BusSwitchover + CAN::NodeID, data}, false);
    }

    void sendUTCTimeMessageWithElapsedTicks() {
        auto now = TimeGetter::getCurrentTimeDefaultCUC();

        const std::chrono::duration<uint64_t, std::milli> msOfDay = now.asDuration() % millisecondsPerDay;

        uint32_t ticksOfDay = static_cast<uint32_t>(msOfDay.count() / 100);

        UTCTimestamp utc = now.toUTCtimestamp();
        etl::array<uint8_t, CAN::Frame::MaxDataLength> data = {0, 0, static_cast<uint8_t>(ticksOfDay),
                                                               static_cast<uint8_t>(ticksOfDay >> 8),
                                                               static_cast<uint8_t>(ticksOfDay >> 16),
                                                               static_cast<uint8_t>(ticksOfDay >> 24),
                                                               static_cast<uint8_t>(utc.day),
                                                               static_cast<uint8_t>(utc.day >> 8)};

        canGatekeeperTask->send({MessageIDs::UTCTime + CAN::NodeID, data}, false);
    }

    void createSendParametersMessage(NodeIDs destinationAddress, bool isMulticast,
                                     const etl::array<uint16_t, TPMessageMaximumArguments> &parameterIDs, bool isISR) {
        TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::SendParameters);
        message.appendUint16(parameterIDs.size());
        for (auto parameterID: parameterIDs) {
            if (Services.parameterManagement.getParameter(parameterID)) {
                message.append(parameterID);
                Services.parameterManagement.getParameter(parameterID)->get().appendValueToMessage(message);
            }
            else if (parameterID == 0 ) {
                continue;
            }
            else {
                LOG_ERROR << "Requested parameter that doesn't exist! ID: " << parameterID;
            }
        }

        CAN::TPProtocol::createCANTPMessage(message, isISR);
    }

    void createRequestParametersMessage(NodeIDs destinationAddress, bool isMulticast,
                                        const etl::array<uint16_t, TPMessageMaximumArguments> &parameterIDs,
                                        bool isISR) {
        TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::RequestParameters);
        message.appendUint16(parameterIDs.size());

        if constexpr (Logger::isLogged(Logger::debug)) {
            String<128> logString = "Requesting parameters with ID: ";
            for (auto parameterID: parameterIDs) {
                if (parameterID == 0) {
                    continue;
                }
                etl::to_string(parameterID, logString, true);
                message.append(parameterID);
            }
            LOG_DEBUG << logString.c_str();
        } else {
            for (auto parameterID: parameterIDs) {
                message.append(parameterID);
            }
        }

        CAN::TPProtocol::createCANTPMessage(message, isISR);
    }

    void createPerformFunctionMessage(NodeIDs destinationAddress, bool isMulticast,
                                      const etl::string<FunctionIdSize> &functionId,
                                      const etl::map<uint8_t, uint64_t, TPMessageMaximumArguments> &arguments,
                                      bool isISR) {
        TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::PerformFunction);

        message.appendString(functionId);

        message.appendUint16(arguments.size());

        for (auto argument: arguments) {
            message.appendUint8(argument.first);
            message.appendUint64(argument.second);
        }

        CAN::TPProtocol::createCANTPMessage(message, isISR);
    }

    void createEventReportMessage(NodeIDs destinationAddress, bool isMulticast, EventReportType type, uint16_t eventID,
                                  const Message &eventData, bool isISR) {
        TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::EventReport);
        message.appendEnum8(type);
        message.appendUint16(eventID);
        message.appendMessage(eventData, eventData.dataSize);

        CAN::TPProtocol::createCANTPMessage(message, isISR);
    }

    void createPacketMessage(NodeIDs destinationAddress, bool isMulticast, const etl::string<128> &incomingMessage, Message::PacketType packetType, bool isISR) {
        TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        if (packetType == Message::TM) {
            message.appendUint8(MessageIDs::TMPacket);
        } else {
            message.appendUint8(MessageIDs::TCPacket);
        }

        message.appendString(incomingMessage);

        CAN::TPProtocol::createCANTPMessage(message, isISR);
    }

    void
    createCCSDSPacketMessage(NodeIDs destinationAddress, bool isMulticast, const Message &incomingMessage, bool isISR) {
        TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        auto ccsdsMessage = MessageParser::compose(incomingMessage);

        message.appendUint8(MessageIDs::CCSDSPacket);
        message.appendString(ccsdsMessage);

        CAN::TPProtocol::createCANTPMessage(message, isISR);
    }

    void createLogMessage(NodeIDs destinationAddress, bool isMulticast, const String<ECSSMaxMessageSize> &log,
                          bool isISR) {
        TPMessage message = {{CAN::NodeID, destinationAddress, isMulticast}};

        message.appendUint8(MessageIDs::LogMessage);
        message.appendString(log);

        CAN::TPProtocol::createCANTPMessage(message, isISR);
    }

    void parseMessage(const CAN::Frame &message) {
        uint32_t id = filterMessageID(message.id);
        if (id == Heartbeat) {
//            registerHeartbeat();
        } else if (id == BusSwitchover) {
            switchBus(static_cast<Driver::ActiveBus>(message.data[0]));
        } else if (id == UTCTime) {
//            registerUTCTime();
        }
    }

    void parseSendParametersMessage(TPMessage &message) {
        uint8_t messageType = message.readUint8();
        if (not ErrorHandler::assertInternal(messageType == SendParameters, ErrorHandler::UnknownMessageType)) {
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
        if (not ErrorHandler::assertInternal(messageType == RequestParameters, ErrorHandler::UnknownMessageType)) {
            return;
        }
        uint16_t parameterCount = message.readUint16();
        etl::array<uint16_t, TPMessageMaximumArguments> parameterIDs = {};

        for (uint16_t idx = 0; idx < parameterCount; idx++) {
            parameterIDs[idx] = message.readUint16();
        }

        createSendParametersMessage(message.idInfo.sourceAddress, message.idInfo.isMulticast, parameterIDs, true);
    }

    void parseTMMessage(TPMessage &message) {
        uint8_t messageType = message.readUint8();
        if (not ErrorHandler::assertInternal(messageType == TMPacket, ErrorHandler::UnknownMessageType)) {
            return;
        }

        String<ECSSMaxMessageSize> logString = message.data + 1;

        LOG_DEBUG << logString.c_str();
    }

    void parseTCMessage(TPMessage &message) {
        uint8_t messageType = message.readUint8();
        if (not ErrorHandler::assertInternal(messageType == TCPacket, ErrorHandler::UnknownMessageType)) {
            return;
        }

        Message teleCommand = MessageParser::parseECSSTC(message.data + 1);

        MessageParser::execute(teleCommand);
    }
}
