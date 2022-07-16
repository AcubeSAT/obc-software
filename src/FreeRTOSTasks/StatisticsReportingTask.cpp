#include "FreeRTOSTasks/StatisticsReportingTask.hpp"

void StatisticsReportingTask::execute() {
    auto &parameterStatistics = Services.parameterStatistics;
    uint32_t nextCollection = 0;
    uint32_t timeBeforeDelay = 0;
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true) {
        if (parameterStatistics.getPeriodicReportingStatus()) {
            Message request = Message(ParameterStatisticsService::ServiceType,
                                      ParameterStatisticsService::MessageType::ReportParameterStatistics,
                                      Message::PacketType::TC, 1);
            request.appendBoolean(false);
            MessageParser::execute(request);
        }
        vTaskDelay(pdMS_TO_TICKS(parameterStatistics.getReportingIntervalMs()));
//        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextCollection))
    }
}
