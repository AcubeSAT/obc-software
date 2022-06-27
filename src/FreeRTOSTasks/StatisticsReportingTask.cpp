#include "FreeRTOSTasks/StatisticsReportingTask.hpp"

void StatisticsReportingTask::execute() {
    auto &parameterStatistics = Services.parameterStatistics;
//    todo: while (parameterStatistics.periodicStatisticsReportingStatus) {}

    while (true) {
        Message request(ParameterStatisticsService::ServiceType,
                        ParameterStatisticsService::MessageType::ReportParameterStatistics, Message::TC, 1);
        MessageParser::execute(request);
        vTaskDelay(delayMs);
    }
}