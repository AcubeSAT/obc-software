#ifndef OBC_SOFTWARE_CANMESSAGE_H
#define OBC_SOFTWARE_CANMESSAGE_H

#include "etl/vector.h"
#include "OBC_Definitions.hpp"

namespace CAN {
    class Frame {
    public:
        static constexpr uint8_t MaxDataLength = 64;
        uint32_t id = 0;
        etl::vector<uint8_t, MaxDataLength> data;

        Frame() = default;

        Frame(uint32_t id) : id(id) {};

        Frame(uint32_t id, const etl::vector<uint8_t, MaxDataLength> &data) : id(id), data(data) {};

        inline void empty() {
            id = 0;
            data.fill(0);
        }
    };
}

#endif //OBC_SOFTWARE_CANMESSAGE_H
