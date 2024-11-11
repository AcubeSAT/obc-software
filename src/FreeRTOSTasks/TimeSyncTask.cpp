#include  "TimeSyncTask.hpp"

void TimeSyncTask::execute() {
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    while (true) {
        CAN::Application::sendUTCTimeMessage();

        vTaskDelay(pdMS_TO_TICKS(TimeSyncPeriod));
    }

}