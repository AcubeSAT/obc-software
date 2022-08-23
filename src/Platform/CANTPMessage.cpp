#include "CANApplicationLayer.hpp"
#include "CANTPMessage.hpp"
#include "OBC_Definitions.hpp"
#include "ServicePool.hpp"

using CAN::TPMessageMaximumSize;
using CAN::TPMessageMaximumArguments;

namespace CANTPMessage {
    IdInfo decodeId(const uint16_t CanID) {
        IdInfo id;

        id.sourceAddress = (CanID >> 4) & 0b111;
        id.destinationAddress = (CanID >> 1) & 0b111;
        id.isMulticast = CanID & 0b1;

        return id;
    }

    uint16_t encodeId(IdInfo idInfo) {
        uint16_t id = 0b0111 << 7;

        id |= idInfo.sourceAddress << 4;
        id |= idInfo.destinationAddress << 1;
        id |= idInfo.isMulticast;

        return id;
    }

    template<typename T>
    void createSendParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                     const etl::vector<uint16_t, TPMessageMaximumArguments> &parameterIDs) {
        uint16_t id = encodeId({CAN::NodeID, destinationAddress, isMulticast});
        uint16_t parameterCount = parameterIDs.size();

        etl::vector<uint8_t, TPMessageMaximumSize> data = {0x01, static_cast<uint8_t>(parameterCount >> 8),
                                                           static_cast<uint8_t>(parameterCount)};

        for (uint16_t parameterId: parameterIDs) {
            auto parameter = static_cast<Parameter<T> &>(Services.parameterManagement.getParameter(
                    parameterId)->get()).getValue();

            stuffIntoVector(parameterId, data);
            stuffIntoVector(parameter, data);
        }

        CANApplicationLayer::finalizeMessage(id, data);
    }

    void createRequestParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                        const etl::vector<uint16_t, TPMessageMaximumArguments> &parameterIDs) {
        uint16_t id = encodeId({0x1, destinationAddress, isMulticast});
        uint16_t parameterCount = parameterIDs.size();

        etl::vector<uint8_t, TPMessageMaximumSize> data = {0x02, static_cast<uint8_t>(parameterCount >> 8),
                                                           static_cast<uint8_t>(parameterCount)};

        for (auto parameterID: parameterIDs) {
            stuffIntoVector(parameterID, data);
        }

        CANApplicationLayer::finalizeMessage(id, data);
    }

    template<typename T>
    void createPerformFunctionMessage(uint8_t destinationAddress, bool isMulticast, uint64_t functionId,
                                      const etl::vector<uint8_t, TPMessageMaximumArguments> &argumentIDs,
                                      const etl::vector<T, TPMessageMaximumArguments> &argumentValues) {
        uint16_t id = encodeId({CAN::NodeID, destinationAddress, isMulticast});

        auto argumentCount = static_cast<uint16_t>(argumentIDs.size());
        etl::vector<uint8_t, TPMessageMaximumSize> data = {0x03};

        uint8_t functionIdSize = 6;
        while (functionIdSize > 0) {
            functionIdSize--;
            data.push_back(functionId >> (functionIdSize * 8));
        }

        uint8_t idx = 0;
        for (auto argumentValue: argumentValues) {
            data.push_back(argumentIDs.at(idx));
            stuffIntoVector(argumentValue, data);

            idx++; //@todo This is not error handled, if the argumentValues.size() != argumentIDs.size() there is undefined behavior.
        }

        CANApplicationLayer::finalizeMessage(id, data);
    }

    void
    createLogMessage(uint8_t destinationAddress, bool isMulticast, const etl::string<LOGGER_MAX_MESSAGE_SIZE> &log) {
        uint16_t id = encodeId({CAN::NodeID, destinationAddress, isMulticast});

        etl::vector<uint8_t, TPMessageMaximumSize> data = {0x40};

        std::copy(log.begin(), log.end(), data.end());

        CANApplicationLayer::finalizeMessage(id, data);
    }

    void createEventReportMessage(uint8_t destinationAddress, bool isMulticast, EventReportType type, uint16_t eventID,
                                  const etl::array<uint8_t, TPMessageMaximumSize> &payload) {
        uint16_t id = encodeId({CAN::NodeID, destinationAddress, isMulticast});

        etl::vector<uint8_t, TPMessageMaximumSize> data = {0x10, type, static_cast<unsigned char>(eventID >> 8),
                                                           static_cast<unsigned char>(eventID)};

        for (auto point: payload) {
            data.push_back(point);
        }

        CANApplicationLayer::finalizeMessage(id, data);
    }
}
