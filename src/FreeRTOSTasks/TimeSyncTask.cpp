#include  "TimeSyncTask.hpp"

void TimeSyncTask::execute() {
    while (true) {
        if(timeRequested == 0) {
            CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS,false,{AcubeSATParameters::ADCSOnBoardTime},false);
            vTaskDelay(pdMS_TO_TICKS(TimeSyncPeriod));
        }
        else {
            CAN::Application::sendUTCTimeMessage();
            vTaskDelay(pdMS_TO_TICKS(TimeSyncPeriod));
        }
    }

}