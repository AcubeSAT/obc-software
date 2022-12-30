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

/********************************* MRAM Code */
#define MRAM_BASE_ADDRESS         (0x61000000) // NCS1 base address
static void accessMRAMTest1() {
    uint32_t i;
    uint8_t *ptr = (uint8_t *) MRAM_BASE_ADDRESS;
    for (i = 0; i < 10 * 1024; ++i) {
        if (i & 1) {
            ptr[i] = 0x96;
        } else {
            ptr[i] = 0x55;
        }
    }
    for (i = 0; i < 10 * 1024; ++i) {
        if (i & 1) {
            if (ptr[i] != 0x96) {
                LOG_DEBUG << "Wrong value in address = " << i;
            }
            else {
                LOG_DEBUG << "Correct value in address = " << i;
            }
        } else {
            if (ptr[i] != 0x55) {
                LOG_DEBUG << "Wrong value in address = " << i;
            }
            else {
                LOG_DEBUG << "Correct value in address = " << i;
            }
        }
    }
}

static void accessMRAMTest2()
{
    uint32_t i;
    uint32_t *ptr = (uint32_t *) MRAM_BASE_ADDRESS;

    for (i = 0; i < 10 * 1024; i+=4) {
        if (i & 1) {
            ptr[i] = i;
        } else {
            ptr[i] = 0xEFBEADDE;
        }
    }
    for (i = 0; i < 10 * 1024; ++i) {
        if (i & 1) {
            if (ptr[i] != i) {
                LOG_DEBUG << "Wrong value in address = " << i;
            }
            else {
                LOG_DEBUG << "Correct value in address = " << i;
            }
        } else {
            if (ptr[i] != 0xEFBEADDE) {
                LOG_DEBUG << "Wrong value in address = " << i;
            }
            else {
                LOG_DEBUG << "Correct value in address = " << i;
            }
        }
    }
}

/********************************* MRAM Code */

const static inline uint16_t Task1StackDepth = 2000;

StackType_t taskStack[Task1StackDepth];

StaticTask_t task1Buffer;

void Task1(void *pvParameters) {
    PIO_PinWrite(LCL_MRAM_RST_PIN, true);
    PIO_PinWrite(LCL_MRAM_SET_PIN, true);
    PWM0_ChannelsStart(PWM_CHANNEL_1_MASK);
    PIO_PinWrite(LCL_MRAM_SET_PIN, false);
    vTaskDelay(pdMS_TO_TICKS(10));
    PIO_PinWrite(LCL_MRAM_SET_PIN, true);

    // TODO: recheck this test
//    accessMRAMTest2(); // write 1 word at a time

    while (true) {
//        uint32_t i;
//        uint8_t *ptr = (uint8_t *) MRAM_BASE_ADDRESS;
//        for (i = 0; i < 10 * 1024; ++i) {
//            if (i & 1) {
//                ptr[i] = 0x96;
//            } else {
//                ptr[i] = 0x55;
//            }
//        }
        accessMRAMTest1(); // write 1 byte at a time
        vTaskDelay(pdMS_TO_TICKS(1000));
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
//    uartGatekeeperTask->createTask();

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
