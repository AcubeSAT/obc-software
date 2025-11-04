#include "RequestParamADCSTask.hpp"

void RequestParamADCSTask::execute() {

    while (true) {

        etl::array<uint16_t, 225> paramIDs;

        size_t paramCount = 0;

        for (uint16_t id = 11; id <= 13; id++) {
            paramIDs[paramCount++] = id;
        }

        for (uint16_t id = 1000; id <= 1045; id++) {
            paramIDs[paramCount++] = id;
        }

        for (uint16_t id = 1046; id <= 1070; id += 2) {
            paramIDs[paramCount++] = id;
        }

        for (uint16_t id = 1071; id <= 1228; id++) {
            paramIDs[paramCount++] = id;
        }

        constexpr size_t BATCH_SIZE = 10;

        for (size_t i = 0; i < paramIDs.size(); i += BATCH_SIZE) {
            etl::array<uint16_t, 10> arguments;

            size_t batchSize = etl::min(BATCH_SIZE, paramCount - i);

            for (size_t j = 0; j < batchSize; j++) {
                arguments[j] = paramIDs[i + j];
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
