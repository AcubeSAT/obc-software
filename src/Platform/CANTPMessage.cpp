#include "CANTPMessage.hpp"
#include "OBC_Definitions.hpp"

CANTPMessage::IdInfo CANTPMessage::decodeId(uint16_t canID) {
    IdInfo id;

    id.sourceAddress = (canID >> 4) & 0b111;
    id.destinationAddress = (canID >> 1) & 0b111;
    id.isMulticast = canID & 0b1;

    return id;
}

uint16_t CANTPMessage::encodeId(IdInfo idInfo) {
    uint16_t id = 0b0111 << 7;

    id |= (idInfo.sourceAddress << 4);
    id |= (idInfo.destinationAddress << 1);
    id |= idInfo.isMulticast;

    return id;
}

void CANTPMessage::createSendParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                               etl::array<uint16_t, 10> parameterIDs) {
    uint16_t id = encodeId({CAN::nodeID, destinationAddress, isMulticast});

    uint8_t parameterCount = parameterIDs.size();

    CANMessage message = {id};

    for (uint8_t idx = 0; idx < parameterCount; idx++) {
        uint16_t parameterId = parameterIDs.at(idx);
        //@todo how should I access the parameters by ID?

    }
}

void CANTPMessage::createRequestParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                                  etl::array<uint8_t, 10> parameterIDs) {
    uint16_t id = encodeId({CAN::nodeID, destinationAddress, isMulticast});

    uint8_t parameterCount = parameterIDs.size();

    for (uint8_t idx = 0; idx < parameterCount; idx++) {
        uint16_t parameterId = parameterIDs.at(idx);

    }

}

void CANTPMessage::createPerformFunctionMessage(uint8_t destinationAddress, bool isMulticast, uint64_t functionId,
                                                etl::array<uint8_t, 10> argumentIDs,
                                                etl::array<uint16_t, 10> argumentValues) {
    uint16_t id = encodeId({CAN::nodeID, destinationAddress, isMulticast});

    auto argumentCount = static_cast<uint16_t>(argumentIDs.size());


}
