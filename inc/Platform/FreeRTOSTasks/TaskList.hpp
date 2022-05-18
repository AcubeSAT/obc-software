#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "FreeRTOSTasks/XTimeKeepingTask.hpp"
#include "FreeRTOSTasks/XUartDMATask.hpp"
#include "FreeRTOSTasks/HousekeepingTask.hpp"
#include "FreeRTOSTasks/TemperatureTask.hpp"
#include "FreeRTOSTasks/ReportParametersTask.hpp"
#include "FreeRTOSTasks/UpdateParametersTask.hpp"

namespace TaskList {
    static XUartDMATask xUartDMATask = XUartDMATask("XUartDMA", NULL, 10000, 900);
    static XTimeKeepingTask xTimeKeepingTask = XTimeKeepingTask("TimeKeeping", NULL, 1000, 1100);
    static HousekeepingTask housekeepingTask = HousekeepingTask("Housekeeping", NULL, 2000);
    static TemperatureTask temperatureTask = TemperatureTask("TemperatureSensor", NULL, 1000, 10000);
    static ReportParametersTask reportParametersTask = ReportParametersTask("ParameterReporting", NULL, 2000, 11, 1000);
    static UpdateParametersTask updateParametersTask = UpdateParametersTask("ParameterUpdating", NULL, 2000, 3000);
}

#endif //OBC_SOFTWARE_TASKLIST_H
