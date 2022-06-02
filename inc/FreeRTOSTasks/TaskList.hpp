#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "TimeKeepingTask.hpp"
#include "UartDMATask.hpp"
#include "HousekeepingTask.hpp"
#include "TemperatureTask.hpp"
#include "ReportParametersTask.hpp"
#include "UpdateParametersTask.hpp"

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
}

#endif //OBC_SOFTWARE_TASKLIST_H
