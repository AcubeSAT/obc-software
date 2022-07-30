#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "BootCounter.hpp"
#include "FreeRTOSTasks/Task.hpp"
#include "FreeRTOSTasks/TaskList.hpp"
#include "TaskInitialization.hpp"

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

extern "C" void main_cpp() {
    using namespace TaskList;

    SYS_Initialize(NULL);
    Init::initializeTasks();

    mcuTemperatureTask.emplace();
    housekeepingTask.emplace();
    timeBasedSchedulingTask.emplace();
    statisticsReportingTask.emplace();

    xTaskCreateStatic(vClassTask<StatisticsReportingTask>, statisticsReportingTask->taskName,
                      statisticsReportingTask->taskStackDepth, &statisticsReportingTask, tskIDLE_PRIORITY + 1,
                      statisticsReportingTask->taskStack, &statisticsReportingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<HousekeepingTask>, housekeepingTask->taskName, housekeepingTask->taskStackDepth,
                      &housekeepingTask, configMAX_PRIORITIES - 1, housekeepingTask->taskStack,
                      &housekeepingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<MCUTemperatureTask>, mcuTemperatureTask->taskName, mcuTemperatureTask->taskStackDepth,
                      &mcuTemperatureTask, tskIDLE_PRIORITY + 2, mcuTemperatureTask->taskStack,
                      &mcuTemperatureTask->taskBuffer);
    timeBasedSchedulingTask->taskHandle = xTaskCreateStatic(vClassTask<TimeBasedSchedulingTask>,
                                                            timeBasedSchedulingTask->taskName,
                                                            timeBasedSchedulingTask->taskStackDepth,
                                                            &timeBasedSchedulingTask, tskIDLE_PRIORITY + 2,
                                                            timeBasedSchedulingTask->taskStack,
                                                            &timeBasedSchedulingTask->taskBuffer);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
