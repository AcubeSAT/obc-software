#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "TimeKeepingTask.hpp"
#include "UartDMATask.hpp"
#include "HousekeepingTask.hpp"
#include "TemperatureTask.hpp"
#include "ReportParametersTask.hpp"
#include "UpdateParametersTask.hpp"
#include "RM3100Task.hpp"

/**
 * Storage of FreeRTOS task instances.
 */
namespace TaskList {
    inline std::optional<UartDMATask> uartDMATask;
    inline std::optional<TimeKeepingTask> timeKeepingTask;
    inline std::optional<TemperatureTask> temperatureTask;
    inline std::optional<HousekeepingTask> housekeepingTask;
    inline std::optional<ReportParametersTask> reportParametersTask;
    inline std::optional<UpdateParametersTask> updateParametersTask;
    inline std::optional<RM3100Task> rm3100Task;
}

#endif //OBC_SOFTWARE_TASKLIST_H
