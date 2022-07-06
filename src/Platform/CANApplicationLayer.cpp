#include "CANApplicationLayer.hpp"
#include "OBC_Definitions.hpp"
#include "PlatformParameters.hpp"

namespace CANApplicationLayer {
    void createPingMessage() {
        uint16_t id = CAN::nodeID; //@todo ping pong messages should have the original node ID?
        uint8_t data[CAN::dataLength] = {pingDataPacket};

        outgoingMessages.push({id, data});
    }

    void createPongMessage() {
        uint16_t id = CAN::nodeID;
        uint8_t data[CAN::dataLength] = {pongDataPacket};
        outgoingMessages.push({id, data});
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
                                         static_cast<uint8_t>(msOfDay >> 16), static_cast<uint8_t>(msOfDay >> 24),
                                         0, PlatformParameters::onBoardDay.getValue()}; //@todo days parameter should not be uint8_t

        outgoingMessages.push({id, data});
    }

    void parseMessage() {
        CANMessage* message;
        incomingMessages.pop_into(*message);

        if (isTPMessage(message->id)) {
            incomingTPMessage.push(*message);
        } else if (message->id > 0x700) {
//            @todo register heartbeat?
        } else if (message->id > 0x400) {
            CAN::currentBus = static_cast<CAN::BusID>(message->data[0]);
//            @todo write code to use the other CAN peripheral
        } else {
//            @todo UTC time message receipt
        }
    }

}

