#ifndef OBC_SOFTWARE_CANTPPROTOCOL_HPP
#define OBC_SOFTWARE_CANTPPROTOCOL_HPP

#include "CANMessage.hpp"
#include "etl/map.h"
#include "etl/vector.h"
#include "etl/queue.h"
#include "CANApplicationLayer.hpp"

namespace CANTPProtocol {
    /**
     * The size of the map holding the received messages.
     */
    uint8_t const CANTPStructureSize = 64;

    /**
     * How many bytes of information are contained in a consecutive frame
     */
    uint8_t const bytesPerFrame = 4;

    /**
     * A pointer indicating the information starting point.
     */
    uint8_t const bytesStartingPoint = 2;

    typedef etl::vector<uint8_t, CANTPStructureSize> CANTPMessage;

    /**
     * Types of CAN-TP procotol frames.
     */
    enum Frame : uint8_t {
        Single = 0x00, First = 0x01, Consecutive = 0x02, FlowControl = 0x03
    };

    /**
     * CAN-TP message IDs, as specified in DDJF_OBDH.
     */
    enum Message : uint8_t {
        SendParameters = 0x01,
        RequestParameters = 0x02,
        PerformFunction = 0x03,
        EventReport = 0x04,
        TMPacket = 0x20,
        TCPacket = 0x21,
        CCSDSPacket = 0x022,
        Ping = 0x30,
        Pong = 0x31,
        LogMessage = 0x40
    };


    /**
     * A structure holding received CAN-TP messages.
     */
    inline static etl::map<uint8_t, CANTPMessage, CANTPStructureSize> incomingMessages;

    /**
     * A structure holding the data length codes of the received CAN-TP messages.
     */
    inline static etl::array<uint8_t, CANTPStructureSize> dataLengthCodes;

    /**
     * Splits a CAN-TP Message into a collection of CAN-TP frames and adds them to the outgoing CANApplicationLayer queue.
     * @param id the CAN Message encoded id
     * @param messageMapKey a map key to save the message correctly to the message map when received
     * @param messagePayload one of the CAN-TP messages found in DDJF_OBDH
     */
    void createCANTPMessage(uint16_t id, uint8_t messageMapKey,
                            const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload);

    /**
     * Receives CAN-TP Protocol message frame and saves it to the map.
     * @param messageFrame the received CAN-TP frame
     */
    void saveCANTPMessage(const CANMessage &messageFrame);

    /**
     * Extracts information(Map key, data length code) from the first frame
     * @param messageFrame the received CAN-TP frame
     * @return the map key and the message data length code
     */
    etl::vector<uint8_t, 3> extractMessageInformation(const CANMessage &messageFrame);

    /**
     * Extracts information from the CAN-TP first frame and sends back information about the current machine state.
     * @param firstFrame the first frame of a CAN-TP message
     */
    void sendFlowControlFrame(const CANMessage firstFrame);

    /**
     * When a message is done being received, it is then parsed future processing.
     * @param message the complete CAN-TP message.
     */
    void parseMessage(const CANTPMessage message);
}

#endif //OBC_SOFTWARE_CANTPPROTOCOL_HPP
