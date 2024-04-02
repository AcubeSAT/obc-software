#include "FreeRTOSTasks/HeaterTask.hpp"
#include "inc/FreeRTOSTasks/heater.hpp"


void HeaterTask::execute() {

    Heater Myheater;
    Myheater.startHeater();
    Myheater.setDutyPercentage(150);

    while (true) {

        vTaskDelay(pdMS_TO_TICKS(5000));
    }

}