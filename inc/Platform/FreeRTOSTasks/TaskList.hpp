#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "XTimeKeepingTask.hpp"
#include "XUartDMATask.hpp"
#include "HousekeepingTask.hpp"
#include "TemperatureTask.hpp"
#include "ReportParametersTask.hpp"
#include "UpdateParametersTask.hpp"

namespace TaskList {
    static UartDMATask uartDMATask = UartDMATask("XUartDMA", NULL, 15000, 500);
    static TimeKeepingTask timeKeepingTask = TimeKeepingTask("TimeKeeping", NULL, 1000, 1100);
    static HousekeepingTask housekeepingTask = HousekeepingTask("Housekeeping", NULL, 2000);
    static TemperatureTask temperatureTask = TemperatureTask("TemperatureSensor", NULL, 1000, 7000);
    static ReportParametersTask reportParametersTask = ReportParametersTask("ParameterReporting", NULL, 2000, 11, 1000);
    static UpdateParametersTask updateParametersTask = UpdateParametersTask("ParameterUpdating", NULL, 2000, 3000);
}

#endif //OBC_SOFTWARE_TASKLIST_H
