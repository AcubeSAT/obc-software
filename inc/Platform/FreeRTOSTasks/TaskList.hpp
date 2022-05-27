#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "TimeKeepingTask.hpp"
#include "UartDMATask.hpp"
#include "HousekeepingTask.hpp"
#include "TemperatureTask.hpp"
#include "ReportParametersTask.hpp"
#include "UpdateParametersTask.hpp"
#include "UARTRXTask.hpp"

namespace TaskList {
    static UartDMATask uartDMATask = UartDMATask("XUartDMA", NULL, 15000, 500);
    static TimeKeepingTask timeKeepingTask = TimeKeepingTask("TimeKeeping", NULL, 1000, 1100);
    static HousekeepingTask housekeepingTask = HousekeepingTask("Housekeeping", NULL, 2000);
    static TemperatureTask temperatureTask = TemperatureTask("TemperatureSensor", NULL, 1000, 7000);
    static ReportParametersTask reportParametersTask = ReportParametersTask("ParameterReporting", NULL, 1000, 11, 1000);
    static UpdateParametersTask updateParametersTask = UpdateParametersTask("ParameterUpdating", NULL, 2000, 3000);
//    static UARTRXTask uartRXTask = UARTRXTask();
}

#endif //OBC_SOFTWARE_TASKLIST_H
