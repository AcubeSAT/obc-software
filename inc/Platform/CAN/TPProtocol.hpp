#pragma once

#include "CAN/ApplicationLayer.hpp"
#include "CAN/Frame.hpp"
#include "CAN/TPMessage.hpp"

namespace CAN::TPProtocol {
    /**
     * Types of CAN-TP protocol frames.
     */
    enum Frame : uint8_t {
        Single = 0x00, First = 0x01, Consecutive = 0x02, FlowControl = 0x03, Final = 0x04
    };

    /**
     * How many bytes of information are contained in a consecutive frame
     */
    static constexpr uint8_t BytesInConsecutiveFrame = 6;

    /**
     * A pointer indicating the information starting point.
     */
    static constexpr uint8_t BytesStartingPoint = 2;

    /**
     * A structure holding the data length codes of the received CAN-TP messages.
     * TODO This doesn't make sense being a vector of size 1.
     */
    inline etl::vector<uint16_t, 1> dataLengthCodes;

    /**
     * Receives CAN-TP Protocol message frame, processes its bytes for information and then saves it to the incoming
     * messages map.
     * @param messageFrame the received CAN-TP frame
     */
    void saveCANTPMessage(const CAN::Frame &messageFrame);

    /**
     * Extracts information(Map key, data length code) from the first frame
     * @param messageFrame the received CAN-TP Frame
     * @return the map key and the message data length code
     */
    inline uint16_t extractDataLengthCode(const CAN::Frame &messageFrame) {
        uint8_t dataLengthCodeLSB = messageFrame.data[0] << 4;
        uint8_t dataLengthCodeMSB = messageFrame.data[1];

        return (static_cast<uint16_t>(dataLengthCodeMSB) << 8) | dataLengthCodeLSB;
    }

    /**
     * Processes the stored messages received and acts on their content accordingly.
     * @param message the complete CAN-TP message.
     */
    void parseMessage(const TPMessage &message);

    /**
     * Splits a CAN-TP Message into a collection of CAN frames according to the TP protocol and adds them to the CAN
     * Gatekeeper Task queue.
     * For more information about the CAN-TP Protocol check
     * https://piembsystech.com/can-tp-protocol/
     * @param message A CAN-TP message.
     */
    void createCANTPMessage(const TPMessage &message);
}
