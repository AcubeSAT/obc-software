#ifndef OBC_SOFTWARE_CANTPPROTOCOL_HPP
#define OBC_SOFTWARE_CANTPPROTOCOL_HPP

#include "CANMessage.hpp"
#include "CANApplicationLayer.hpp"
#include "CANTPMessage.hpp"
#include "etl/map.h"

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
    etl::map<uint8_t, etl::vector<uint8_t, CANTPMessageMapSize>, CANTPMessageMapSize> incomingMessages;

    /**
     * A queue holding the outgoing messages.
     */
    etl::queue<etl::vector<uint8_t, CANMessage::MaxDataLength>, CANTPMessageMapSize> outgoingCANTPMessages;

    /**
     * Sends a Send Parameters CAN-TP Message as described in DDJF_OBDH.
     * @tparam T The type of the parameter.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param parameterIDs The IDs of the parameters to be sent.
     */
    template<typename T>
    void createSendParametersCANTPMessage(uint8_t destinationAddress, bool isMulticast,
                                          const etl::vector<uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs);

    /**
     * Sends a Request Parameters CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param parameterIDs The IDs of the parameters to be requested.
     */
    void createRequestParametersCANTPMessage(uint8_t destinationAddress, bool isMulticast,
                                             const etl::vector<uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs);


    void createTMPackerCANTPMessage();

    void createTCPackerCANTPMessage();

    void createCCSDSPackerCANTPMessage();

    /**
     * Encodes a message according to the CAN-TP Protocol.
     * @param messagePayload one of the CAN-TP messages found in DDJF_OBDH
     */
    template<typename T>
    void encodeCANTPMessage(const etl::vector<T, CAN::TPMessageMaximumSize> &messagePayload);

    /**
     * Decodes a received CAN-TP Protocol message to extract the containing information.
     * @param incomingMessage
     */
    template<typename T>
    void decodeCANTPMessage(const etl::vector<T, CAN::TPMessageMaximumSize> &incomingMessage);


}

#endif //OBC_SOFTWARE_CANTPPROTOCOL_HPP
