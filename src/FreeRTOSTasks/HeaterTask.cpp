//
// Created by evangelia on 3/12/24.
//


#include "FreeRTOSTasks/HeaterTask.hpp"

void HeaterTask::execute() {
    while (true) {
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}