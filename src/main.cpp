#include <Logger.hpp>
#include "main.h"
#include "SEGGER_RTT.h"
#include "ServicePool.hpp"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"

/**
 * @note This should not be considered a final main.cpp file and will be reverted.
 * Its purpose is just to test USART1 functionality.
 *
 * PIO_PIN_PB4 is the USART1 TX pin according to page 1140 of the microcontroller datasheet.
 * pinval should be toggling while sending a message,
 * however this implementation does not work at the moment.
 */

volatile uint8_t pinval = 0;
etl::string<17> usartData = "\r\n testing \r\n";

void xTask1Code(void *pvParameters) {
    while (true) {
        PIO_PinToggle(PIO_PIN_PA23);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
};

void xTask2Code(void *pvParameters) {
    while (true) {
//        pinval = PIO_PinRead(PIO_PIN_PA23);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
};

void xUartDMA(void *pvParameters) {
    while (true) {
        USART1_Write(usartData.data(), usartData.size());
        while (USART1_WriteIsBusy()) {
            pinval = PIO_PinRead(PIO_PIN_PB4);
            SEGGER_RTT_printf(0, "\r\nbusy\r\n");
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
};

extern "C" void main_cpp() {
    SYS_Initialize(NULL);
    USART1_Initialize();
    SEGGER_RTT_Init();
    EventReportService &eventReportService = Services.eventReport;
    eventReportService.lowSeverityAnomalyReport(EventReportService::LowSeverityUnknownEvent, "data");
    uint8_t lowSeverityEvents = eventReportService.lowSeverityEventCount; //Variable to check in ozone timeline

//    xTaskCreate(xTask1Code, "Task1", 100, NULL, tskIDLE_PRIORITY + 1, NULL);
//    xTaskCreate(xTask2Code, "Task2", 100, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(xUartDMA, "UartDMA", 100, NULL, tskIDLE_PRIORITY + 1, NULL);

    vTaskStartScheduler();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
