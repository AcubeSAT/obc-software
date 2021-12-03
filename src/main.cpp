#include "main.h"
#include "SEGGER_RTT.h"
#include "ServicePool.hpp"

extern "C" void main_cpp() {
    SEGGER_RTT_Init();
    SEGGER_RTT_printf(0, "test");
    EventReportService &eventReportService = Services.eventReport;
    eventReportService.lowSeverityAnomalyReport(EventReportService::LowSeverityUnknownEvent, "data");
    SEGGER_RTT_printf(0, "%i", eventReportService.lowSeverityEventCount);
}
