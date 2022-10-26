#include "CAN/ApplicationLayer.hpp"
#include "CAN/TPMessage.hpp"
#include "CAN/TPProtocol.hpp"
#include "CANGatekeeperTask.hpp"

namespace CAN::Application {
    void sendPingMessage(uint8_t destinationAddress, bool isMulticast) {
        TPMessage message;

        message.idInfo = {NodeID, destinationAddress, isMulticast};
        message.appendUint8(Ping);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void sendPongMessage() {
        TPMessage message;

        message.idInfo = {NodeID, OBC, false};
        message.appendUint8(Pong);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void sendHeartbeatMessage() {
        canGatekeeperTask->send({MessageIDs::Heartbeat + CAN::NodeID});
    }

    void sendBusSwitchoverMessage() {
        etl::array<uint8_t, CAN::Frame::MaxDataLength> data = {toggleBusSwitchover()};

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
        CAN::TPMessage message = {};
        message.idInfo = {CAN::NodeID, destinationAddress, isMulticast};

        message.appendUint8(MessageIDs::SendParameters);
        message.appendUint16(parameterIDs.size());
        for (auto parameterID: parameterIDs) {
            if (Services.parameterManagement.getParameter(parameterID)) {
                message.appendUint16(parameterID);
                Services.parameterManagement.getParameter(parameterID)->get().appendValueToMessage(message);
            } else {
                LOG_ERROR << "Requested parameter that doesn't exist! ID: " << parameterID;
            }
        }

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createRequestParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                        const etl::vector<uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs) {
        CAN::TPMessage message = {};
        message.idInfo = {CAN::NodeID, destinationAddress, isMulticast};

        message.appendUint8(MessageIDs::RequestParameters);
        message.appendUint16(parameterIDs.size());
        for (auto parameterID: parameterIDs) {
            message.appendUint16(parameterID);
        }

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createPerformFunctionMessage(uint8_t destinationAddress, bool isMulticast, uint64_t functionId,
                                      const etl::map<uint8_t, uint64_t, TPMessageMaximumArguments> &arguments) {
        CAN::TPMessage message = {};
        message.idInfo = {CAN::NodeID, destinationAddress, isMulticast};

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
        CAN::TPMessage message = {};
        message.idInfo = {CAN::NodeID, destinationAddress, isMulticast};

        message.appendUint8(MessageIDs::EventReport);
        message.appendEnum8(type);
        message.appendUint16(eventID);
        message.appendMessage(eventData, eventData.dataSize);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createPacketMessage(uint8_t destinationAddress, bool isMulticast, const Message &incomingMessage) {
        CAN::TPMessage message = {};
        message.idInfo = {CAN::NodeID, destinationAddress, isMulticast};

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
        CAN::TPMessage message = {};
        message.idInfo = {CAN::NodeID, destinationAddress, isMulticast};

        auto ccsdsMessage = MessageParser::compose(incomingMessage);

        message.appendUint8(MessageIDs::CCSDSPacket);
        message.appendString(ccsdsMessage);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void createLogMessage(uint8_t destinationAddress, bool isMulticast, const String<LOGGER_MAX_MESSAGE_SIZE> &log) {
        CAN::TPMessage message = {};
        message.idInfo = {CAN::NodeID, destinationAddress, isMulticast};

        message.appendUint8(MessageIDs::LogMessage);
        message.appendString(log);

        CAN::TPProtocol::createCANTPMessage(message);
    }

    void parseMessage(const CAN::Frame &message) {
        uint32_t id = filterMessageID(message.id);
        if (id == 0x700) {
//            registerHeartbeat();
        } else if (id == 0x400) {
            toggleBusSwitchover(static_cast<ActiveBus>(message.data[0]));
        } else if (id == 0x200) {
//            registerUTCTime();
        }
    }

    void parseSendParametersMessage(TPMessage &message) {
        uint16_t parameterCount = message.readUint16();

        for (uint16_t idx = 0; idx < parameterCount; idx++) {
            uint16_t parameterID = message.readUint16();
            if (Services.parameterManagement.parameterExists(parameterID)) {
                Services.parameterManagement.getParameter(parameterID)->get().setValueFromMessage(message);
            }
        }
    }

    void parseRequestParametersMessage(TPMessage &message) {
        uint16_t parameterCount = message.readUint16();
        etl::vector<uint16_t, TPMessageMaximumArguments> parameterIDs;

        for (uint16_t idx = 0; idx < parameterCount; idx++) {
            parameterIDs.push_back(message.readUint16());
        }

        createSendParametersMessage(message.idInfo.sourceAddress, message.idInfo.isMulticast, parameterIDs);
    }
}
