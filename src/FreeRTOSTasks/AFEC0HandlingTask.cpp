#include "AFEC0HandlingTask.hpp"

AFEC0HandlingTask::AFEC0HandlingTask() : Task("AFEC0HandlingTask") {
    AFEC0_CallbackRegister([](uint32_t status, uintptr_t context) -> void {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        configASSERT(AFEC0HandlingTaskHandle != nullptr);
        vTaskNotifyGiveFromISR(AFEC0HandlingTaskHandle, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken)
    }, reinterpret_cast<uintptr_t>(nullptr));
}

void AFEC0HandlingTask::execute() {
    while (true) {
        AFEC0_ConversionStart();

        if (ulTaskNotifyTake(pdTRUE, MaxDelay) != pdTRUE) {
            LOG_ERROR << "AFEC Handler 0: Task notification was not received!";
            AFEC0_Initialize();
        }

        vTaskDelay(pdMS_TO_TICKS(DelayMs));
    }
}