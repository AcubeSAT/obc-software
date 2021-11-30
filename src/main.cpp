#include "main.h"
#include "Services/EventReportService.hpp"
#include "SEGGER_RTT.h"

extern "C" void main_cpp() {
    EventReportService eventReportService = EventReportService();
    const char eventReportData[] = "HelloWorld";
    eventReportService.lowSeverityAnomalyReport(EventReportService::LowSeverityUnknownEvent, eventReportData);
    SEGGER_RTT_printf(0, "test");
}
