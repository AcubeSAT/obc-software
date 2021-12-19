#include "main.h"
#include "SEGGER_RTT.h"
#include "ServicePool.hpp"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "definitions.h"
#include <Logger.hpp>


void xTask1Code(void *pvParameters) {
    ParameterService &parameterService = Services.parameterManagement;
    float a = Services.parameterManagement.parametersArray[2].get().getValueAsDouble();
    int g = (int) a;
    SEGGER_RTT_printf(0, "%d\n", g);
    Message msg1(ParameterService::ServiceType, ParameterService::ParameterValuesReport, Message::TC, 1);
    msg1.appendHalfword((uint16_t) 2);
    msg1.appendHalfword((uint16_t) 2);
    msg1.appendHalfword((uint16_t) 3);
    Message msg2(ParameterService::ServiceType, ParameterService::SetParameterValues , Message::TC, 1);
    msg2.appendHalfword((uint16_t) 2);
    msg2.appendHalfword((uint16_t) 2);
    msg2.appendHalfword((uint16_t) 3);
    while (true) {
//        Services.parameterManagement.setParameters(msg2);
//        a = Services.parameterManagement.parametersArray[0].get().getValueAsDouble();
//        g = (int) a;
//        SEGGER_RTT_printf(0, "%d\n", g);
//        a = Services.parameterManagement.parametersArray[1].get().getValueAsDouble();
//        g = (int) a;
//        SEGGER_RTT_printf(0, "%d\n", g);
//        a = Services.parameterManagement.parametersArray[2].get().getValueAsDouble();
//        g = (int) a;
//        SEGGER_RTT_printf(0, "%d\n", g);
//        a = Services.parameterManagement.parametersArray[3].get().getValueAsDouble();
//        g = (int) a;
//        SEGGER_RTT_printf(0, "%d\n", g);
    }
};


extern "C" void main_cpp() {
    SEGGER_RTT_Init();
    SEGGER_RTT_printf(0, "test\n");
    EventReportService &eventReportService = Services.eventReport;
    eventReportService.lowSeverityAnomalyReport(EventReportService::LowSeverityUnknownEvent, "data");
    SEGGER_RTT_printf(0, "%i", eventReportService.lowSeverityEventCount);

    xTaskCreate(xTask1Code, "Task1", 100, NULL, tskIDLE_PRIORITY + 1, NULL);

    vTaskStartScheduler();
}
