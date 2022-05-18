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
#include "FreeRTOSTasks/XUartDMATask.hpp"
#include "FreeRTOSTasks/XTimeKeepingTask.hpp"
#include "FreeRTOSTasks/TaskList.hpp"

extern "C" void main_cpp() {
    using namespace TaskList;

    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    xTaskCreate(Task::vClassTask, xUartDMATask.taskName, 1000,
                &xUartDMATask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, xTimeKeepingTask.taskName, 1000,
                &xTimeKeepingTask, tskIDLE_PRIORITY + 2, NULL);

//    const char *taskName = "Task1";
//    xTaskCreate(FreeRTOSTasks::reportParameters, taskName, 2000,
//                NULL, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::updateParameters, "Task2", 2000,
//                &taskName, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::xUartDMA, "UartDMA", 10000,
//                NULL, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::xTimeKeeping, "timeKeeping", 1000,
//                NULL, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::housekeeping, "Housekeeping", 2000,
//                NULL, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::temperatureTask, "Temperature", 1000,
//                NULL, tskIDLE_PRIORITY + 2, NULL);
    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
