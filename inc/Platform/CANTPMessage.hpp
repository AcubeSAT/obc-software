#ifndef OBC_SOFTWARE_CANTPMESSAGE_H
#define OBC_SOFTWARE_CANTPMESSAGE_H

#include <cstdint>
#include "CANMessage.hpp"
#include "etl/String.hpp"
#include "etl/vector.h"
#include "Logger_Definitions.hpp"
#include "Services/EventReportService.hpp"

namespace CANTPMessage {
    struct IdInfo {
        uint8_t sourceAddress;
        uint8_t destinationAddress;
        bool isMulticast;
    };

    enum EventReportType : uint8_t {
        Informative = 0x0, LowSeverity = 0x1, MediumSeverity = 0x2, HighSeverity = 0x3
    };

    IdInfo decodeId(uint16_t canID);

    uint16_t encodeId(IdInfo idInfo);

    template<typename T, size_t N>
    inline void stuffIntoVector(T value, etl::vector<uint8_t, N> &vector) {
        for (auto i = sizeof(T) - 1; i >= 0; i--) {
            vector.push_back(value >> (i * 8));
        }
    }

    template<typename T>
    void createSendParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                     const etl::vector<uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs);

    void createRequestParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                        const etl::vector<uint16_t, CAN::TPMessageMaximumArguments> &parameterIDs);

    template<typename T>
    void createPerformFunctionMessage(uint8_t destinationAddress, bool isMulticast, uint64_t functionId,
                                      const etl::vector<uint8_t, CAN::TPMessageMaximumArguments> &argumentIDs,
                                      const etl::vector<T, CAN::TPMessageMaximumArguments> &argumentValues);

    void
    createLogMessage(uint8_t destinationAddress, bool isMulticast, const etl::string<LOGGER_MAX_MESSAGE_SIZE> &log);

    void createEventReportMessage(uint8_t destinationAddress, bool isMulticast, EventReportType type, uint16_t eventID,
                                  const etl::array<uint8_t, CAN::TPMessageMaximumSize> &payload);
};

#endif //OBC_SOFTWARE_CANTPMESSAGE_H
