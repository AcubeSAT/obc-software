#include "main.h"
#include "FreeRTOS.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "BootCounter.hpp"
#include "SEGGER_RTT.h"
#include "FreeRTOSTasks/TaskList.hpp"
#include "OBC_Definitions.hpp"

template<class T>
static void vClassTask(void *pvParameters) {
    (static_cast<T *>(pvParameters))->execute();
}

extern "C" void main_cpp() {
    using namespace TaskList;
    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    uartGatekeeper.emplace();
    uartDMATask.emplace();
    mcuTemperatureTask.emplace();
    timeKeepingTask.emplace();
    housekeepingTask.emplace();
    reportParametersTask.emplace();
    updateParametersTask.emplace();
    timeBasedSchedulingTask.emplace();
    ambientTemperatureTask.emplace();
    watchdogTask.emplace();

    xTaskCreate(vClassTask<UARTGatekeeper>, uartGatekeeper->taskName, uartGatekeeper->taskStackDepth,
                &uartGatekeeper, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(vClassTask<UartDMATask>, uartDMATask->taskName, uartDMATask->taskStackDepth,
                &uartDMATask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
                &timeKeepingTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vClassTask<MCUTemperatureTask>, mcuTemperatureTask->taskName, mcuTemperatureTask->taskStackDepth,
                &mcuTemperatureTask, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(vClassTask<ReportParametersTask>, reportParametersTask->taskName, reportParametersTask->taskStackDepth,
                &reportParametersTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vClassTask<UpdateParametersTask>, updateParametersTask->taskName, updateParametersTask->taskStackDepth,
                &updateParametersTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vClassTask<HousekeepingTask>, housekeepingTask->taskName, housekeepingTask->taskStackDepth,
                &housekeepingTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vClassTask<TimeBasedSchedulingTask>, timeBasedSchedulingTask->taskName, timeBasedSchedulingTask->taskStackDepth,
                &timeBasedSchedulingTask, tskIDLE_PRIORITY + 2, &timeBasedSchedulingTask->taskHandle);
    xTaskCreate(vClassTask<AmbientTemperatureTask>, ambientTemperatureTask->taskName, ambientTemperatureTask->taskStackDepth,
                &ambientTemperatureTask, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(vClassTask<WatchdogTask>, watchdogTask->taskName, watchdogTask->taskStackDepth,
               &watchdogTask, tskIDLE_PRIORITY, NULL);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
