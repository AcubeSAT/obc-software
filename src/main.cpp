#include "main.h"
#include "FreeRTOS.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "BootCounter.hpp"
#include "SEGGER_RTT.h"
#include "FreeRTOSTasks/TaskList.hpp"

static StaticTask_t timekeepingTaskBuffer;
static StackType_t timekeepingTaskStack[ configMINIMAL_STACK_SIZE * 1 ];
static StaticTask_t housekeepingTaskBuffer;
static StackType_t housekeepingTaskStack[configMINIMAL_STACK_SIZE * 2];
static StaticTask_t mcuTemperatureTaskBuffer;
static StackType_t mcuTemperatureTaskStack[configMINIMAL_STACK_SIZE * 1 ];
static StaticTask_t updateParametersTaskBuffer;
static StackType_t updateParametersTaskStack[configMINIMAL_STACK_SIZE * 2 ];
static StaticTask_t ambientTemperatureTaskBuffer;
static StackType_t ambientTemperatureTaskStack[configMINIMAL_STACK_SIZE * 2 ];

template<class T>
static void vClassTask(void *pvParameters) {
    (static_cast<T *>(pvParameters))->execute();
}

extern "C" void main_cpp() {
    using namespace TaskList;

    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    mcuTemperatureTask.emplace();
    timeKeepingTask.emplace();
    housekeepingTask.emplace();
    updateParametersTask.emplace();
    ambientTemperatureTask.emplace();

    xTaskCreateStatic(vClassTask<UpdateParametersTask>, updateParametersTask->taskName, updateParametersTask->taskStackDepth,
                      &updateParametersTask, tskIDLE_PRIORITY + 1, updateParametersTaskStack, &updateParametersTaskBuffer );
    xTaskCreateStatic(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
                      &timeKeepingTask, tskIDLE_PRIORITY + 1, timekeepingTaskStack, &timekeepingTaskBuffer);
    xTaskCreateStatic(vClassTask<HousekeepingTask>, housekeepingTask->taskName, housekeepingTask->taskStackDepth,
                      &housekeepingTask, configMAX_PRIORITIES - 1, housekeepingTaskStack, &housekeepingTaskBuffer );
    xTaskCreateStatic(vClassTask<MCUTemperatureTask>, mcuTemperatureTask->taskName, mcuTemperatureTask->taskStackDepth,
                      &mcuTemperatureTask, tskIDLE_PRIORITY + 2, mcuTemperatureTaskStack, &mcuTemperatureTaskBuffer );
//    xTaskCreateStatic(vClassTask<AmbientTemperatureTask>, ambientTemperatureTask->taskName, ambientTemperatureTask->taskStackDepth,
//                &ambientTemperatureTask, tskIDLE_PRIORITY + 2, ambientTemperatureTaskStack, &ambientTemperatureTaskBuffer );

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
/* If the buffers to be provided to the Idle task are declared inside this
function then they must be declared static - otherwise they will be allocated on
the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE * 2];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE * 2;
}
