#pragma once

#include "Driver.hpp"
#include "etl/map.h"
#include "etl/array.h"
#include "etl/String.hpp"
#include "Frame.hpp"
#include "Logger_Definitions.hpp"
#include "Message.hpp"
#include "Peripheral_Definitions.hpp"
#include "AcubeSATParameters.hpp"
#include "TPMessage.hpp"
#include "Definitions.hpp"

namespace CAN::Application {
    /**
     * Entity that maps subsystem names to strings for use in logging functions.
     */
    inline etl::map<NodeIDs, String <LogSource::MaximumLettersInSubsystemName>, LogSource::NumberOfLogSources> nodeIdToString = {
            {OBC,         "OBC"},
            {COMMS,       "COMMS"},
            {ADCS,        "ADCS"},
            {SU,          "SU"},
            {ExternalMCU, "External"}
    };

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

    /**
     * Toggles the active CAN Bus.
     * @param bus A default argument that uses the currentBus member variable if a value is not provided.
     * @return The ID of the bus to be switched to.
     */
    CAN::Driver::ActiveBus switchBus(CAN::Driver::ActiveBus newBus);

    /**
     * The available Event Report Types, for an Event Report CAN-TP Message.
     */
    enum EventReportType : uint8_t {
        Informative = 0x0, LowSeverity = 0x1, MediumSeverity = 0x2, HighSeverity = 0x3
    };

    /**
     * The size in bytes for the function ID required in Perform Function Messages.
     */
    static constexpr uint8_t FunctionIdSize = 6;

    /**
     * Milliseconds per day.
     */
    inline constexpr uint64_t millisecondsPerDay = 24 * 60 * 60 * 1000;


    /**
     * Removes the ID of the sender in an incoming CAN Message.
     * @param id The ID to be filtered.
     * @return The filtered ID.
     */
    inline uint32_t filterMessageID(uint32_t id) {
        return id & 0x700;
    }

    /**
     * Adds a Ping message to the outgoing queue, according to DDJF_OBDH.
     */
    void sendPingMessage(NodeIDs destinationAddress, bool isMulticast);

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
    void createSendParametersMessage(NodeIDs destinationAddress, bool isMulticast,
                                     const etl::array<uint16_t, TPMessageMaximumArguments> &parameterIDs,
                                     bool isISR);

    /**
     * Sends a Request Parameters CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param parameterIDs The IDs of the parameters to be requested.
     */
    void createRequestParametersMessage(NodeIDs destinationAddress, bool isMulticast,
                                        const etl::array<uint16_t, TPMessageMaximumArguments> &parameterIDs,
                                        bool isISR);

    /**
     * Sends a Request Parameters CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param functionId The ID of the function to be called.
     * @param arguments The map containing the arguments of the function to be called.
     * @TODO This map should be changed to accommodate arguments of differing types, not just uint64_t
     * */
    void createPerformFunctionMessage(NodeIDs destinationAddress, bool isMulticast,
                                      const etl::string<FunctionIdSize> &functionId,
                                      const etl::map<uint8_t, uint64_t, TPMessageMaximumArguments> &arguments,
                                      bool isISR);

    /**
     * Sends a Event Report CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param type The event report type.
     * @param eventID The ID of the event.
     * @param payload An array of the event data.
     */
    void createEventReportMessage(NodeIDs destinationAddress, bool isMulticast, EventReportType type, uint16_t eventID,
                                  const Message &eventData, bool isISR);

    /**
     * Creates an ECSS-E-ST-70-41C Services TM/TC packet to be sent. After creation the packet is split into CAN-TP
     * Protocol frames to be transmitted.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param message An ECSS Message.
     */
    void createPacketMessage(NodeIDs destinationAddress, bool isMulticast, const etl::string<128> &incomingMessage, Message::PacketType packetType, bool isISR);

    /**
     * Creates a CCSDS packet to be sent. After creation the packet is split into CAN-TP
     * Protocol frames to be transmitted.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param message An ECSS Message.
     */
    void
    createCCSDSPacketMessage(NodeIDs destinationAddress, bool isMulticast, const Message &message, bool isISR);

    /**
     * Sends a Log CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param log A LogEntry to be sent.
     */
    void createLogMessage(NodeIDs destinationAddress, bool isMulticast, const String<ECSSMaxMessageSize> &log,
                          bool isISR);

    /**
     * Parses an incoming non-TP frame for the appropriate response.
     * @param message The incoming CAN::Frame.
     */
    void parseMessage(const CAN::Frame &message);

    /**
     * Parses an incoming Send Parameters Message and updates the according parameters
     * @param message An incoming TPMessage
     */
    void parseSendParametersMessage(TPMessage &message);

    /**
     * Parses an incoming Request Parameters Message and sends the according parameters back, if they exist.
     * @param message An incoming TPMessage
     */
    void parseRequestParametersMessage(TPMessage &message);

    /**
     * Parses an incoming TM Packet and logs it.
     * @param message An incoming TMPacket
     */
    void parseTMMessage(TPMessage &message);

    /**
     * Parses an incoming TC Packet and executes it.
     * @param message An incoming TCPacket
     */
    void parseTCMessage(TPMessage &message);
}
