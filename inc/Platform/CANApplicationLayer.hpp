#ifndef OBC_SOFTWARE_CANAPPLICATIONLAYER_H
#define OBC_SOFTWARE_CANAPPLICATIONLAYER_H

#include "CANMessage.hpp"
#include "CANTPMessage.hpp"
#include "etl/queue.h"

namespace CANApplicationLayer {
    /**
     * A queue that holds messages that are waiting to be sent via the CAN Bus.
     */
    inline etl::queue<CANMessage, CAN::MessageQueueSize> outgoingMessages;

    /**
     * A queue that holds messages that have been received via the CAN Bus, and are awaiting parsing.
     */
    inline etl::queue<CANMessage, CAN::MessageQueueSize> incomingMessages;

    /**
     * A queue that holds a collection of CAN Messages that compose a CAN TP Message.
     */
    inline etl::queue<CANMessage, CAN::TPMessageQueueSize> incomingCommsTPMessage;

    /**
     * A queue that holds a collection of CAN Messages that compose a CAN TP Message.
     */
    inline etl::queue<CANMessage, CAN::TPMessageQueueSize> incomingAdcsTPMessage;

    /**
     * A queue that holds a collection of CAN Messages that compose a CAN TP Message.
     */
    inline etl::queue<CANMessage, CAN::TPMessageQueueSize> incomingSuTPMessage;

    /**
     * Defines the Available CAN Buses to use.
     */
    enum BusID : uint8_t {
        MainBus = 0, RedundantBus = 1
    };

    /**
     * Adds a Ping message to the outgoing queue, according to DDJF_OBDH.
     */
    void sendPingMessage();

    /**
     * Adds a Pong message to the outgoing queue, to be sent in response to a Ping message, according to DDJF_OBDH.
     */
    void sendPongMessage();

    /**
     * Adds a Heartbeat message to the outgoing queue, to be called periodically, according to DDJF_OBDH.
     */
    void sendHeartbeatMessage();

    /**
     * Creates a CAN Bus switchover message to be sent whenever the FDIR responsible determines the bus quality
     * is not satisfactory, according to DDJF_OBDH.
     */
    void sendBusSwitchoverMessage();

    /**
     * Adds a message to the outgoing queue with the current UTC Time, according to DDJF_OBDH.
     */
    void sendUTCTimeMessage();

    /**
     * Retrus true if the message follows the heartbeat message id format, according to DDJF_OBDH.
     * @param id The id of the message to be checked.
     */
    inline bool isHeartbeatMessage(uint16_t id) {
        return (id & 0x700) == 0x700;
    }

    /**
     * Retrus true if the message follows the switchover message id format, according to DDJF_OBDH.
     * @param id The id of the message to be checked.
     */
    inline bool isSwitchoverMessage(uint16_t id) {
        return (id & 0x400) == 0x400;
    }

    /**
     * Retrus true if the message follows the UTC Time message id format, according to DDJF_OBDH.
     * @param id The id of the message to be checked.
     */
    inline bool isUTCTimeMessage(uint16_t id) {
        return (id & 0x200) == 0x200;
    }

    /**
     * Determines whether a message is following the CAN-TP Message protocol.
     * @param id The id of the message received via CAN
     * @return True if the message is part of a CAN-TP Message
     */
    inline bool isTPMessage(const uint16_t id) {
        return (id >> 7) == 0b0111;
    }

    /**
     * Value of a Ping data packet according to DDJF_OBDH.
     */
    const uint8_t pingMessageId = 0x30;

    /**
     * Value of a Pong data packet according to DDJF_OBDH.
     */
    const uint8_t pongMessageId = 0x31;

    /**
     * The current CAN Bus in use.
     */
    inline BusID currentBus = MainBus;

    /**
     * Value of a Heartbeat message ID according to DDJF_OBDH.
     * @param nodeID The ID of the current node.
     */
    inline uint16_t getHeartbeatID(uint16_t nodeID) {
        return nodeID + 0x700;
    }

    /**
     * Value of a Bus Switchover message ID according to DDJF_OBDH.
     * @param nodeID The ID of the current node.
     * @return The ID the Bus Switchover message should have.
     */
    inline uint16_t getBusSwitchoverID(uint16_t nodeID) {
        return nodeID + 0x400;
    }

    /**
     * Switches the active CAN Bus and returns the data packet to be sent in a Bus Switchover message.
     */
    inline BusID getBusToSwitchover() {
        if (currentBus == MainBus) {
            currentBus = RedundantBus;
        } else {
            currentBus = MainBus;
        }
        return currentBus;
    }

    /**
     * Value of a UTC Time message ID according to DDJF_OBDH.
     * @param nodeID The ID of the current node.
     */
    inline uint16_t getTimeID(uint16_t nodeID) {
        return nodeID + 0x200;
    }

    /**
     * Parses an incoming message and calls the appropriate functions for it's handling.
     * @param message A CANMessage object with an ID and a Data field.
     */
    void parseMessage(CANMessage message);

    /**
     * Splits a CAN-TP Message into a collection of CAN Messages and adds them to the outgoing queue.
     * @param id The ID that will be used for the messages.
     * @param messagePayload A vector containing the data part of the CAN-TP Message.
     */
    void finalizeMessage(uint16_t id, const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &messagePayload);
}

#endif //OBC_SOFTWARE_CANAPPLICATIONLAYER_H
