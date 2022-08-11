#include "CANApplicationLayer.hpp"
#include "OBC_Definitions.hpp"
#include "PlatformParameters.hpp"
#include "Helpers/TimeGetter.hpp"

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
        uint64_t msOfDay = TimeGetter::getCurrentTimeCustomCUC().elapsed100msTicks; //@todo This doesn't reset every day, only since epoch.

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
//            incomingTPMessage.push(message);
        } else if (message.id == pingMessageId) {
            sendPongMessage();
        } else {
            switch (filterMessageID(message.id)) {
                case heartbeatMessageID:
//                    parseHeartbeatMessage();
                    break;
                case busSwitchoverMessageID:
//                    parseBusSwitchoverMessage();
                    break;
                case utcTimeMessageID:
//                    parseTimeMessage();
                    break;
                default:
                    break;
            }
        }
    }

    void
    parseTPMessage() { // @todo How should this function be called? Whenever a TP message header is found on parseMessage?
        message.empty();
//        incomingTPMessage.pop_into(message);

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

    void finalizeMessage(uint16_t id, const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload) {
        etl::array<uint8_t, CANMessage::MaxDataLength> data = {};

        uint8_t messageNumber = 0;
        uint8_t idx = 0;

        for (uint8_t character: messagePayload) {
            if (idx == 0) {
                data[idx] = messageNumber;
                idx++;
            }

            data[idx] = character;
            idx++;

            if (idx == CANMessage::MaxDataLength) {
                message.empty();
                message = {id, data};
                CANApplicationLayer::outgoingMessages.push(message);
                data.fill(0);
                idx = 0;
            }
        }
    }
}

