#pragma once

#include <cstdint>

namespace CAN::Application {
    /**
     * CAN-TP message IDs, as specified in DDJF_OBDH.
     */
    enum MessageIDs : uint16_t {
        SendParameters = 0x01,
        RequestParameters = 0x02,
        PerformFunction = 0x03,
        EventReport = 0x10,
        TMPacket = 0x20,
        TCPacket = 0x21,
        CCSDSPacket = 0x022,
        Ping = 0x30,
        Pong = 0x31,
        LogMessage = 0x40,
        UTCTime = 0x200,
        BusSwitchover = 0x400,
        Heartbeat = 0x700
    };

    enum ActiveBus : uint8_t {
        MainBus = 0x0,
        RedundantBus = 0x1
    };

    ActiveBus currentBus = MainBus;

    inline uint8_t toggleBusSwitchover() {
        if (currentBus == MainBus) {
            currentBus = RedundantBus;
        } else {
            currentBus = MainBus;
        }
        return currentBus;
    }

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
     * Determines whether a message is following the CAN-TP Message protocol.
     * @param id The Id of the message received via CAN
     * @return True if the message is part of a CAN-TP Message
     */
    inline bool isTPMessage(uint16_t id) {
        return (id >> 7) == 0b0111;
    }

    /**
     * Removes the id of the sender in an incoming CAN Message.
     * @param id The ID to be filtered.
     * @return The filtered ID.
     */
    inline uint16_t filterMessageID(uint16_t id) {
        return id & 0x700;
    }

}
