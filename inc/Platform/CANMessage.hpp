#ifndef OBC_SOFTWARE_CANMESSAGE_H
#define OBC_SOFTWARE_CANMESSAGE_H

#include <algorithm>
#include <cstdint>
#include "etl/vector.h"
#include "OBC_Definitions.hpp"

class CANMessage {
public:
    static constexpr uint8_t MaxDataLength = 8;
    uint16_t id;
    etl::vector<uint8_t, MaxDataLength> data;

    CANMessage() {};

    CANMessage(uint16_t id) : id(id) {};

    CANMessage(uint16_t id, const etl::vector<uint8_t, MaxDataLength> &_data) : id(id), data(_data) {};

    inline void empty() {
        id = 0;
        data.fill(0);
    }
};

#endif //OBC_SOFTWARE_CANMESSAGE_H
