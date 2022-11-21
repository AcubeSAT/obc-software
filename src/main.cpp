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
#include "CANGatekeeperTask.hpp"
#include "CANTestTask.hpp"
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
    canGatekeeperTask.emplace();
    canTestTask.emplace();
    tcHandlingTask.emplace();

    updateParametersTask->createTask();
    statisticsReportingTask->createTask();
    housekeepingTask->createTask();
    timeBasedSchedulingTask->createTask();
    tcHandlingTask->createTask();
    canGatekeeperTask->createTask();
    canTestTask->createTask();

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
