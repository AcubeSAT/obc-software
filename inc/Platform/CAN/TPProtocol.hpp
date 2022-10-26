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
     * The usable data length for a consecutive message.
     */
    static constexpr uint8_t UsableDataLength = CAN::Frame::MaxDataLength - 1;

    /**
     * Creates a TPMessage object from a single frame, and passes it over to the parse function.
     * @param message A received CAN::Frame.
     */
    void processSingleFrame(const CAN::Frame &message);

    /**
     * Receives a collection of messages from the Gatekeeper Task's incomingQueue, and processes them.
     */
    void processMultipleFrames();

    /**
     * Processes the stored messages received and acts on their content accordingly.
     * @param message the complete CAN-TP message.
     */
    void parseMessage(TPMessage &message);

    /**
     * Splits a CAN-TP Message into a collection of CAN frames according to the TP protocol and adds them to the CAN
     * Gatekeeper Task queue.
     * For more information about the CAN-TP Protocol check
     * https://piembsystech.com/can-tp-protocol/
     * @param message A CAN-TP message.
     */
    void createCANTPMessage(const TPMessage &message);
}
