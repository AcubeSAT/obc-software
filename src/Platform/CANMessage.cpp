#include "CANMessage.hpp"

using MessageData = CANMessage::MessageData;

MessageData CANMessage::createPingMessage(){
    MessageData messageData;

    messageData.id = CAN::nodeID;
    messageData.data[0] = pingDataPacket;

    return messageData;
}

MessageData CANMessage::createPongMessage(){
    MessageData messageData;

    messageData.id = CAN::nodeID;
    messageData.data[0] = pongDataPacket;

    return messageData;
}

MessageData CANMessage::createHeartbeatMessage(){
    MessageData messageData;

    messageData.id = getHeartbeatID(CAN::nodeID);

    return messageData;
}

MessageData CANMessage::createBusSwitchoverMessage(){
    MessageData messageData;

    messageData.id = getBusSwitchoverID(CAN::nodeID);
    messageData.data[0] = getBusToSwitchover();

    return messageData;
}
