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
//#include "CANTransmitTask.hpp"
#include "TCHandlingTask.hpp"
#include "plib_pio.h"
#include "peripheral/pwm/plib_pwm0.h"
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
//void nandTest1() {
//    MT29F nandDie1(SMC::NCS1, NAND_RB_2_PIN);
//
//    for(int i = 0; i < 10; i++) {
//        nandDie1.sendData(0x11);
//        nandDie1.sendAddress(0x11);
//        nandDie1.sendCommand(0x11);
//        uint8_t a = nandDie1.readData();
//        vTaskDelay(pdMS_TO_TICKS(50));
//    }
//
//}
//
//void nandTest2() {
//    MT29F nandDie1(SMC::NCS1, NAND_RB_2_PIN);
//
//    nandDie1.readNANDID();
//}


/********************************* NAND Code */

//const static inline uint16_t Task1StackDepth = 2000;
//
//StackType_t taskStack[Task1StackDepth];
//
//StaticTask_t task1Buffer;

//void Task1(void *pvParameters) {
//    PIO_PinWrite(LCL_MRAM_RST_PIN, true);
//    PIO_PinWrite(LCL_MRAM_SET_PIN, true);
//    PWM0_ChannelsStart(PWM_CHANNEL_1_MASK);
//    PIO_PinWrite(LCL_MRAM_SET_PIN, false);
//    vTaskDelay(pdMS_TO_TICKS(10));
//    PIO_PinWrite(LCL_MRAM_SET_PIN, true);
//
//    while (true) {
//        nandTest1();
//        vTaskDelay(pdMS_TO_TICKS(500));
//        nandTest2();
//        vTaskDelay(pdMS_TO_TICKS(500));
//    }
//}

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
    initializeTasks();

//    housekeepingTask.emplace();
//    timeBasedSchedulingTask.emplace();
//    statisticsReportingTask.emplace();
//    updateParametersTask.emplace();
//    canTransmitTask.emplace();
//    tcHandlingTask.emplace();
    nandInitializeTask.emplace();
//
//    updateParametersTask->createTask();
//    statisticsReportingTask->createTask();
//    housekeepingTask->createTask();
//    timeBasedSchedulingTask->createTask();
//    tcHandlingTask->createTask();
//    canTransmitTask->createTask();
//    xTaskCreateStatic(Task1, "Task1",
//                      5000, NULL, tskIDLE_PRIORITY + 2, taskStack,
//                      &task1Buffer);
//    uartGatekeeperTask->createTask();
    nandInitializeTask->createTask();


    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
