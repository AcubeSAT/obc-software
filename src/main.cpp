#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.h"
#include "FreeRTOSTasks.hpp"
#include "BootCounter.h"

extern "C" void main_cpp() {
    bootCounterIncrement();

    SYS_Initialize(NULL);

    const char * taskName = "Task1";
    xTaskCreate(FreeRTOSTasks::parameterReporting, taskName, FreeRTOSTaskStackDepth,
                NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(FreeRTOSTasks::parameterUpdating, "Task2", FreeRTOSTaskStackDepth,
                &taskName, tskIDLE_PRIORITY + 1, NULL);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
