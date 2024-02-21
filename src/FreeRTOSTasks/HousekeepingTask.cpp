#include "FreeRTOSTasks/HousekeepingTask.hpp"

void HousekeepingTask::execute() {
    auto &housekeeping = Services.housekeeping;
    Time::DefaultCUC nextCollection(0);
    Time::DefaultCUC timeBeforeDelay( 0);
    TickType_t xLastWakeTime = xTaskGetTickCount();
    Time::DefaultCUC TaskGetTickCountCUC (pdTICKS_TO_S(xTaskGetTickCount()));
    while (true) {
        nextCollection = housekeeping.reportPendingStructures(TaskGetTickCountCUC , timeBeforeDelay, nextCollection);
        timeBeforeDelay = TaskGetTickCountCUC;
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextCollection.formatAsBytes()));
    }
}
