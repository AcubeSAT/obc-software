#pragma once

#include "etl/array.h"
#include "Peripheral_Definitions.hpp"

namespace CAN {
    /**
     * A CAN::Frame is a single message that is going to be sent over the CAN Bus. It could be part of collection of
     * CAN::Frames composing a CAN::TPMessage, a Single Frame TP Message, or a non-TP Message.
     *
     * It consists of an ID which specifies the message's function, as in DDJF_OBDH + an etl::array that contains the
     * message payload. A CAN::Frame is merely a carrier of information and has no functionality.
     */
    class Frame {
    public:
        /**
         * The maximum data length that is currently configured in the peripheral.
         */
        static constexpr uint8_t MaxDataLength = 64;

        /**
         * The right aligned ID of the message to be sent. Since the protocol doesn't make use of extended IDs,
         * they should be at most 11 bits long.
         *
         * @note The ID here must match one of the IDs found in DDJF_OBDH.
         */
        uint32_t id = 0;

        /**
         * A array containing the message payload.
         *
         * @note Users should use data.push_back() instead of data[i] while adding items to avoid errors caused by
         * copying the array to the gatekeeper queue.
         */
        etl::array<uint8_t, MaxDataLength> data = {};

        Frame() = default;

        Frame(uint32_t id) : id(id) {};

        Frame(uint32_t id, const etl::array<uint8_t, MaxDataLength> &data) : id(id), data(data) {};

        /**
         * Zeroes out the current frame. Use this if you're using a single static object in a recurring function.
         */
        inline void empty() {
            id = 0;
            data.fill(0);
        }
    };
}
