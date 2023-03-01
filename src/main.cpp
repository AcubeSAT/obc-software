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
#include "MR4A08BUYS45.hpp"
//#include "NANDFlash.h"
//#include "SMC.h"

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

/********************************* NAND Code */
void mramTest1() {

//    MRAM mram(SMC::NCS1);

    volatile uint8_t * volatile mramBuffer = reinterpret_cast<volatile uint8_t * volatile> (EBI_CS1_ADDR);

    for(uint32_t i = 0; i < 2097152; i++) {
        mramBuffer[i] = 27;
    }

    for(uint32_t i = 0; i < 32; i++) {
        LOG_DEBUG << mramBuffer[i];
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

void mramTest2() {

    MRAM mram(SMC::NCS1);
    for(uint32_t i = 0; i < 2097152; i++) {
        mram.mramWriteByte(i, 28);
    }

    for(uint32_t i = 0; i < 32; i++) {
        LOG_DEBUG << mram.mramReadByte(i);
        vTaskDelay(pdMS_TO_TICKS(50));
    }

}

void mramTest3() {
    PIO_PinWrite(A0_PIN, false);
    PIO_PinWrite(A1_PIN, false);
    PIO_PinWrite(A2_PIN, false);
    PIO_PinWrite(A3_PIN, false);
    PIO_PinWrite(A4_PIN, false);
    PIO_PinWrite(A5_PIN, false);
    PIO_PinWrite(A6_PIN, false);
    PIO_PinWrite(A7_PIN, false);
    PIO_PinWrite(A8_PIN, false);
    PIO_PinWrite(A9_PIN, false);
    PIO_PinWrite(A10_PIN, false);
    PIO_PinWrite(A11_PIN, false);
    PIO_PinWrite(A12_PIN, false);
    PIO_PinWrite(A13_PIN, false);
    PIO_PinWrite(A14_PIN, false);
    PIO_PinWrite(A15_PIN, false);
    PIO_PinWrite(A16_PIN, false);
    PIO_PinWrite(A17_PIN, false);
    PIO_PinWrite(A18_PIN, false);
    PIO_PinWrite(A19_PIN, false);
    PIO_PinWrite(A20_PIN, false);

    *(reinterpret_cast<volatile uint8_t * volatile>(EBI_CS1_ADDR)) = 29;
}

void mramTest4() {
    MRAM mram(SMC::NCS1);
    mram.mramWriteByte(524290, 193); // 2^19 + 2 => address > 2^21
    for(int i = 0; i < 524288; i++) {
        if(mram.mramReadByte(i) == 193) {
            LOG_DEBUG << "found in address " << i;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}


/********************************* NAND Code */

const static inline uint16_t Task1StackDepth = 2000;

StackType_t taskStack[Task1StackDepth];

StaticTask_t task1Buffer;

void Task1(void *pvParameters) {
//    PIO_PinWrite(LCL_MRAM_RST_PIN, true);
//    PIO_PinWrite(LCL_MRAM_SET_PIN, true);
//    PWM0_ChannelsStart(PWM_CHANNEL_1_MASK);
//    PIO_PinWrite(LCL_MRAM_SET_PIN, false);
//    vTaskDelay(pdMS_TO_TICKS(10));
//    PIO_PinWrite(LCL_MRAM_SET_PIN, true);

    while (true) {
//        mramTest1();
//        vTaskDelay(pdMS_TO_TICKS(500));
//        mramTest2();
//        vTaskDelay(pdMS_TO_TICKS(500));
        mramTest3();
        vTaskDelay(pdMS_TO_TICKS(500));
//        mramTest4();
//        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
    initializeTasks();

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


