#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "InitializationTask.hpp"
#include "FreeRTOSHandlers.hpp"
#include "SEGGER_RTT.h"
#include "SEGGER_SYSVIEW.h"

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

    SEGGER_RTT_Init();
    SEGGER_SYSVIEW_Conf();
    SEGGER_SYSVIEW_Start();
    initializationTask.emplace();
    initializationTask->createTask();
    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }
}

