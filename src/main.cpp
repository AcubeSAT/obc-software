#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "FreeRTOSTasks.hpp"
#include "BootCounter.hpp"
#include "SEGGER_RTT.h"

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    const char * taskName = "Task1";
    xTaskCreate(FreeRTOSTasks::reportParameters, taskName, FreeRTOSTaskStackDepth,
                NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(FreeRTOSTasks::updateParameters, "Task2", FreeRTOSTaskStackDepth,
                &taskName, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(FreeRTOSTasks::xUartDMA, "UartDMA", FreeRTOSTaskStackDepth,
                NULL,tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(FreeRTOSTasks::temperatureTask, "Temperature", FreeRTOSTaskStackDepth,
                NULL,tskIDLE_PRIORITY + 2, NULL);
    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
