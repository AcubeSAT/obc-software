#include "CANApplicationLayer.hpp"
#include "OBC_Definitions.hpp"
#include "PlatformParameters.hpp"

namespace CANApplicationLayer {
    void createPingMessage() {
        uint16_t id = pingMessageId;
        outgoingMessages.push({id});
    }

    void createPongMessage() {
        uint16_t id = pongMessageId;
        outgoingMessages.push({id});
    }

    void createHeartbeatMessage() {
        outgoingMessages.push({getHeartbeatID(CAN::nodeID)});
    }

    void createBusSwitchoverMessage() {
        uint16_t id = getBusSwitchoverID(CAN::nodeID);
        uint8_t data[CAN::dataLength] = {getBusToSwitchover()};
        outgoingMessages.push({id, data});
    }

    void createUTCTimeMessage() {
        uint32_t msOfDay; //@todo How do we get millisecond accuracy?

        uint16_t id = getTimeID(CAN::nodeID);
        uint8_t data[CAN::dataLength] = {0, 0, //@todo how do we get submillis of ms?
                                         static_cast<uint8_t>(msOfDay), static_cast<uint8_t>(msOfDay >> 8),
                                         static_cast<uint8_t>(msOfDay >> 16), static_cast<uint8_t>(msOfDay >> 24), 0,
                                         PlatformParameters::onBoardDay.getValue()}; //@todo days parameter should not be uint8_t

        outgoingMessages.push({id, data});
    }

    void parseMessage() {
        CANMessage *message;
        incomingMessages.pop_into(*message);

        if (isTPMessage(message->id)) {
            incomingTPMessage.push(*message);
        } else if (message->id > 0x700) {
//            @todo register heartbeat?
        } else if (message->id > 0x400) {
            CAN::currentBus = static_cast<CAN::BusID>(message->data[0]);
//            @todo write code to use the other CAN peripheral
        } else if (message->id > 0x200) {
//            @todo UTC time message receipt
        } else if (message->id == pingMessageId){
            sendPongMessage();
        }
    }

    void
    parseTPMessage() { // @todo How should this function be called? Whenever a TP message header is found on parseMessage?

    }

    void finalizeMessage(uint16_t id, etl::vector<uint8_t, 256> messagePayload) {
        auto remainingBytes = messagePayload.size();
        uint8_t data[CAN::dataLength];
        uint8_t idx = 0;

        while (remainingBytes > 0) {
            data[idx % CAN::dataLength] = messagePayload.at(idx);
            if (idx % CAN::dataLength == CAN::dataLength - 1) {
                CANMessage message = {id, data};
                CANApplicationLayer::outgoingMessages.push(message);
                memset(data, 0, sizeof(data));
            }
            idx++;
            remainingBytes--;
        }
    }

}

