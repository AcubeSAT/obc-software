#include "FreeRTOSTasks/StatisticsReportingTask.hpp"

void StatisticsReportingTask::execute() {
    auto &parameterStatistics = Services.parameterStatistics;
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true) {
        if (parameterStatistics.getPeriodicReportingStatus()) {
            parameterStatistics.reportParameterStatistics(false);
        }
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(parameterStatistics.getReportingIntervalMs()));
    }
}
