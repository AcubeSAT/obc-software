#include "UpdateParametersTask.hpp"

void UpdateParametersTask::execute() {
    TaskHandle_t updateParametersHandle = xTaskGetHandle(TaskName);

    while (true) {
//        AcubeSATParameters::availableHeap.setValue(
//                static_cast<uint16_t>(xPortGetFreeHeapSize()));
//        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}
