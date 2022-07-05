#ifndef OBC_SOFTWARE_CANMESSAGE_H
#define OBC_SOFTWARE_CANMESSAGE_H

#include <cstdint>
#include <cstring>
#include "OBC_Definitions.hpp"

class CANMessage {
public:
    uint16_t id;
    uint8_t data[CAN::dataLength]{};

    explicit CANMessage(uint16_t id) : id(id) {};

    CANMessage(uint16_t id, uint8_t incomingData[CAN::dataLength]) : id(id) {
        memcpy(data, incomingData, CAN::dataLength);
    };
};

#endif //OBC_SOFTWARE_CANMESSAGE_H
