#include "FreeRTOSTasks/HousekeepingTask.hpp"

void HousekeepingTask::execute() {
    auto &housekeeping = Services.housekeeping;
    uint32_t nextCollection = 0;
    uint32_t timeBeforeDelay = 0;
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true) {
        nextCollection = housekeeping.reportPendingStructures(xTaskGetTickCount(), timeBeforeDelay, nextCollection);
        timeBeforeDelay = xTaskGetTickCount();
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextCollection));
    }
}
