#ifndef OBC_SOFTWARE_CANTPPROTOCOL_HPP
#define OBC_SOFTWARE_CANTPPROTOCOL_HPP

#include "CANApplicationLayer.hpp"
#include "CANMessage.hpp"
#include "etl/map.h"
#include "etl/queue.h"
#include "etl/vector.h"

namespace CANTPProtocol {

    /**
     * The size of the map holding the received messages.
     */
    constexpr uint16_t CANTPStructureSize = 256;

    /**
     * How many bytes of information are contained in a consecutive frame
     */
    uint8_t const BytesPerFrame = 5;

    /**
     * A pointer indicating the information starting point.
     */
    uint8_t const BytesStartingPoint = 2;

    /**
     * A structure holding the data length codes of the received CAN-TP messages.
     */
    uint8_t randomleksi;

    typedef etl::vector<uint8_t, CANTPStructureSize> CANTPMessage;

    static CANTPMessage canTPMessage = {};
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
     * Splits a CAN-TP Message into a collection of CAN-TP frames and adds them to the outgoing CANApplicationLayer queue.
     * @param id the CAN Message encoded id
     * @param messageMapKey a map key to save the message correctly to the message map when received
     * @param messagePayload one of the CAN-TP messages found in DDJF_OBDH
     */
    void createCANTPMessage(uint16_t id, const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload);

    /**
     * Receives CAN-TP Protocol message frame, processes its bytes for information and then saves it to the incoming
     * messages map.
     * @param messageFrame the received CAN-TP frame
     */
    void saveCANTPMessage(const CANMessage &messageFrame);

    /**
     * Extracts information(Map key, data length code) from the first frame
     * @param messageFrame the received CAN-TP frame
     * @return the map key and the message data length code
     */
    uint16_t extractDataLengthCode(const CANMessage &messageFrame);

    /**
     * Processes the stored messages received and acts on their content accordingly.
     * @param message the complete CAN-TP message.
     */
    void parseMessage(const CANTPMessage &message);
}

#endif //OBC_SOFTWARE_CANTPPROTOCOL_HPP
