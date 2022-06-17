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
#define STACK_SIZE 200



extern "C" void main_cpp() {
    using namespace TaskList;

    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();
// Structure that will hold the TCB of the task being created.
    StaticTask_t xTaskBuffer;
// Buffer that the task being created will use as its stack.  Note this is
// an array of StackType_t variables.  The size of StackType_t is dependent on
// the RTOS port.
    StackType_t xStack[ STACK_SIZE ];
    uartDMATask.emplace();
    mcuTemperatureTask.emplace();
    timeKeepingTask.emplace();
    housekeepingTask.emplace();
    reportParametersTask.emplace();
    updateParametersTask.emplace();
    ambientTemperatureTask.emplace();

//    xTaskCreateStatic(vClassTask<UartDMATask>, uartDMATask->taskName, uartDMATask->taskStackDepth,
//                &uartDMATask, tskIDLE_PRIORITY + 1,     xStack,          // Array to use as the task's stack.
//                      &xTaskBuffer );
//    xTaskCreate(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
//                &timeKeepingTask, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(vClassTask<MCUTemperatureTask>, mcuTemperatureTask->taskName, mcuTemperatureTask->taskStackDepth,
//                &mcuTemperatureTask, tskIDLE_PRIORITY + 2, NULL);
//    xTaskCreate(vClassTask<ReportParametersTask>, reportParametersTask->taskName, reportParametersTask->taskStackDepth,
//                &reportParametersTask, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(vClassTask<UpdateParametersTask>, updateParametersTask->taskName, updateParametersTask->taskStackDepth,
//                &updateParametersTask, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreateStatic(vClassTask<HousekeepingTask>, housekeepingTask->taskName, STACK_SIZE,
//                &housekeepingTask, tskIDLE_PRIORITY + 1,xStack,          // Array to use as the task's stack.
//                      &xTaskBuffer );
    xTaskCreate(vClassTask<HousekeepingTask>, housekeepingTask->taskName, STACK_SIZE,
                &housekeepingTask, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(vClassTask<AmbientTemperatureTask>, ambientTemperatureTask->taskName, ambientTemperatureTask->taskStackDepth,
//                &ambientTemperatureTask, tskIDLE_PRIORITY + 2, NULL);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
