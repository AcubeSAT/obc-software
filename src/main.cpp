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
#include "UARTGatekeeperTask.hpp"

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

const static inline uint16_t Task1StackDepth = 2000;

StackType_t taskStack[Task1StackDepth];

StaticTask_t task1Buffer;

void Task1(void *pvParameters) {
    while(true) {
        LOG_DEBUG << "Hello, world!";
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
//    initializeTasks();
//
//    housekeepingTask.emplace();
//    timeBasedSchedulingTask.emplace();
//    statisticsReportingTask.emplace();
//    updateParametersTask.emplace();
//    canGatekeeperTask.emplace();
//    canTestTask.emplace();
//    tcHandlingTask.emplace();
//
//    updateParametersTask->createTask();
//    statisticsReportingTask->createTask();
//    housekeepingTask->createTask();
//    timeBasedSchedulingTask->createTask();
//    tcHandlingTask->createTask();
//    canGatekeeperTask->createTask();
//    canTestTask->createTask();
    uartGatekeeperTask.emplace();
    uartGatekeeperTask->createTask();
    xTaskCreateStatic(Task1, "Task1",
                      2000, NULL, tskIDLE_PRIORITY + 2, taskStack,
                      &task1Buffer);    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
