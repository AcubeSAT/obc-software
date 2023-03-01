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
#include "WatchdogTask.hpp"

#define IDLE_TASK_SIZE 100

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
TaskHandle_t taskHandle1;

void CANLCLInit(void *pvParameters) {
    PIO_PinWrite(LCL_CAN_2_RST_PIN, true); // break point 1 here, before any LCL init code runs
    PIO_PinWrite(LCL_CAN_2_SET_PIN, true);
    PWM0_ChannelsStart(PWM_CHANNEL_2_MASK);

    PIO_PinWrite(LCL_CAN_2_SET_PIN, false); // break point 2, before this runs
    vTaskDelay(pdMS_TO_TICKS(100));
    PIO_PinWrite(LCL_CAN_2_SET_PIN, true);

    vTaskSuspend(taskHandle1);

    while(true) {

    }
}

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
//    initializeTasks();
//
//    housekeepingTask.emplace();
    uartGatekeeperTask.emplace();
    taskHandle1 = xTaskCreateStatic(CANLCLInit, "CAN LCL Init",
                      2000, NULL, tskIDLE_PRIORITY + 2, taskStack,
                      &task1Buffer);
//    timeBasedSchedulingTask.emplace();
//    statisticsReportingTask.emplace();
//    updateParametersTask.emplace();
    canGatekeeperTask.emplace();
    canTestTask.emplace();
//    tcHandlingTask.emplace();
//
//    updateParametersTask->createTask();
//    statisticsReportingTask->createTask();
//    housekeepingTask->createTask();
//    timeBasedSchedulingTask->createTask();
//    tcHandlingTask->createTask();
    uartGatekeeperTask->createTask();
    canGatekeeperTask->createTask();
    canTestTask->createTask();

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
