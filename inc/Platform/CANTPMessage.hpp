#ifndef OBC_SOFTWARE_CANTPMESSAGE_H
#define OBC_SOFTWARE_CANTPMESSAGE_H

#include <cstdint>
#include "CANMessage.hpp"
#include "etl/String.hpp"
#include "etl/vector.h"
#include "Logger_Definitions.hpp"
#include "Services/EventReportService.hpp"

namespace CANTPMessage {
    /**
     * The ID information of a CAN-TP Message, as specified in DDJF_OBDH.
     */
    struct IdInfo {
        uint8_t sourceAddress;
        uint8_t destinationAddress;
        bool isMulticast;
    };

    /**
     * The available Event Report Types, for an Event Report CAN-TP Message.
     */
    enum EventReportType : uint8_t {
        Informative = 0x0, LowSeverity = 0x1, MediumSeverity = 0x2, HighSeverity = 0x3
    };

    /**
     * Decodes the ID of a CAN-TP Message.
     * @param canID The received ID.
     * @return A struct containing the ID information.
     */
    IdInfo decodeId(uint16_t canID);

    /**
     * Encodes the ID of a CAN-TP Message.
     * @param idInfo The ID information.
     * @return The encoded ID.
     */
    uint16_t encodeId(IdInfo idInfo);

    /**
     * Split a value into an array of bytes and insert it into vector.
     * @tparam T The type of the parameter.
     * @tparam N The maximum size of the vector.
     * @param value The value to be inserted.
     * @param vector The vector to insert the value into.
     */
    template<typename T, size_t N>
    inline void stuffIntoVector(T value, etl::vector<uint8_t, N> &vector) {
        for (auto i = sizeof(T) - 1; i >= 0; i--) {
            vector.push_back(value >> (i * 8));
        }
    }

    /**
     * Sends a Send Parameters CAN-TP Message as described in DDJF_OBDH.
     * @tparam T The type of the parameter.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param parameterIDs The IDs of the parameters to be sent.
     */
    template<typename T>
    void createSendParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                     const etl::vector<uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs);

    /**
     * Sends a Request Parameters CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param parameterIDs The IDs of the parameters to be requested.
     */
    void createRequestParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                        const etl::vector<uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs);

    /**
     * Sends a Request Parameters CAN-TP Message as described in DDJF_OBDH.
     * @tparam T The type of the argument.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param functionId The ID of the function to be called.
     * @param argumentIDs The IDs of the arguments to be sent.
     * @param argumentValues The values of the arguments to be sent.
     * */
    template<typename T>
    void createPerformFunctionMessage(uint8_t destinationAddress, bool isMulticast, uint64_t functionId,
                                      const etl::vector<uint8_t, CAN::TPMessageMaximumArguments> &argumentIDs,
                                      const etl::vector<T, CAN::TPMessageMaximumArguments> &argumentValues);

    /**
     * Sends a Log CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param log A LogEntry to be sent.
     */

    void createLogMessage(uint8_t destinationAddress, bool isMulticast, uint16_t logSize, const etl::string<LOGGER_MAX_MESSAGE_SIZE> &log);

    /**
     * Sends a Event Report CAN-TP Message as described in DDJF_OBDH.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param type The event report type.
     * @param eventID The ID of the event.
     * @param payload An array of the event data.
     */
    void createEventReportMessage(uint8_t destinationAddress, bool isMulticast, EventReportType type, uint16_t eventID,
                                  const etl::vector<uint8_t, CAN::TPMessageMaximumSize> &payload);

    /**
     * Creates an ECSS-E-ST-70-41C Services TM/TC packet to be sent. After creation the packet is split into CAN-TP
     * Protocol frames to be transmitted.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param message An ECSS Message.
     */
    void createPacketMessage(uint8_t destinationAddress, bool isMulticast, const Message &message);

    /**
     * Creates a CCSDS packet to be sent. After creation the packet is split into CAN-TP
     * Protocol frames to be transmitted.
     * @param destinationAddress The ID of the destination node.
     * @param isMulticast Whether the message is to be sent to a multicast group.
     * @param message An ECSS Message.
     */
    void createCCSDSPacketMessage(uint8_t destinationAddress, bool isMulticast, const Message &message);
};

#endif //OBC_SOFTWARE_CANTPMESSAGE_H
