#include  "TimeSyncTask.hpp"
#include  "ApplicationLayer.hpp"


void TimeSyncTask::execute() {

    while (true) {


        CAN::Application::sendUTCTimeMessage();

        vTaskDelay(pdMS_TO_TICKS(TimeSyncPeriod));
    }

}