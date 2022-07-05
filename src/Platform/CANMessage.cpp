#include "CANMessage.hpp"
#include "PlatformParameters.hpp"

using MessageData = CANMessage::MessageData;

MessageData CANMessage::createPingMessage() {
    return {CAN::nodeID, pingDataPacket};
}

MessageData CANMessage::createPongMessage() {
    return {CAN::nodeID, pongDataPacket};
}

MessageData CANMessage::createHeartbeatMessage() {
    return {getHeartbeatID(CAN::nodeID)};
}

MessageData CANMessage::createBusSwitchoverMessage() {
    return {getBusSwitchoverID(CAN::nodeID), getBusToSwitchover()};
}

MessageData CANMessage::createUTCTimeMessage() {
    uint32_t msOfDay;

    return {getTimeID(CAN::nodeID),
            0, 0, //@todo how do we get submillis of ms?
            static_cast<uint8_t>(msOfDay), static_cast<uint8_t>(msOfDay >> 8),
            static_cast<uint8_t>(msOfDay >> 16), static_cast<uint8_t>(msOfDay >> 24), //@todo what clock gives us millisecond accuracy?
            0, PlatformParameters::onBoardDay.getValue()}; //@todo days parameter should not be uint8_t
}
