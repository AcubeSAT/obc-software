#include "CAN/TPMessage.hpp"

using IdInfo = CAN::TPMessage::IdInfo;

IdInfo CAN::TPMessage::decodeId(uint32_t canID) {
    idInfo.sourceAddress = (canID >> 4) & 0b111;
    idInfo.destinationAddress = (canID >> 1) & 0b111;
    idInfo.isMulticast = canID & 0b1;

    return idInfo;
}

uint32_t CAN::TPMessage::encodeId() const {
    uint16_t id = 0b0111 << 7;

    id |= idInfo.sourceAddress << 4;
    id |= idInfo.destinationAddress << 1;
    id |= idInfo.isMulticast;

    return id;
}


