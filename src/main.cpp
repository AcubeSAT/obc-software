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

#define IDLE_TASK_SIZE 4000

#if configSUPPORT_STATIC_ALLOCATION
/* static memory allocation for the IDLE task */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[IDLE_TASK_SIZE];

extern "C" void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer,
                                              uint32_t *pulIdleTaskStackSize) {
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
    *ppxIdleTaskStackBuffer = &xIdleStack[0];
    *pulIdleTaskStackSize = IDLE_TASK_SIZE;
}

#endif

template<class T>
static void vClassTask(void *pvParameters) {
    (static_cast<T *>(pvParameters))->execute();
}

extern "C" void main_cpp() {
    using namespace TaskList;

    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    uartGatekeeperTask.emplace();
    mcuTemperatureTask.emplace();
    timeKeepingTask.emplace();
    housekeepingTask.emplace();
    updateParametersTask.emplace();
    timeBasedSchedulingTask.emplace();
    ambientTemperatureTask.emplace();
    watchdogTask.emplace();
    statisticsReportingTask.emplace();

    xTaskCreateStatic(vClassTask<StatisticsReportingTask>, statisticsReportingTask->taskName,
                      statisticsReportingTask->taskStackDepth, &statisticsReportingTask, tskIDLE_PRIORITY + 1,
                      statisticsReportingTask->taskStack, &statisticsReportingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<UARTGatekeeperTask>, uartGatekeeperTask->taskName, uartGatekeeperTask->taskStackDepth,
                      &uartGatekeeperTask, tskIDLE_PRIORITY + 2, uartGatekeeperTask->taskStack,
                      &uartGatekeeperTask->taskBuffer);
    xTaskCreateStatic(vClassTask<UpdateParametersTask>, updateParametersTask->taskName,
                      updateParametersTask->taskStackDepth,
                      &updateParametersTask, tskIDLE_PRIORITY + 1, updateParametersTask->taskStack,
                      &updateParametersTask->taskBuffer);
    xTaskCreateStatic(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
                      &timeKeepingTask, tskIDLE_PRIORITY + 1, timeKeepingTask->taskStack, &timeKeepingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<HousekeepingTask>, housekeepingTask->taskName, housekeepingTask->taskStackDepth,
                      &housekeepingTask, configMAX_PRIORITIES - 1, housekeepingTask->taskStack,
                      &housekeepingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<MCUTemperatureTask>, mcuTemperatureTask->taskName, mcuTemperatureTask->taskStackDepth,
                      &mcuTemperatureTask, tskIDLE_PRIORITY + 2, mcuTemperatureTask->taskStack,
                      &mcuTemperatureTask->taskBuffer);
    xTaskCreateStatic(vClassTask<AmbientTemperatureTask>, ambientTemperatureTask->taskName,
                      ambientTemperatureTask->taskStackDepth,
                      &ambientTemperatureTask, tskIDLE_PRIORITY + 2, ambientTemperatureTask->taskStack,
                      &ambientTemperatureTask->taskBuffer);
    TaskList::timeBasedSchedulingTask->taskHandle = xTaskCreateStatic(vClassTask<TimeBasedSchedulingTask>,
                                                                      timeBasedSchedulingTask->taskName,
                                                                      timeBasedSchedulingTask->taskStackDepth,
                                                                      &timeBasedSchedulingTask, tskIDLE_PRIORITY + 2,
                                                                      timeBasedSchedulingTask->taskStack,
                                                                      &timeBasedSchedulingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<WatchdogTask>, watchdogTask->taskName, watchdogTask->taskStackDepth,
                      &watchdogTask, tskIDLE_PRIORITY, watchdogTask->taskStack, &watchdogTask->taskBuffer);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
