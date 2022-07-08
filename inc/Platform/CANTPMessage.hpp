#ifndef OBC_SOFTWARE_CANTPMESSAGE_H
#define OBC_SOFTWARE_CANTPMESSAGE_H

#include <cstdint>
#include "CANMessage.hpp"
#include "etl/String.hpp"
#include "etl/vector.h"
#include "Logger_Definitions.hpp"

class CANTPMessage : CANMessage {
private:
    struct IdInfo {
        uint8_t sourceAddress;
        uint8_t destinationAddress;
        bool isMulticast;
    };

    IdInfo decodeId(uint16_t canID);

    uint16_t encodeId(IdInfo idInfo);

    template<typename T>
    void
    createSendParametersMessage(uint8_t destinationAddress, bool isMulticast, etl::vector<uint16_t, 10> parameterIDs);

    void
    createRequestParametersMessage(uint8_t destinationAddress, bool isMulticast, etl::array<uint8_t, 10> parameterIDs);

    void createPerformFunctionMessage(uint8_t destinationAddress, bool isMulticast, uint64_t functionId,
                                      etl::array<uint8_t, 10> argumentIDs, etl::array<uint16_t, 10> argumentValues);
};

#endif //OBC_SOFTWARE_CANTPMESSAGE_H
