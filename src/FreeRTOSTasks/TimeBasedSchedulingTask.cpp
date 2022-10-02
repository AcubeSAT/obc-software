#include "FreeRTOSTasks/TimeBasedSchedulingTask.hpp"

void TimeBasedSchedulingTask::execute() {
    auto &timeBasedScheduling = Services.timeBasedScheduling;

    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true) {
        Time::DefaultCUC now = TimeGetter::getCurrentTimeDefaultCUC();
        auto nextActivityExecutionCUCTime = timeBasedScheduling.executeScheduledActivity(now);
        if (nextActivityExecutionCUCTime == Time::DefaultCUC::max()) {
            xTaskNotifyWait(0, 0, nullptr, portMAX_DELAY);
        } else {
            TickType_t nextActivityExecutionTime = std::chrono::duration_cast<std::chrono::milliseconds>(nextActivityExecutionCUCTime - now).count();
            vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextActivityExecutionTime));
        }
    }
}
