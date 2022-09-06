#ifndef OBC_SOFTWARE_CANTPPROTOCOL_HPP
#define OBC_SOFTWARE_CANTPPROTOCOL_HPP

#include "CANMessage.hpp"
#include "etl/map.h"
#include "etl/vector.h"
#include "etl/queue.h"
#include "CANApplicationLayer.hpp"

namespace CANTPProtocol {

    /**
     * Types of CAN-TP procotol frames.
     */
    enum CANTPFrames : uint8_t {
        Single = 0x00, First = 0x01, Consecutive = 0x02, FlowControl = 0x03
    };

    /**
     * The size of the map holding the received messages.
     */
    uint8_t const CANTPMessageMapSize = 64;


    /**
     * A structure holding received CAN-TP messages.
     */
    static etl::map<uint8_t, etl::vector<uint8_t, CANTPMessageMapSize>, CANTPMessageMapSize> incomingMessages;

    /**
     * Splits a CAN-TP Message into a collection of CAN-TP frames and adds them to the outgoing CANApplicationLayer queue.
     * @param id the CAN Message encoded id
     * @param messageMapKey a map key to save the message correctly to the message map when received
     * @param messagePayload one of the CAN-TP messages found in DDJF_OBDH
     */
    void createCANTPMessage(uint16_t id, uint8_t messageMapKey,
                            const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload);

    /**
     * Decodes a received CAN-TP Protocol message to extract the containing information.
     * @param incomingMessage the received message split into CAN-TP frames
     */
    void parseCANTPMessage(const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &incomingMessage);

    /**
     * Extracts information from the CAN-TP first frame and sends back information about the
     * @param firstFrame
     */
    void sendFlowControlFrame(CANMessage firstFrame);
}

#endif //OBC_SOFTWARE_CANTPPROTOCOL_HPP
