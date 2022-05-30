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

//static QueueHandle_t rxQueue;
//static uint16_t currentRXbyte = 0;
//static uint16_t currentReadLocation = 0;
//
//struct Buffer {
//    char message[10];
//};
//
//Buffer buffer1;
//
//void foo(void *) {
//    while (true) {
//        xQueueReceive(rxQueue, static_cast<void *>(&buffer1), (TickType_t) (1000));
//
////        xQueueReceiveFromISR(rxQueue, static_cast<void *>(&buffer2), &xHigherPriorityTaskWoken);
//
////        if (overRun) {
////            overRun = false;
////            LOG_ERROR << "RX too large message";
////        }
//
//        // Create a TC message and execute it.
//        Message mess(buffer1.message[1], buffer1.message[2], Message::TC, 1);
//        MessageParser::execute(mess);
////        cobsBuffer = COBSdecode<MaxInputSize>(reinterpret_cast<uint8_t*>(buffer2.message), MaxInputSize);
//
////        ECSSMessage ecss = MessageParser::parseECSSTC(reinterpret_cast<const uint8_t*>(cobsBuffer.c_str()));
////
////        LOG_INFO << "Received new [" << ecss.serviceType << "," << ecss.messageType << "] TC";
//
////        MessageParser::execute(ecss);
//    }
//}
//
//static BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//
//void ingress() {
//    if (currentRXbyte == 0) {
////            xQueueSend(rxQueue, static_cast<void *>(&buffer1), (TickType_t) (1000));
//        xQueueSendToBackFromISR(rxQueue, static_cast<void *>(&buffer1), &xHigherPriorityTaskWoken);
//        if (xHigherPriorityTaskWoken) {
//            /* Actual macro used here is port specific. */
//            taskYIELD();
////                taskYIELD_FROM_ISR ();
//        }
//        currentReadLocation = 0;
//        new(&(buffer1)) Buffer{};
//    } else {
////        if (currentReadLocation == MaxInputSize) {
////            overRun = true;
////            currentReadLocation = 0;
////        } else {
//        buffer1.message[currentReadLocation++] = currentRXbyte;
////        }
//    }
//}
//
//void initialiseInterrupt() {
//    rxQueue = xQueueCreate(10, sizeof(Message));
//
//    USART1_Read(&currentRXbyte, 1);
//
//    USART1_ReadCallbackRegister([](uintptr_t object) {
//        // This function is called whenever a single byte arrives
//
////        auto rxTask = reinterpret_cast<UARTRXTask *>(object); // Work-around through library API to pass object
//
//        if (USART1_ReadCountGet() == 0) {
//            // Some error occurred
//        } else {
////            ingress();
//        }
//
//        // Initiate next read
//        USART1_Read(&(currentRXbyte), 1);
//    }, reinterpret_cast<uintptr_t>(nullptr));
//}

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

//    initialiseInterrupt();

//    xTaskCreate(&foo, "FuckingKanavouras", 1000, nullptr, tskIDLE_PRIORITY + 1, nullptr);
    xTaskCreate(vClassTask<UARTRXTask>, uartRXtask->taskName, uartRXtask->taskStackDepth, &uartRXtask,
                tskIDLE_PRIORITY + 1, nullptr);
//    xTaskCreate(vClassTask<UartDMATask>, uartDMATask->taskName, uartDMATask->taskStackDepth,
//                &uartDMATask, tskIDLE_PRIORITY + 1, nullptr);
//    xTaskCreate(vClassTask<TimeKeepingTask>, timeKeepingTask->taskName, timeKeepingTask->taskStackDepth,
//                &timeKeepingTask, tskIDLE_PRIORITY + 4, nullptr);
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
