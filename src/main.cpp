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
#include "FreeRTOSTasks/ReportParametersTask.hpp"
#include "FreeRTOSTasks/XUartDMATask.hpp"
#include "FreeRTOSTasks/UpdateParametersTask.hpp"
#include "FreeRTOSTasks/TemperatureTask.hpp"
#include "FreeRTOSTasks/Helper.hpp"

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    const char *taskName = "Task1";

    ReportParametersTask reportParametersTask;
    UpdateParametersTask updateParametersTask;
    TemperatureTask temperatureTask;
    XUartDMATask xUartDMATask;

    xTaskCreate(Task::vClassTask, taskName, FreeRTOSTaskStackDepth,
                &reportParametersTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, "Task2", FreeRTOSTaskStackDepth,
                &updateParametersTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, "UartDMA", FreeRTOSTaskStackDepth,
                &xUartDMATask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, "Temperature", FreeRTOSTaskStackDepth,
                &temperatureTask, tskIDLE_PRIORITY + 2, NULL);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
