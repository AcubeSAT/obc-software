#include "CANMessage.hpp"

void CANMessage::decodeTPMessage(const uint16_t canID) {
    uint8_t sourceAddress = (canID >> 4) & 0b111;

    uint8_t destinationAddress = (canID >> 1) & 0b111;

    bool isMulticast = canID & 0b1;
}