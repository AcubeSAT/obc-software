#include "CANApplicationLayer.hpp"
#include "OBC_Definitions.hpp"
#include "PlatformParameters.hpp"

namespace CANApplicationLayer {
    CANMessage createPingMessage() {
        uint16_t id = CAN::nodeID;
        uint8_t data[CAN::dataLength] = {pingDataPacket};
        return {id, data};
    }

    CANMessage createPongMessage() {
        uint16_t id = CAN::nodeID;
        uint8_t data[CAN::dataLength] = {pongDataPacket};
        return {id, data};
    }

    CANMessage createHeartbeatMessage() {
        return CANMessage(getHeartbeatID(CAN::nodeID));
    }

    CANMessage createBusSwitchoverMessage() {
        uint16_t id = getBusSwitchoverID(CAN::nodeID);
        uint8_t data[CAN::dataLength] = {getBusToSwitchover()};
        return {id, data};
    }

    CANMessage createUTCTimeMessage() {
        uint32_t msOfDay; //@todo How do we get millisecond accuracy?

        uint16_t id = getTimeID(CAN::nodeID);
        uint8_t data[CAN::dataLength] = {0, 0, //@todo how do we get submillis of ms?
                                         static_cast<uint8_t>(msOfDay), static_cast<uint8_t>(msOfDay >> 8),
                                         static_cast<uint8_t>(msOfDay >> 16), static_cast<uint8_t>(msOfDay >> 24),
                                         0, PlatformParameters::onBoardDay.getValue()}; //@todo days parameter should not be uint8_t

        return {id, data};
    }

    void parseMessage(CANMessage message) {
        if (isTPMessage(message.id)) {
//            parseTPMessage(); @todo how to do this async?
        } else if (message.id > 0x700) {
//            @todo register heartbeat?
        } else if (message.id > 0x400) {
            CAN::currentBus = static_cast<CAN::BusID>(message.data[0]);
//            @todo write code to use the other CAN peripheral
        } else {
//            @todo UTC time message receipt
        }
    }

}

