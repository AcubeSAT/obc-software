#ifndef OBC_SOFTWARE_CANTPPROTOCOL_HPP
#define OBC_SOFTWARE_CANTPPROTOCOL_HPP

#include "CANMessage.hpp"
#include "etl/map.h"
#include "etl/vector.h"
#include "etl/queue.h"

namespace CANTPProtocol {

    /**
     * Types of CAN-TP procotol frames.
     */
    enum CANTPFrames : uint8_t {
        SingleFrame = 0x00, FirstFrame = 0x01, ConsecutiveFrame = 0x02, FlowControlFrame = 0x03
    };

    /**
     * The size of the map holding the received messages.
     */
    uint8_t const CANTPMessageMapSize = 64;

    /**
     * The byte payload length of the First Frame.
     */
    inline const uint8_t FirstFramePayloadLength = 6;

    /**
     * The byte payload length of a Consecutive Frame
     */
    inline const uint8_t ConsecutiveFramePayloadLength = 7;

    /**
     * A structure holding received CAN-TP messages.
     */
//    etl::map<uint8_t, etl::vector<uint8_t, CANTPMessageMapSize>, CANTPMessageMapSize> incomingMessages;

    /**
     * A queue holding the outgoing messages.
     */
    etl::queue<CANMessage, CANTPMessageMapSize> CANTPMessages;


    void createTMPacketMessage();

    void createTCPacketMessage();

    void createCCSDSPacketMessage();

    /**
     * Encodes a message according to the CAN-TP Protocol.
     * @param messagePayload one of the CAN-TP messages found in DDJF_OBDH
     */
    void createCANTPMessage(uint8_t messageID, const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload);

    /**
     * Decodes a received CAN-TP Protocol message to extract the containing information.
     * @param incomingMessage
     */
    void decodeCANTPMessage(const etl::vector<uint8_t , CAN::TPMessageMaximumSize> &incomingMessage);


}

#endif //OBC_SOFTWARE_CANTPPROTOCOL_HPP
