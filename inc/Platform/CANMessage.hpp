#ifndef OBC_SOFTWARE_CANMESSAGE_H
#define OBC_SOFTWARE_CANMESSAGE_H

#include <algorithm>
#include <cstdint>
#include "OBC_Definitions.hpp"

class CANMessage {
public:
    uint16_t id;
    uint8_t data[CAN::dataLength]{};

    CANMessage(uint16_t id) : id(id) {};

    CANMessage(uint16_t id, uint8_t _data[CAN::dataLength]) : id(id) {
        std::copy(_data, _data + CAN::dataLength, data);
    };
};

#endif //OBC_SOFTWARE_CANMESSAGE_H
