#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "TimeKeepingTask.hpp"
#include "HousekeepingTask.hpp"
#include "MCUTemperatureTask.hpp"
#include "UpdateParametersTask.hpp"
#include "TimeBasedSchedulingTask.hpp"
#include "AmbientTemperatureTask.hpp"
#include "UARTGatekeeper.hpp"
#include "WatchdogTask.hpp"

/**
 * Storage of FreeRTOS task instances.
 */
namespace TaskList {
    inline std::optional<TimeKeepingTask> timeKeepingTask;
    inline std::optional<MCUTemperatureTask> mcuTemperatureTask;
    inline std::optional<HousekeepingTask> housekeepingTask;
    inline std::optional<UpdateParametersTask> updateParametersTask;
    inline std::optional<TimeBasedSchedulingTask> timeBasedSchedulingTask;
    inline std::optional<AmbientTemperatureTask> ambientTemperatureTask;
    inline std::optional<UARTGatekeeper> uartGatekeeper;
    inline std::optional<WatchdogTask> watchdogTask;
}

#endif //OBC_SOFTWARE_TASKLIST_H
