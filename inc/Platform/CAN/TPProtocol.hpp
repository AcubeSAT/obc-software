#pragma once

#include "CAN/ApplicationLayer.hpp"
#include "CAN/Frame.hpp"
#include "CAN/TPMessage.hpp"

namespace CAN::TPProtocol {
    /**
     * Types of CAN-TP protocol frames.
     */
    enum Frame : uint8_t {
        Single = 0x00, First = 0x01, Consecutive = 0x02, Final = 0x03
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
     * @param isISR Whether the function is called from an Interrupt Service Routine. The function is simply passed to
     * canGatekeeperTask->send().
     *
     * @note For the consecutive frame fill loop idx + 1 is used since the first byte of each frame is already filled,
     * however idx only reaches a maximum value of 62 which makes the position in the consecutiveFrame array valid.
     * The message.data[] part reaches the maximum index of 62 for the first frame, continues from 63 up to 125 etc.
     */
    void createCANTPMessage(const TPMessage &message, bool isISR);
}
