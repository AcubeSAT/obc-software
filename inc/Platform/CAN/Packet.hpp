#ifndef OBC_SOFTWARE_CANMESSAGE_H
#define OBC_SOFTWARE_CANMESSAGE_H

#include "etl/vector.h"
#include "OBC_Definitions.hpp"

namespace CAN {
    class Packet {
    public:
        static constexpr uint8_t MaxDataLength = 8;
        uint16_t id = 0;
        etl::vector<uint8_t, MaxDataLength> data = {};

        Packet() = default;

        Packet(uint16_t id) : id(id) {};

        Packet(uint16_t id, const etl::vector<uint8_t, MaxDataLength> &data) : id(id), data(data) {};

        inline void empty() {
            id = 0;
            data.fill(0);
        }
    };
}

#endif //OBC_SOFTWARE_CANMESSAGE_H