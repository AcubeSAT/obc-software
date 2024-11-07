#include  "TimeSyncTask.hpp"
#include  "ApplicationLayer.hpp"


void TimeSyncTask::execute() {

    while (true) {

        using namespace AcubeSATParameters;

        CAN::Application::sendUTCTimeMessage();

        vTaskDelay(pdMS_TO_TICKS(2000));
    }

}