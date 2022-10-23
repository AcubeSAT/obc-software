#pragma once

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
            bool isMulticast: 1;
        };

        IdInfo idInfo = {};

        TPMessage() = default;

        /**
         * Decodes the ID of a CAN-TP Message, and sets the idInfo field of the current message.
         * @param canID The received ID.
         * @return A struct containing the ID information.
         */
        [[maybe_unused]] IdInfo decodeId(uint16_t canID);

        /**
         * Encodes the ID of a CAN-TP Message, using the already set idInfo member.
         * @return The encoded ID.
         */
        uint16_t encodeId() const;
    };
}
