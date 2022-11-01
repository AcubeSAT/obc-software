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

        /**
         * Whether the message is a response to an another CAN Message. If true then we need to use sendFromISR instead
         * of send in the Gatekeeper Task.
         */
        bool isResponse = false;

        TPMessage() = default;

        TPMessage(IdInfo _idInfo) : idInfo(_idInfo) {};

        TPMessage(IdInfo _idInfo, bool _isResponse) : idInfo(_idInfo), isResponse(_isResponse) {};

        /**
         * Decodes the ID of a CAN-TP Message, and sets the idInfo field of the current message.
         * @param canID The received ID.
         * @return A struct containing the ID information.
         */
        [[maybe_unused]] inline IdInfo decodeId(uint32_t canID) {
            idInfo.sourceAddress = (canID >> 4) & 0b111;
            idInfo.destinationAddress = (canID >> 1) & 0b111;
            idInfo.isMulticast = canID & 0b1;

            return idInfo;
        }

        /**
         * Encodes the ID of a CAN-TP Message, using the already set idInfo member.
         * @return The encoded ID.
         */
        inline uint32_t encodeId() const {
            uint16_t id = 0b0111 << 7;

            id |= idInfo.sourceAddress << 4;
            id |= idInfo.destinationAddress << 1;
            id |= idInfo.isMulticast;

            return id;
        }
    };
}
