#include "RequestParamADCSTask.hpp"

void RequestParamADCSTask::execute() {

    etl::array<uint16_t, parametersCount> paramIDs{};

    size_t paramCount = 0;

    for (uint16_t id = 11; id <= 13; id++) {
        paramIDs.insert_at(paramCount , id);
        paramCount++;
    }

    for (uint16_t id = 1000; id <= 1045; id++) {
        paramIDs.insert_at(paramCount , id);
        paramCount++;
    }

    for (uint16_t id = 1046; id <= 1070; id += 2) {
        paramIDs.insert_at(paramCount , id);
        paramCount++;
    }

    for (uint16_t id = 1071; id <= 1228; id++) {
        paramIDs.insert_at(paramCount , id);
        paramCount++;
    }

    while (true) {

        for (size_t i = 0; i < paramIDs.size(); i += BATCH_SIZE) {
            etl::array<uint16_t, 10> arguments{};

            size_t count = std::min(BATCH_SIZE, paramIDs.size() - i);
            for (size_t j = 0; j < count; j++) {
                arguments.insert_at(j , paramIDs[i + j]);
            }

            CAN::Application::createRequestParametersMessage(
                CAN::NodeIDs::ADCS,
                false,
                arguments,
                false
            );

            vTaskDelay(pdMS_TO_TICKS(20));
        }
        vTaskDelay(pdMS_TO_TICKS(DelayMs));
    }
}
