#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "BootCounter.hpp"
#include "SEGGER_RTT.h"
#include "FreeRTOSTasks/ReportParametersTask.hpp"
#include "FreeRTOSTasks/XUartDMATask.hpp"
#include "FreeRTOSTasks/UpdateParametersTask.hpp"
#include "FreeRTOSTasks/TemperatureTask.hpp"
#include "FreeRTOSTasks/HousekeepingTask.hpp"
#include "FreeRTOSTasks/Task.hpp"
#include "FreeRTOSTasks/XTimeKeepingTask.hpp"

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    XTimeKeepingTask xTimeKeepingTask("TimeKeeping", NULL, 1000, 1000);
    ReportParametersTask reportParametersTask("ParametersReporting", NULL, 2000, 11, 1000);
    UpdateParametersTask updateParametersTask("ParametersUpdating", NULL, 2000, 300);
    TemperatureTask temperatureTask("TemperatureSensor", NULL, 1000, 10000);
    XUartDMATask xUartDMATask("UartDMA", NULL, 10000, 3000);
    HousekeepingTask housekeepingTask("Housekeeping", NULL, 2000);

    xTaskCreate(Task::vClassTask, xTimeKeepingTask.taskName, xTimeKeepingTask.taskStackDepth,
                &xTimeKeepingTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, reportParametersTask.taskName, reportParametersTask.taskStackDepth,
                &reportParametersTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, updateParametersTask.taskName, updateParametersTask.taskStackDepth,
                &updateParametersTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, xUartDMATask.taskName, xUartDMATask.taskStackDepth,
                &xUartDMATask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, temperatureTask.taskName, temperatureTask.taskStackDepth,
                &temperatureTask, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(Task::vClassTask, housekeepingTask.taskName, housekeepingTask.taskStackDepth,
                &housekeepingTask, tskIDLE_PRIORITY + 1, NULL);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
