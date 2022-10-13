#pragma once

#include <cstdint>
#include "Message.hpp"

namespace CAN {
    class TPMessage : public Message {
    public:
        /**
         * The ID information of a CAN-TP Message, as specified in DDJF_OBDH.
         */
        struct IdInfo {
            uint8_t sourceAddress;
            uint8_t destinationAddress;
            bool isMulticast;
        };

        IdInfo idInfo = {};

        TPMessage() = default;
    };
}
