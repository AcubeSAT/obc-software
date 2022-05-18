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

extern "C" void main_cpp() {
    using namespace TaskList;

    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();

    xTaskCreate(Task::vClassTask, xUartDMATask.taskName, xUartDMATask.taskStackDepth,
                &xUartDMATask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, xTimeKeepingTask.taskName, xTimeKeepingTask.taskStackDepth,
                &xTimeKeepingTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, temperatureTask.taskName, temperatureTask.taskStackDepth,
                &temperatureTask, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(Task::vClassTask, reportParametersTask.taskName, reportParametersTask.taskStackDepth,
                &reportParametersTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, updateParametersTask.taskName, updateParametersTask.taskStackDepth,
                &updateParametersTask, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(Task::vClassTask, housekeepingTask.taskName, housekeepingTask.taskStackDepth,
                &housekeepingTask, tskIDLE_PRIORITY + 1, NULL);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
