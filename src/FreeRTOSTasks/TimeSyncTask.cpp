#include  "TimeSyncTask.hpp"
#include  "ApplicationLayer.hpp"


void TimeSyncTask::execute() {
    CAN::Application::switchBus(CAN::Driver::Main);

    while (true) {

        using namespace AcubeSATParameters;

        CAN::Application::sendUTCTimeMessage();

        vTaskDelay(pdMS_TO_TICKS(2000));
    }

}