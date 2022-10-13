#pragma once

#include "etl/map.h"
#include "etl/vector.h"
#include "etl/String.hpp"
#include "Logger_Definitions.hpp"
#include "Message.hpp"
#include "OBC_Definitions.hpp"

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
        //TODO Signal logic to peripheral
        if (currentBus == MainBus) {
            currentBus = RedundantBus;
        } else {
            currentBus = MainBus;
        }
        return currentBus;
    }

    /**
     * The available Event Report Types, for an Event Report CAN-TP Message.
     */
    enum EventReportType : uint8_t {
        Informative = 0x0, LowSeverity = 0x1, MediumSeverity = 0x2, HighSeverity = 0x3
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
     * Sends a Send Parameters CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param parameterIDs The IDs of the parameters to be sent.
     */
    void createSendParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                     const etl::vector <uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs);

    /**
     * Sends a Request Parameters CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param parameterIDs The IDs of the parameters to be requested.
     */
    void createRequestParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                        const etl::vector <uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs);

    /**
     * Sends a Request Parameters CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param functionId The ID of the function to be called.
     * @param argumentIDs The IDs of the arguments to be sent.
     * @param argumentValues The values of the arguments to be sent.
     * */
    void createPerformFunctionMessage(uint8_t destinationAddress, bool isMulticast, uint64_t functionId,
                                      const etl::map <uint8_t, uint64_t, TPMessageMaximumArguments> &arguments);

    /**
     * Sends a Log CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param log A LogEntry to be sent.
     */
    void createLogMessage(uint8_t destinationAddress, bool isMulticast, uint16_t logSize,
                          const etl::string <LOGGER_MAX_MESSAGE_SIZE> &log);

    /**
     * Sends a Event Report CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param type The event report type.
     * @param eventID The ID of the event.
     * @param payload An array of the event data.
     */
    void createEventReportMessage(uint8_t destinationAddress, bool isMulticast, EventReportType type, uint16_t eventID,
                                  const etl::vector <uint8_t, CAN::TPMessageMaximumSize> &payload);

    /**
     * Creates an ECSS-E-ST-70-41C Services TM/TC packet to be sent.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param message An ECSS Message.
     */
    void createPacketMessage(uint8_t destinationAddress, bool isMulticast, const Message &message);

    /**
     * Creates a CCSDS packet to be sent.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param message An ECSS Message.
     */
    void createCCSDSPacketMessage(uint8_t destinationAddress, bool isMulticast, const Message &message);

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
