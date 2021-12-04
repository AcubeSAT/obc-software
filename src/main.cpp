#include "main.h"
#include "SEGGER_RTT.h"
#include "ServicePool.hpp"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"                // SYS function prototypes


volatile uint8_t pinval = 0;
volatile int xTask1 = 1;

void xTask1Code(void *pvParameters) {
    while (true) {
        PIO_PinToggle(PIO_PIN_PA23);
        vTaskDelay(pdMS_TO_TICKS(500));
    }

};

void xTask2Code(void *pvParameters) {
    for (;;) {
        pinval = PIO_PinRead(PIO_PIN_PA23);
        vTaskDelay(pdMS_TO_TICKS(500));
    }

};

extern "C" void main_cpp() {
    SEGGER_RTT_Init();
    SEGGER_RTT_printf(0, "test");
    EventReportService &eventReportService = Services.eventReport;
    eventReportService.lowSeverityAnomalyReport(EventReportService::LowSeverityUnknownEvent, "data");
    SEGGER_RTT_printf(0, "%i", eventReportService.lowSeverityEventCount);
    xTaskCreate(xTask1Code, "Task1", 100, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(xTask2Code, "Task2", 100, NULL, tskIDLE_PRIORITY + 1, NULL);
    vTaskStartScheduler();
}
