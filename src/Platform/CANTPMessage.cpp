#include "CANTPMessage.hpp"

CANTPMessage::idInfo CANTPMessage::decodeId(uint16_t canID) {
    idInfo id;

    id.sourceAddress = (canID >> 4) & 0b111;
    id.destinationAddress = (canID >> 1) & 0b111;
    id.isMulticast = canID & 0b1;

    return id;
}

