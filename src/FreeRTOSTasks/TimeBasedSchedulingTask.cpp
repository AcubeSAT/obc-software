#include "FreeRTOSTasks/TimeBasedSchedulingTask.hpp"

void TimeBasedSchedulingTask::execute() {
    auto &timeBasedScheduling = Services.timeBasedScheduling;

    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true) {
        Time::CustomCUC_t now = TimeGetter::getCurrentTimeCustomCUC();
        auto nextActivityExecutionCUCTime = timeBasedScheduling.executeScheduledActivity(now);
        TickType_t nextActivityExecutionTime = (nextActivityExecutionCUCTime - now).getMs();
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextActivityExecutionTime));
    }
}
