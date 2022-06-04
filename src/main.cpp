#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "BootCounter.hpp"
#include "SEGGER_RTT.h"
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

    uartRXtask.emplace();
//    uartDMATask.emplace();
//    timeKeepingTask.emplace();
//    housekeepingTask.emplace();
//    temperatureTask.emplace();
//    reportParametersTask.emplace();
//    updateParametersTask.emplace();

    xTaskCreate(vClassTask<UARTRXTask>, uartRXtask->taskName, uartRXtask->taskStackDepth, &uartRXtask,
                tskIDLE_PRIORITY + 1, nullptr);
//    xTaskCreate(vClassTask<UartDMATask>, uartDMATask->taskName, uartDMATask->taskStackDepth,
//                &uartDMATask, tskIDLE_PRIORITY + 1, nullptr);
//    xTaskCreate(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
//                &timeKeepingTask, tskIDLE_PRIORITY + 2, nullptr);
//    xTaskCreate(vClassTask<TemperatureTask>, temperatureTask->taskName, temperatureTask->taskStackDepth,
//                &temperatureTask, tskIDLE_PRIORITY + 1, nullptr);
//    xTaskCreate(vClassTask<ReportParametersTask>, reportParametersTask->taskName, reportParametersTask->taskStackDepth,
//                &reportParametersTask, tskIDLE_PRIORITY + 1, nullptr);
//    xTaskCreate(vClassTask<UpdateParametersTask>, updateParametersTask->taskName, updateParametersTask->taskStackDepth,
//                &updateParametersTask, tskIDLE_PRIORITY + 1, nullptr);
//    xTaskCreate(vClassTask<HousekeepingTask>, housekeepingTask->taskName, housekeepingTask->taskStackDepth,
//                &housekeepingTask, tskIDLE_PRIORITY + 1, nullptr);

    vTaskStartScheduler();

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }
#pragma clang diagnostic pop

    return;
}
