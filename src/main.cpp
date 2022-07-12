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


template<class T>
static void vClassTask(void *pvParameters) {
    (static_cast<T *>(pvParameters))->execute();
}

extern "C" void main_cpp() {
    using namespace TaskList;

    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    uartGatekeeper.emplace();
    mcuTemperatureTask.emplace();
    timeKeepingTask.emplace();
    housekeepingTask.emplace();
    updateParametersTask.emplace();
    timeBasedSchedulingTask.emplace();
    ambientTemperatureTask.emplace();
    watchdogTask.emplace();

    xTaskCreateStatic(vClassTask<UARTGatekeeper>, uartGatekeeper->taskName, uartGatekeeper->taskStackDepth,
                      &uartGatekeeper, tskIDLE_PRIORITY + 2, uartGatekeeperTaskStack, &uartGatekeeperTaskBuffer);
    xTaskCreateStatic(vClassTask<UpdateParametersTask>, updateParametersTask->taskName, updateParametersTask->taskStackDepth,
                      &updateParametersTask, tskIDLE_PRIORITY + 1, updateParametersTaskStack,
                      &updateParametersTaskBuffer);
    xTaskCreateStatic(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
                      &timeKeepingTask, tskIDLE_PRIORITY + 1, timekeepingTaskStack, &timekeepingTaskBuffer);
    xTaskCreateStatic(vClassTask<HousekeepingTask>, housekeepingTask->taskName, housekeepingTask->taskStackDepth,
                      &housekeepingTask, configMAX_PRIORITIES - 1, housekeepingTaskStack, &housekeepingTaskBuffer);
    xTaskCreateStatic(vClassTask<MCUTemperatureTask>, mcuTemperatureTask->taskName, mcuTemperatureTask->taskStackDepth,
                      &mcuTemperatureTask, tskIDLE_PRIORITY + 2, mcuTemperatureTaskStack, &mcuTemperatureTaskBuffer);
//    xTaskCreateStatic(vClassTask<AmbientTemperatureTask>, ambientTemperatureTask->taskName, ambientTemperatureTask->taskStackDepth,
//                &ambientTemperatureTask, tskIDLE_PRIORITY + 2, ambientTemperatureTaskStack, &ambientTemperatureTaskBuffer );
    xTaskCreateStatic(vClassTask<TimeBasedSchedulingTask>, timeBasedSchedulingTask->taskName,timeBasedSchedulingTask->taskStackDepth,
                      &timeBasedSchedulingTask, tskIDLE_PRIORITY + 2, timeBasedSchedulingTaskStack, &timeBasedSchedulingTaskBuffer);
    xTaskCreateStatic(vClassTask<WatchdogTask>, watchdogTask->taskName, watchdogTask->taskStackDepth,
                      &watchdogTask, tskIDLE_PRIORITY, watchdogTaskStack, &watchdogTaskBuffer);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}