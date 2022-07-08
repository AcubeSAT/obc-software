#include "CANApplicationLayer.hpp"
#include "CANTPMessage.hpp"
#include "OBC_Definitions.hpp"
#include "ServicePool.hpp"

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

template<typename T>
void CANTPMessage::createSendParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                               etl::vector<uint16_t, 10> parameterIDs) {
    uint16_t id = encodeId({CAN::nodeID, destinationAddress, isMulticast});
    uint16_t parameterCount = parameterIDs.size();

    etl::vector<uint8_t, 256> data = {0x01, static_cast<uint8_t>(parameterCount >> 8),
                                      static_cast<uint8_t>(parameterCount)};

    for (uint16_t parameterId: parameterIDs) {
        auto parameter = static_cast<Parameter <T> &>(Services.parameterManagement.getParameter(
                parameterId)->get()).getValue();

        for (auto paramId: stuffIntoVector(parameterId)) {
            data.push_back(paramId);
        }

        for (auto param: stuffIntoVector(parameter)) { //@todo better name for this?
            data.push_back(param);
        }
    }

    CANApplicationLayer::finalizeMessage(id, data);
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
