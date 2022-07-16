#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "BootCounter.hpp"
#include "SEGGER_RTT.h"
#include "FreeRTOSTasks/Task.hpp"
#include "FreeRTOSTasks/TaskList.hpp"

static StaticTask_t timekeepingTaskBuffer;
static StackType_t timekeepingTaskStack[configMINIMAL_STACK_SIZE * 1];
static StaticTask_t housekeepingTaskBuffer;
static StackType_t housekeepingTaskStack[configMINIMAL_STACK_SIZE * 2];
static StaticTask_t mcuTemperatureTaskBuffer;
static StackType_t mcuTemperatureTaskStack[configMINIMAL_STACK_SIZE * 1];
static StaticTask_t ambientTemperatureTaskBuffer;
static StackType_t ambientTemperatureTaskStack[configMINIMAL_STACK_SIZE * 2];
static StaticTask_t updateParametersTaskBuffer;
static StackType_t updateParametersTaskStack[configMINIMAL_STACK_SIZE * 6];
static StaticTask_t uartGatekeeperTaskBuffer;
static StackType_t uartGatekeeperTaskStack[configMINIMAL_STACK_SIZE * 2];
static StaticTask_t timeBasedSchedulingTaskBuffer;
static StackType_t timeBasedSchedulingTaskStack[configMINIMAL_STACK_SIZE * 4];
static StaticTask_t watchdogTaskBuffer;
static StackType_t watchdogTaskStack[configMINIMAL_STACK_SIZE * 2];


#define IDLE_TASK_SIZE 4000

#if configSUPPORT_STATIC_ALLOCATION
/* static memory allocation for the IDLE task */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[IDLE_TASK_SIZE];

extern "C" void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize) {
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
    *ppxIdleTaskStackBuffer = &xIdleStack[0];
    *pulIdleTaskStackSize = IDLE_TASK_SIZE;
}

#endif

template<class T>
static void vClassTask(void *pvParameters) {
    (static_cast<T *>(pvParameters))->execute();
}

extern "C" void main_cpp() {
    using namespace TaskList;

    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    uartGatekeeperTask.emplace();
    mcuTemperatureTask.emplace();
    timeKeepingTask.emplace();
    housekeepingTask.emplace();
    updateParametersTask.emplace();
    timeBasedSchedulingTask.emplace();
    ambientTemperatureTask.emplace();
    watchdogTask.emplace();

    xTaskCreateStatic(vClassTask<UARTGatekeeperTask>, uartGatekeeperTask->taskName, uartGatekeeperTask->taskStackDepth,
                      &uartGatekeeperTask, tskIDLE_PRIORITY + 2, uartGatekeeperTask->taskStack, &uartGatekeeperTask->taskBuffer);
    xTaskCreateStatic(vClassTask<UpdateParametersTask>, updateParametersTask->taskName, updateParametersTask->taskStackDepth,
                      &updateParametersTask, tskIDLE_PRIORITY + 1, updateParametersTaskStack,
                      &updateParametersTaskBuffer);
    xTaskCreateStatic(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
                      &timeKeepingTask, tskIDLE_PRIORITY + 1, timeKeepingTask->taskStack, &timeKeepingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<HousekeepingTask>, housekeepingTask->taskName, housekeepingTask->taskStackDepth,
                      &housekeepingTask, configMAX_PRIORITIES - 1, housekeepingTask->taskStack, &housekeepingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<MCUTemperatureTask>, mcuTemperatureTask->taskName, mcuTemperatureTask->taskStackDepth,
                      &mcuTemperatureTask, tskIDLE_PRIORITY + 2, mcuTemperatureTask->taskStack, &mcuTemperatureTask->taskBuffer);
//    xTaskCreateStatic(vClassTask<AmbientTemperatureTask>, ambientTemperatureTask->taskName, ambientTemperatureTask->taskStackDepth,
//                &ambientTemperatureTask, tskIDLE_PRIORITY + 2, ambientTemperatureTask->taskStack, &ambientTemperatureTask->taskBuffer );
    xTaskCreateStatic(vClassTask<TimeBasedSchedulingTask>, timeBasedSchedulingTask->taskName,timeBasedSchedulingTask->taskStackDepth,
                      &timeBasedSchedulingTask, tskIDLE_PRIORITY + 2, timeBasedSchedulingTask->taskStack, &timeBasedSchedulingTask->taskBuffer);
    xTaskCreateStatic(vClassTask<WatchdogTask>, watchdogTask->taskName, watchdogTask->taskStackDepth,
                      &watchdogTask, tskIDLE_PRIORITY, watchdogTask->taskStack, &watchdogTask->taskBuffer);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
