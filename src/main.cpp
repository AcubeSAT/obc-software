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

template<class T>
static void vClassTask(void *pvParameters) {
    (static_cast<T *>(pvParameters))->execute();
}

extern "C" void main_cpp() {
    using namespace TaskList;

    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();
    uartDMATask.emplace();
    mcuTemperatureTask.emplace();
    timeKeepingTask.emplace();
    housekeepingTask.emplace();
    reportParametersTask.emplace();
    updateParametersTask.emplace();
    ambientTemperatureTask.emplace();
    static StaticTask_t xCheckTask;

/* Allocate the stack that will be used by the task.  NOTE:  This is declared
static so it still exists after this function has returned. */
    static StackType_t ucTaskStack[ configMINIMAL_STACK_SIZE * sizeof( StackType_t ) ];

    static StaticTask_t xCheckTask1;
    static StackType_t ucTaskStack1[ configMINIMAL_STACK_SIZE * sizeof( StackType_t ) ];
    static StaticTask_t xCheckTask2;
    static StackType_t ucTaskStack2[ configMINIMAL_STACK_SIZE * sizeof( StackType_t ) ];
    static StaticTask_t xCheckTask3;
    static StackType_t ucTaskStack3[ configMINIMAL_STACK_SIZE * 1 ];
//    static StaticTask_t xCheckTask4;
//    static StackType_t ucTaskStack4[ configMINIMAL_STACK_SIZE * sizeof( StackType_t ) ];


//    xTaskCreateStatic(vClassTask<UartDMATask>, uartDMATask->taskName, uartDMATask->taskStackDepth,
//                &uartDMATask, tskIDLE_PRIORITY + 1,  ucTaskStack, &xCheckTask );
    xTaskCreateStatic(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
                &timeKeepingTask, tskIDLE_PRIORITY + 1, ucTaskStack, &xCheckTask);
    xTaskCreateStatic(vClassTask<MCUTemperatureTask>, mcuTemperatureTask->taskName, mcuTemperatureTask->taskStackDepth,
                &mcuTemperatureTask, tskIDLE_PRIORITY + 2, ucTaskStack2, &xCheckTask2 );
    xTaskCreateStatic(vClassTask<ReportParametersTask>, reportParametersTask->taskName, reportParametersTask->taskStackDepth,
                &reportParametersTask, tskIDLE_PRIORITY + 1, ucTaskStack3, &xCheckTask3 );
//    xTaskCreateStatic(vClassTask<UpdateParametersTask>, updateParametersTask->taskName, updateParametersTask->taskStackDepth,
//                &updateParametersTask, tskIDLE_PRIORITY + 1, ucTaskStack4, &xCheckTask4 );

    xTaskCreateStatic(vClassTask<HousekeepingTask>, housekeepingTask->taskName, housekeepingTask->taskStackDepth,
                      &housekeepingTask, configMAX_PRIORITIES - 1, ucTaskStack1, &xCheckTask1 );
//    xTaskCreate(vClassTask<AmbientTemperatureTask>, ambientTemperatureTask->taskName, ambientTemperatureTask->taskStackDepth,
//                &ambientTemperatureTask, tskIDLE_PRIORITY + 2, NULL);

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
    static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}
