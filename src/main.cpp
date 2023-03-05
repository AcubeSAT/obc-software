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
#include "MR4A08BUYS45.hpp"
#include "SMC.hpp"

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

void mramTest1() {
    LOG_DEBUG << "MRAM Test 1";
    vTaskDelay(pdMS_TO_TICKS(150));

    MRAM mram(SMC::NCS0);

    for(uint32_t i = 0; i < 32; i++) {
        LOG_DEBUG << "Position = " << i << " ,value = " << mram.mramReadByte(i);
        vTaskDelay(pdMS_TO_TICKS(150));
    }

}

void mramTest2() {
    LOG_DEBUG << "MRAM Test 2";
    vTaskDelay(pdMS_TO_TICKS(150));

    MRAM mram(SMC::NCS0);

    for(uint32_t i = 0; i < 32; i++) {
        mram.mramWriteByte(i, i+1);
        vTaskDelay(pdMS_TO_TICKS(1));
    }

    for(uint32_t i = 0; i < 32; i++) {
        LOG_DEBUG << "Position = " << i << " ,value = " << mram.mramReadByte(i);
        vTaskDelay(pdMS_TO_TICKS(150));
    }

}

void mramTest3() {
    LOG_DEBUG << "MRAM Test 3";
    vTaskDelay(pdMS_TO_TICKS(150));

    volatile uint8_t * volatile mramBuffer = reinterpret_cast<volatile uint8_t * volatile>(EBI_CS0_ADDR);

    for(uint32_t i = 0; i < 32; i++) {
        mramBuffer[i] = i+5;
        vTaskDelay(pdMS_TO_TICKS(1));
    }

    for(uint32_t i = 0; i < 32; i++) {
        LOG_DEBUG << "Position = " << i << " ,value = " << mramBuffer[i];
        vTaskDelay(pdMS_TO_TICKS(150));
    }

}

void Task1(void *pvParameters) {
    PIO_PinWrite(LCL_MRAM_RST_PIN, true);
    PIO_PinWrite(LCL_MRAM_SET_PIN, true);
    PWM0_ChannelsStart(PWM_CHANNEL_1_MASK);
    PIO_PinWrite(LCL_MRAM_SET_PIN, false);
    vTaskDelay(pdMS_TO_TICKS(10));
    PIO_PinWrite(LCL_MRAM_SET_PIN, true);

    while (true) {
        mramTest1();
        vTaskDelay(pdMS_TO_TICKS(500));
        mramTest2();
        vTaskDelay(pdMS_TO_TICKS(500));
        mramTest3();
        vTaskDelay(pdMS_TO_TICKS(500));
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
//    canTransmitTask.emplace();
//    tcHandlingTask.emplace();
//
//    updateParametersTask->createTask();
//    statisticsReportingTask->createTask();
//    housekeepingTask->createTask();
//    timeBasedSchedulingTask->createTask();
//    tcHandlingTask->createTask();
//    canTransmitTask->createTask();
    uartGatekeeperTask.emplace();
//    nandInitializeTask.emplace();

    uartGatekeeperTask->createTask();
//    nandInitializeTask->createTask();
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
