#include "CANMessage.hpp"

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
