#include "CANApplicationLayer.hpp"
#include "CANTPMessage.hpp"
#include "OBC_Definitions.hpp"
#include "ServicePool.hpp"

namespace CANTPMessage {
    IdInfo decodeId(uint16_t canID) {
        IdInfo id;

        id.sourceAddress = (canID >> 4) & 0b111;
        id.destinationAddress = (canID >> 1) & 0b111;
        id.isMulticast = canID & 0b1;

        return id;
    }

    uint16_t encodeId(IdInfo idInfo) {
        uint16_t id = 0b0111 << 7;

        id |= (idInfo.sourceAddress << 4);
        id |= (idInfo.destinationAddress << 1);
        id |= idInfo.isMulticast;

        return id;
    }

    template<typename T>
    void
    createSendParametersMessage(uint8_t destinationAddress, bool isMulticast, etl::vector<uint16_t, 10> parameterIDs) {
        uint16_t id = encodeId({CAN::NodeID, destinationAddress, isMulticast});
        uint16_t parameterCount = parameterIDs.size();

        etl::vector<uint8_t, 256> data = {0x01, static_cast<uint8_t>(parameterCount >> 8),
                                          static_cast<uint8_t>(parameterCount)};

        for (uint16_t parameterId: parameterIDs) {
            auto parameter = static_cast<Parameter<T> &>(Services.parameterManagement.getParameter(
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

    void createRequestParametersMessage(uint8_t destinationAddress, bool isMulticast,
                                        etl::vector<uint16_t, 10> parameterIDs) {
        uint16_t id = encodeId({0x1, destinationAddress, isMulticast});
        uint16_t parameterCount = parameterIDs.size();

        etl::vector<uint8_t, 256> data = {0x02, static_cast<uint8_t>(parameterCount >> 8),
                                          static_cast<uint8_t>(parameterCount)};

        for (auto parameter: parameterIDs) {
            data.push_back(parameter);
        }

        CANApplicationLayer::finalizeMessage(id, data);
    }

    template<typename T>
    void createPerformFunctionMessage(uint8_t destinationAddress, bool isMulticast, uint64_t functionId,
                                      etl::vector<uint8_t, 10> argumentIDs, etl::vector<T, 10> argumentValues) {
        uint16_t id = encodeId({CAN::NodeID, destinationAddress, isMulticast});

        auto argumentCount = static_cast<uint16_t>(argumentIDs.size());
        etl::vector<uint8_t, 256> data = {0x03};

        uint8_t functionIdSize = 6;
        while (functionIdSize > 0) {
            functionIdSize--;
            data.push_back(functionId >> (functionIdSize * 8));
        }

        uint8_t idx = 0;
        for (auto argumentValue: argumentValues) {
            data.push_back(argumentIDs.at(idx));

            for (auto value: stuffIntoVector(argumentValue)) {
                data.push_back(value);
            }
            idx++; //@todo This is not error handled, if the argumentValues.size() != argumentIDs.size() there is undefined behavior.
        }

        CANApplicationLayer::finalizeMessage(id, data);
    }

    void createLogMessage(uint8_t destinationAddress, bool isMulticast, etl::string<LOGGER_MAX_MESSAGE_SIZE> log) {
        uint16_t id = encodeId({CAN::NodeID, destinationAddress, isMulticast});

        etl::vector<uint8_t, 256> data = {0x40};

        for (auto character: log) {
            data.push_back(character);
        }

        CANApplicationLayer::finalizeMessage(id, data);
    }

    void createEventReportMessage(uint8_t destinationAddress, bool isMulticast, EventReportType type, uint16_t eventID,
                                  etl::array<uint8_t, 256> payload) {
        uint16_t id = encodeId({CAN::NodeID, destinationAddress, isMulticast});

        etl::vector<uint8_t, 256> data = {0x10, static_cast<unsigned char>(eventID >> 8),
                                          static_cast<unsigned char>(eventID)};

        for (auto point: payload) {
            data.push_back(point);
        }

        CANApplicationLayer::finalizeMessage(id, data);
    }


    template<typename T>
    etl::vector<uint8_t, 8> stuffIntoVector(T value) {
        auto size = sizeof(T);
        etl::vector<uint8_t, 8> vector;

        while (size > 0) {
            size--;
            vector.push_back(value >> (size * 8));
        }

        return vector;
    }
}
