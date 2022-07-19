#include "FreeRTOSTasks/TimeBasedSchedulingTask.hpp"

void TimeBasedSchedulingTask::execute() {
    auto &timeBasedScheduling = Services.timeBasedScheduling;

    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true) {
        Time::CustomCUC_t now = TimeGetter::getCurrentTimeCustomCUC();
        auto nextActivityExecutionCUCTime = timeBasedScheduling.executeScheduledActivity(now);
        if (nextActivityExecutionCUCTime.elapsed100msTicks ==
            std::numeric_limits<decltype(nextActivityExecutionCUCTime.elapsed100msTicks)>::max()) {
            xTaskNotifyWait(0, 0, nullptr, portMAX_DELAY);
        } else {
            TickType_t nextActivityExecutionTime = (nextActivityExecutionCUCTime - now).getMs();
            vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextActivityExecutionTime));
        }
    }
}
