#include "WatchdogTask.hpp"

void WatchdogTask::execute() {
    while (true) {
        WDT_Clear();
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}
