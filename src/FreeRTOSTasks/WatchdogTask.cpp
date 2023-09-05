#include "WatchdogTask.hpp"

void WatchdogTask::execute() {
    while (true) {
        WDT_Clear();
        LOG_DEBUG << "Watchdog reset";
        vTaskDelay(pdMS_TO_TICKS(WatchdogWindow));
    }
}
