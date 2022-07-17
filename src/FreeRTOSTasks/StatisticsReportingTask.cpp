#include "FreeRTOSTasks/StatisticsReportingTask.hpp"

void StatisticsReportingTask::execute() {
    auto &parameterStatistics = Services.parameterStatistics;
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true) {
        if (parameterStatistics.getPeriodicReportingStatus()) {
            Message request = Message(ParameterStatisticsService::ServiceType,
                                      ParameterStatisticsService::MessageType::ReportParameterStatistics,
                                      Message::PacketType::TC, ApplicationId);
            request.appendBoolean(false);
            MessageParser::execute(request);
        }
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(parameterStatistics.getReportingIntervalMs()));
    }
}
