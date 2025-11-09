#include "RequestParamADCSTask.hpp"

void RequestParamADCSTask::execute() {

    etl::vector<uint16_t, ParametersCount> paramIDs{};

    for (uint16_t id = 11; id <= 13; id++) {
        paramIDs.push_back(id);
    }

    for (uint16_t id = 1000; id <= 1045; id++) {
        paramIDs.push_back(id);
    }

    for (uint16_t id = 1046; id <= 1070; id += 2) {
        paramIDs.push_back(id);
    }

    for (uint16_t id = 1071; id <= 1228; id++) {
        paramIDs.push_back(id);
    }

    while (true) {

        for (size_t i = 0; i < paramIDs.size(); i += BatchSize) {
            etl::array<uint16_t, 10> arguments{};

            size_t count = etl::min(BatchSize, paramIDs.size() - i);
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
