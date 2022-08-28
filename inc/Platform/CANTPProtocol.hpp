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

    uint8_t const CANTPMessageMapSize = 64;

    etl::map<uint8_t, CANMessage, CANTPMessageMapSize> outgoingMessages;

    etl::map<uint8_t, CANMessage, CANTPMessageMapSize> incomingMessages;

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
    void encodeCANTPMessage(const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload);

    /**
     * Decodes a received CAN-TP Protocol message to extract the containing information.
     * @param incomingMessage
     */
    void decodeCANTPMessage(const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &incomingMessage);


}

#endif //OBC_SOFTWARE_CANTPPROTOCOL_HPP
