#ifndef OBC_SOFTWARE_CANAPPLICATIONLAYER_H
#define OBC_SOFTWARE_CANAPPLICATIONLAYER_H

#include "CANMessage.hpp"
#include "CANTPMessage.hpp"
#include "etl/queue.h"

namespace CANApplicationLayer {

    /**
     * A queue that holds messages that are waiting to be sent via the CAN Bus.
     */
    inline etl::queue<CANMessage, 64> outgoingMessages;

    /**
     * A queue that holds messages that have been received via the CAN Bus, and are awaiting parsing.
     */
    inline etl::queue<CANMessage, 64> incomingMessages;

    /**
     * A queue that holds a collection of CAN Messages that compose a CAN TP Message.
     */
    inline etl::queue<CANMessage, 64> incomingTPMessage;

    /**
     * Function that adds a Ping message to the outgoing queue, according to the CDR.
     */
    void sendPingMessage();

    /**
     * Function that adds a Pong message to the outgoing queue, to be sent in response to a Ping message, according to the CDR.
     */
    void sendPongMessage();

    /**
     * Function that adds a Heartbeat message to the outgoing queue, to be called periodically, according to the CDR.
     */
    void sendHeartbeatMessage();

    /**
     * Function that creates a Heartbeat message to be sent whenever the FDIR responsible determines the bus quality
     * is not satisfactory, according to the CDR.
     */
    void sendBusSwitchoverMessage();

    /**
     * Function that adds a message to the outgoing queue with the current UTC Time, according to the CDR.
     */
    void sendUTCTimeMessage();

    /**
     * Function that determines whether a message is following the CAN-TP Message protocol.
     * @param id The id of the message received via CAN
     * @return True if the message is part of a CAN-TP Message
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
     * @param nodeID The ID of the current node.
     */
    inline uint16_t getHeartbeatID(const uint16_t nodeID) {
        return nodeID + 0x700;
    }

    /**
     * Value of a Bus Switchover message ID according to the CDR.
     * @param nodeID The ID of the current node.
     * @return The ID the Bus Switchover message should have.
     */
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
     * @param nodeID The ID of the current node.
     */
    inline uint16_t getTimeID(const uint16_t nodeID) {
        return nodeID + 0x200;
    }

    /**
     * Function that parses an incoming message and calls the appropriate functions for it's handling.
     * @param message A CANMessage object with an ID and a Data field.
     */
    void parseMessage(CANMessage message);

    /**
     * Function that splits a CAN-TP Message into a collection of CAN Messages and adds them to the outgoing queue.
     * @param id The ID that will be used for the messages.
     * @param messagePayload A vector containing the data part of the CAN-TP Message.
     */
    void finalizeMessage(uint16_t id, etl::vector<uint8_t, 256> messagePayload);

}

#endif //OBC_SOFTWARE_CANAPPLICATIONLAYER_H
