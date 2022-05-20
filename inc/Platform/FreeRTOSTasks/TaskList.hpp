#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "XTimeKeepingTask.hpp"
#include "XUartDMATask.hpp"
#include "HousekeepingTask.hpp"
#include "TemperatureTask.hpp"
#include "ReportParametersTask.hpp"
#include "UpdateParametersTask.hpp"

namespace TaskList {
    static UartDMATask uartDMATask = UartDMATask("XUartDMA", nullptr, 10000, 900);
    static TimeKeepingTask timeKeepingTask = TimeKeepingTask("TimeKeeping", nullptr, 1000, 1100);
    static HousekeepingTask housekeepingTask = HousekeepingTask("Housekeeping", nullptr, 2000);
    static TemperatureTask temperatureTask = TemperatureTask("TemperatureSensor", nullptr, 1000, 10000);
    static ReportParametersTask reportParametersTask = ReportParametersTask("ParameterReporting", nullptr, 2000, 11, 1000);
    static UpdateParametersTask updateParametersTask = UpdateParametersTask("ParameterUpdating", nullptr, 2000, 3000);
}

#endif //OBC_SOFTWARE_TASKLIST_H
