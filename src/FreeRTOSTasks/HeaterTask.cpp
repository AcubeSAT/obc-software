#include "FreeRTOSTasks/HeaterTask.hpp"
#include "inc/FreeRTOSTasks/heater.hpp"


void HeaterTask::execute() {

    heater Myheater;
    Myheater.startHeater();
    Myheater.setDutyPercentage(30);

    while (true) {

        vTaskDelay(pdMS_TO_TICKS(5000));
    }

}