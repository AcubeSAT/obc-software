#include  "TimeSyncTask.hpp"

void TimeSyncTask::execute() {
    while (true) {
        if (timeRequested == false) {
          vTaskDelay(pdMS_TO_TICKS(1000));
          AcubeSATParameters::adcsOnBoardTime.setNotifier(updateTimeOnReset);
          CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{AcubeSATParameters::ADCSOnBoardTime}, false);
          ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        } else {
            vTaskDelay(pdMS_TO_TICKS(100));
            CAN::Application::sendUTCTimeMessage();
            vTaskDelay(pdMS_TO_TICKS(TimeSyncPeriod));
        }
    }
}
