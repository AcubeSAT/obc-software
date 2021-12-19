#include <Logger.hpp>
#include "main.h"
#include "SEGGER_RTT.h"
#include "ServicePool.hpp"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"


volatile uint8_t pinval = 0;

void xTask1Code(void *pvParameters) {
    while (true) {
        PIO_PinToggle(PIO_PIN_PA23);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
};

void xTask2Code(void *pvParameters) {
    while (true) {
        pinval = PIO_PinRead(PIO_PIN_PA23);
        vTaskDelay(pdMS_TO_TICKS(500));
    }

};

extern "C" void main_cpp() {
    SYS_Initialize(NULL);

    SEGGER_RTT_Init();
    EventReportService &eventReportService = Services.eventReport;
    eventReportService.lowSeverityAnomalyReport(EventReportService::LowSeverityUnknownEvent, "data");
    uint8_t lowSeverityEvents = eventReportService.lowSeverityEventCount; //Variable to check in ozone timeline

    etl::string<3> logData = "log";
    Logger::log(Logger::notice, logData);
    xTaskCreate(xTask1Code, "Task1", 100, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(xTask2Code, "Task2", 100, NULL, tskIDLE_PRIORITY + 1, NULL);

    vTaskStartScheduler();

    while (true) {


        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
    }

    return;
}
