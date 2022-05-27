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
    static std::optional<UartDMATask> uartDMATask;
    static std::optional<TimeKeepingTask> timeKeepingTask;
    static std::optional<HousekeepingTask> housekeepingTask;
    static std::optional<TemperatureTask> temperatureTask;
    static std::optional<ReportParametersTask> reportParametersTask;
    static std::optional<UpdateParametersTask> updateParametersTask;
    static std::optional<UARTRXTask> uartRXtask;
}

#endif //OBC_SOFTWARE_TASKLIST_H
