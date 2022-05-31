#include "CANApplication.hpp"

void CANApplication::decodeTPMessage(const uint8_t data[8]) {
    uint8_t sourceAddress = (data[0] >> 1) & 0b111;

    uint8_t destinationAddress = ((data[0] & 0b1) << 2) | (data[1] >> 6);

    bool isMulticast = (data[1] >> 5) & 0b1;
}