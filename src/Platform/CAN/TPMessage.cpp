#include "CAN/TPMessage.hpp"

using IdInfo = CAN::TPMessage::IdInfo;

IdInfo CAN::TPMessage::decodeId(uint16_t canID) {
    idInfo.sourceAddress = (canID >> 4) & 0b111;
    idInfo.destinationAddress = (canID >> 1) & 0b111;
    idInfo.isMulticast = canID & 0b1;

    return idInfo;
}

uint16_t CAN::TPMessage::encodeId() {
    uint16_t id = 0b0111 << 7;

    id |= idInfo.sourceAddress << 4;
    id |= idInfo.destinationAddress << 1;
    id |= idInfo.isMulticast;

    return id;
}


