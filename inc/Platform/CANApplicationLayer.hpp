#ifndef OBC_SOFTWARE_CANAPPLICATIONLAYER_H
#define OBC_SOFTWARE_CANAPPLICATIONLAYER_H

#include "CANMessage.hpp"
#include "CANTPMessage.hpp"

namespace CANApplicationLayer {

    /**
     * Function that creates a Ping message to be sent, according to the CDR.
     * @return A CANMessage object with an ID and a Data field ready to be sent via CAN Bus.
     */
    CANMessage createPingMessage();

    /**
     * Function that creates a Pong message to be sent in response to a Ping message, according to the CDR.
     * @return A CANMessage object with an ID and a Data field ready to be sent via CAN Bus.
     */
    CANMessage createPongMessage();

    /**
     * Function that creates a Heartbeat message to be sent periodically, according to the CDR.
     * @return A CANMessage object with an ID and a Data field ready to be sent via CAN Bus.
     */
    CANMessage createHeartbeatMessage();

    /**
     * Function that creates a Heartbeat message to be sent whenever the FDIR responsible determines the bus quality
     * is not satisfactory, according to the CDR.
     * @return A CANMessage object with an ID and a Data field ready to be sent via CAN Bus.
     */
    CANMessage createBusSwitchoverMessage();

    /**
     * Function that creates a message with the current UTC Time, according to the CDR.
     * @return A CANMessage object with an ID and a Data field ready to be sent via CAN Bus.
     */
    CANMessage createUTCTimeMessage();

    /**
     * Function that determines whether a message is following the CAN-TP Message protocol.
     * @param id The id of the message received via CAN
     * @return Whether the message is a CAN-TP Message
     */
    inline bool isTPMessage(const uint16_t id) {
        return ((id >> 7) == 0b0111);
    }

    /**
     * Value of a Ping data packet according to the CDR.
     */
    const uint8_t pingDataPacket = 0x30;

    /**
     * Value of a Pong data packet according to the CDR.
     */
    const uint8_t pongDataPacket = 0x31;

    /**
     * Value of a Heartbeat message ID according to the CDR.
     */
    inline uint16_t getHeartbeatID(const uint16_t nodeID) {
        return nodeID + 0x700;
    }

    inline uint16_t getBusSwitchoverID(const uint16_t nodeID) {
        return nodeID + 0x400;
    }

    /**
     * Function that determines the bus that will be used after a CAN Bus switchover event.
     * @return The bus to be used after the switchover.
     */
    inline CAN::BusID getBusToSwitchover() {
        if (CAN::currentBus == CAN::MainBus) {
            return CAN::RedundantBus;
        }
        return CAN::MainBus;
    }

    /**
     * Value of a UTC Time message ID according to the CDR.
     */
    inline uint16_t getTimeID(const uint16_t nodeID) {
        return nodeID + 0x200;
    }

    /**
     * Function that parses an incoming message and calls the appropriate functions for it's handling.
     * @param message A CANMessage object with an ID and a Data field.
     */
    void parseMessage(CANMessage message);
}

#endif //OBC_SOFTWARE_CANAPPLICATIONLAYER_H
