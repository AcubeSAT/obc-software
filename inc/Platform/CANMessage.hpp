#ifndef OBC_SOFTWARE_CANMESSAGE_H
#define OBC_SOFTWARE_CANMESSAGE_H

#include <algorithm>
#include <cstdint>
#include "etl/array.h"
#include "OBC_Definitions.hpp"

class CANMessage {
public:
    uint16_t id;
    etl::array<uint8_t, CAN::DataLength> data;

    CANMessage() {};

    CANMessage(uint16_t id) : id(id) {};

    CANMessage(uint16_t id, etl::array<uint8_t, CAN::DataLength> _data) : id(id), data(_data) {};

    inline void empty(){
        id = 0;
        data.fill(0);
    }
};

#endif //OBC_SOFTWARE_CANMESSAGE_H
