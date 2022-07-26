#include "CANApplicationLayer.hpp"
#include "OBC_Definitions.hpp"
#include "PlatformParameters.hpp"

namespace CANApplicationLayer {
    static CANMessage message = {};

    void createPingMessage() {
        outgoingMessages.push({pingMessageId});
    }

    void createPongMessage() {
        outgoingMessages.push({pongMessageId});
    }

    void createHeartbeatMessage() {
        uint16_t id = getHeartbeatID(CAN::NodeID);
        outgoingMessages.push({id});
    }

    void createBusSwitchoverMessage() {
        uint16_t id = getBusSwitchoverID(CAN::NodeID);
        etl::array<uint8_t, CANMessage::MaxDataLength> data = {getBusToSwitchover()};

        outgoingMessages.push({id, data});
    }

    void createUTCTimeMessage() {
        uint32_t msOfDay; //@todo How do we get millisecond accuracy?

        uint16_t id = getTimeID(CAN::NodeID);
        etl::array<uint8_t, CANMessage::MaxDataLength> data = {0, 0, static_cast<uint8_t>(msOfDay),
                                                     static_cast<uint8_t>(msOfDay >> 8),
                                                     static_cast<uint8_t>(msOfDay >> 16),
                                                     static_cast<uint8_t>(msOfDay >> 24), 0,
                                                     PlatformParameters::onBoardDay.getValue()}; //@todo days parameter should not be uint8_t

        outgoingMessages.push({id, data});
    }

    void parseMessage() {
        message.empty();
        incomingMessages.pop_into(message);

        if (isTPMessage(message.id)) {
            incomingTPMessage.push(message);
        } else if (isHeartbeatMessage(message.id)) {
//            parseHeartbeatMessage(message);
        } else if (isSwitchoverMessage(message.id)) {
            currentBus = static_cast<BusID>(message.data[0]);
//            parseBusSwitchoverMessage(message);
        } else if (isUTCTimeMessage(message.id)) {
//            parseUTCTimeMessage(message);
        } else if (message.id == pingMessageId) {
            sendPongMessage();
        }
    }

    void
    parseTPMessage() { // @todo How should this function be called? Whenever a TP message header is found on parseMessage?
        message.empty();
        incomingTPMessage.pop_into(message);

        auto idInfo = CANTPMessage::decodeId(message.id);
        if ((idInfo.destinationAddress == CAN::NodeID) | idInfo.isMulticast) {
//            switch(message->data[0]){
//                case 0x01:
//                    parseSendParametersMessage();
//                    break;
//                case 0x02:
//                    parseRequestParametersMessage();
//                    break;
//                case 0x03:
//                    parsePerformFunctionMessage();
//                    break;
//                case 0x10:
//                    parseEventReportMessage();
//                    break;
//                case 0x20:
//                    parseTMPacketMessage();
//                    break;
//                case 0x21:
//                    parseTCPacketMessage();
//                    break;
//                case 0x22:
//                    parseCCSDSPacketMessage();
//                    break;
//                default: ;
//            };
        }
    }

    void finalizeMessage(uint16_t id, const etl::vector<uint8_t, 256> &messagePayload) {
        etl::array<uint8_t, CANMessage::MaxDataLength> data = {};

        for (uint8_t idx = 0; idx < messagePayload.size(); idx++) {
            data[idx % CANMessage::MaxDataLength] = messagePayload.at(idx);
            if (idx % CANMessage::MaxDataLength == CANMessage::MaxDataLength - 1) {
                message.empty();
                message = {id, data};
                CANApplicationLayer::outgoingMessages.push(message);
                data.fill(0);
            }
        }
    }

}

