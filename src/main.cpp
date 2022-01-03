#include "main.h"
#include "SEGGER_RTT.h"
#include "ServicePool.hpp"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.h"
#include "FreeRTOSTasks.hpp"

extern "C" void main_cpp() {
    SYS_Initialize(NULL);

    xTaskCreate(FreeRTOSTasks::ParameterReporting, "Task1", FreeRTOSTaskStackDepth, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(FreeRTOSTasks::ParameterUpdating, "Task2", FreeRTOSTaskStackDepth, NULL, tskIDLE_PRIORITY + 1, NULL);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}