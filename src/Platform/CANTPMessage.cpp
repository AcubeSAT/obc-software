#include "CANTPMessage.hpp"

using MessageData = CANMessage::MessageData;

CANTPMessage::IdInfo CANTPMessage::decodeId(uint16_t canID) {
    IdInfo id;

    id.sourceAddress = (canID >> 4) & 0b111;
    id.destinationAddress = (canID >> 1) & 0b111;
    id.isMulticast = canID & 0b1;

    return id;
}

uint16_t CANTPMessage::encodeId(IdInfo idInfo){
    uint16_t id = 0b0111 << 7;

    id |= (idInfo.sourceAddress << 4);
    id |= (idInfo.destinationAddress << 1);
    id |= idInfo.isMulticast;

    return id;
}


}

