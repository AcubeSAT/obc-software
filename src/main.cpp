#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "TaskInitialization.hpp"
#include "HousekeepingTask.hpp"
#include "UpdateParametersTask.hpp"
#include "TimeBasedSchedulingTask.hpp"
#include "StatisticsReportingTask.hpp"
#include "CANTransmitTask.hpp"
#include "TCHandlingTask.hpp"

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


    SYS_Initialize(NULL);
    initializeTasks();

    housekeepingTask.emplace();
    timeBasedSchedulingTask.emplace();
    statisticsReportingTask.emplace();
    updateParametersTask.emplace();
    canTransmitTask.emplace();
    tcHandlingTask.emplace();

    xTaskCreateStatic(vClassTask<UpdateParametersTask>, updateParametersTask->TaskName,
                      updateParametersTask->TaskStackDepth,
                      &updateParametersTask, tskIDLE_PRIORITY + 1, updateParametersTask->taskStack,
                      &updateParametersTask->taskBuffer);
    xTaskCreateStatic(vClassTask<StatisticsReportingTask>, statisticsReportingTask->TaskName,
                      statisticsReportingTask->TaskStackDepth, &statisticsReportingTask, tskIDLE_PRIORITY + 1,
                      statisticsReportingTask->taskStack, &statisticsReportingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<HousekeepingTask>, housekeepingTask->TaskName, housekeepingTask->TaskStackDepth,
                      &housekeepingTask, configMAX_PRIORITIES - 1, housekeepingTask->taskStack,
                      &housekeepingTask->taskBuffer);
    timeBasedSchedulingTask->taskHandle = xTaskCreateStatic(vClassTask<TimeBasedSchedulingTask>,
                                                            timeBasedSchedulingTask->TaskName,
                                                            timeBasedSchedulingTask->TaskStackDepth,
                                                            &timeBasedSchedulingTask, tskIDLE_PRIORITY + 2,
                                                            timeBasedSchedulingTask->taskStack,
                                                            &timeBasedSchedulingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<CANTransmitTask>, canTransmitTask->TaskName, canTransmitTask->TaskStackDepth,
                      &canTransmitTask, tskIDLE_PRIORITY + 1, canTransmitTask->taskStack, &canTransmitTask->taskBuffer);
    xTaskCreateStatic(vClassTask<TCHandlingTask>, tcHandlingTask->TaskName, tcHandlingTask->TaskStackDepth,
                      &tcHandlingTask, tskIDLE_PRIORITY+1, tcHandlingTask->taskStack, &tcHandlingTask->taskBuffer);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
