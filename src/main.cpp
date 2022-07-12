#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "BootCounter.hpp"
#include "SEGGER_RTT.h"
#include "FreeRTOSTasks/Task.hpp"
#include "FreeRTOSTasks/TaskList.hpp"



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
    mcuTemperatureTask.emplace();
    timeKeepingTask.emplace();
    housekeepingTask.emplace();
    updateParametersTask.emplace();
    timeBasedSchedulingTask.emplace();
    ambientTemperatureTask.emplace();
    watchdogTask.emplace();

    xTaskCreateStatic(vClassTask<UARTGatekeeper>, uartGatekeeper->taskName, uartGatekeeper->taskStackDepth,
                      &uartGatekeeper, tskIDLE_PRIORITY + 2, UARTGatekeeper::taskStack, &uartGatekeeper->taskBuffer);
    xTaskCreateStatic(vClassTask<UpdateParametersTask>, updateParametersTask->taskName, updateParametersTask->taskStackDepth,
                      &updateParametersTask, tskIDLE_PRIORITY + 1, UpdateParametersTask::taskStack,
                      &updateParametersTask->taskBuffer);
    xTaskCreateStatic(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
                      &timeKeepingTask, tskIDLE_PRIORITY + 1, TimeKeepingTask::taskStack, &timeKeepingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<HousekeepingTask>, housekeepingTask->taskName, housekeepingTask->taskStackDepth,
                      &housekeepingTask, configMAX_PRIORITIES - 1, HousekeepingTask::taskStack, &housekeepingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<MCUTemperatureTask>, mcuTemperatureTask->taskName, mcuTemperatureTask->taskStackDepth,
                      &mcuTemperatureTask, tskIDLE_PRIORITY + 2, MCUTemperatureTask::taskStack, &mcuTemperatureTask->taskBuffer);
    xTaskCreateStatic(vClassTask<AmbientTemperatureTask>, ambientTemperatureTask->taskName, ambientTemperatureTask->taskStackDepth,
                &ambientTemperatureTask, tskIDLE_PRIORITY + 2, AmbientTemperatureTask::taskStack, &ambientTemperatureTask->taskBuffer );
    xTaskCreateStatic(vClassTask<TimeBasedSchedulingTask>, timeBasedSchedulingTask->taskName,timeBasedSchedulingTask->taskStackDepth,
                      &timeBasedSchedulingTask, tskIDLE_PRIORITY + 2, TimeBasedSchedulingTask::taskStack, &timeBasedSchedulingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<WatchdogTask>, watchdogTask->taskName, watchdogTask->taskStackDepth,
                      &watchdogTask, tskIDLE_PRIORITY, WatchdogTask::taskStack, &watchdogTask->taskBuffer);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
