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
#include "plib_pio.h"
#include "peripheral/pwm/plib_pwm0.h"

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

    PIO_PinWrite(LCL_NAND_RST_PIN, true); // break point 1 here, before any LCL init code runs
    PIO_PinWrite(LCL_NAND_SET_PIN, true);
    PWM0_ChannelsStart(PWM_CHANNEL_0_MASK);


//    PWM0_ChannelsStart(PWM_CHANNEL_0_MASK);
    PIO_PinWrite(LCL_NAND_SET_PIN, false); // break point 2, before this runs
    vTaskDelay(pdMS_TO_TICKS(100));
    PIO_PinWrite(LCL_NAND_SET_PIN, true);

    PWM0_ChannelsStop(PWM_CHANNEL_0_MASK); // break point 3, before this runs

    PIO_PinWrite(LCL_NAND_RST_PIN, false); // break point 4, before this runs


//    PIO_PinWrite(LCL_MRAM_RST_PIN, true); // RESET
//    PIO_PinWrite(LCL_MRAM_SET_PIN, true); // SET
//    PWM0_ChannelsStart(PWM_CHANNEL_1_MASK);
//    PIO_PinWrite(LCL_MRAM_SET_PIN, false); // enable set
//    vTaskDelay(pdMS_TO_TICKS(100)); // any better ideas?
//    PIO_PinWrite(LCL_MRAM_SET_PIN, true); // disable set
//
//    PIO_PinWrite(LCL_CAN_2_RST_PIN, true); // RESET
//    PIO_PinWrite(LCL_CAN_2_SET_PIN, true); // SET
//    PWM0_ChannelsStart(PWM_CHANNEL_2_MASK);
//    PIO_PinWrite(LCL_CAN_2_SET_PIN, false); // enable set
//    vTaskDelay(pdMS_TO_TICKS(100)); // any better ideas?
//    PIO_PinWrite(LCL_CAN_2_SET_PIN, true); // disable set
//
//    PIO_PinWrite(LCL_CAN_1_RST_PIN, true); // RESET
//    PIO_PinWrite(LCL_CAN_1_SET_PIN, true); // SET
//    PWM0_ChannelsStart(PWM_CHANNEL_3_MASK);
//    PIO_PinWrite(LCL_CAN_1_SET_PIN, false); // enable set
//    vTaskDelay(pdMS_TO_TICKS(100)); // any better ideas?
//    PIO_PinWrite(LCL_CAN_1_SET_PIN, true); // disable set

    while (true) {
        PIO_PinToggle(PIO_PIN_PA30); // break point 5, before this runs
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
//    initializeTasks();

//    housekeepingTask.emplace();
//    timeBasedSchedulingTask.emplace();
//    statisticsReportingTask.emplace();
//    updateParametersTask.emplace();
//    canTransmitTask.emplace();
//    tcHandlingTask.emplace();
//
//    updateParametersTask->createTask();
//    statisticsReportingTask->createTask();
//    housekeepingTask->createTask();
//    timeBasedSchedulingTask->createTask();
//    tcHandlingTask->createTask();
//    canTransmitTask->createTask();
    xTaskCreateStatic(Task1, "Task1",
                      2000, NULL, tskIDLE_PRIORITY + 2, taskStack,
                      &task1Buffer);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
