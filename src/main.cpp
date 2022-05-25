#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include "OBC_Definitions.hpp"
#include "FreeRTOSTasks.hpp"
#include "BootCounter.hpp"
#include "SEGGER_RTT.h"
#include "UARTRXTask.hpp"
#include "UARTTask.hpp"

/**
 * Just calls the operator() function of a task
 * @param pvParameters Pointer to object of type Task
 */
template<class Task>
static void vClassTask(void *pvParameters) {
    (static_cast<Task *>(pvParameters))->operator()();
}

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
    SEGGER_RTT_Init();
    BootCounter::incrementBootCounter();
    uartTask.emplace();
    uartRXtask.emplace();

//    xTaskCreate(vClassTask<UARTTask>, "UART_Tx", 3000, &*uartTask, tskIDLE_PRIORITY + 1, nullptr);
    xTaskCreate(vClassTask<UARTRXTask>, "UART_Rx", 6000, &*uartRXtask, tskIDLE_PRIORITY + 1, nullptr);

//    const char *taskName = "Task1";
//    xTaskCreate(FreeRTOSTasks::reportParameters, taskName, 2000,
//                NULL, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::updateParameters, "Task2", 2000,
//                &taskName, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::xUartDMA, "UartDMA", 10000,
//                NULL, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::xTimeKeeping, "timeKeeping", 1000,
//                NULL, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::housekeeping, "Housekeeping", 2000,
//                NULL, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(FreeRTOSTasks::temperatureTask, "Temperature", 1000,
//                NULL, tskIDLE_PRIORITY + 2, NULL);
    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
