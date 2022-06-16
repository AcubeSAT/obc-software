#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "TimeKeepingTask.hpp"
#include "UartDMATask.hpp"
#include "HousekeepingTask.hpp"
#include "MCUTemperatureTask.hpp"
#include "ReportParametersTask.hpp"
#include "UpdateParametersTask.hpp"
<<<<<<< HEAD
#include "TimeBasedSchedulingTask.hpp"

=======
#include "AmbientTemperatureTask.hpp"
#include "WatchdogTask.hpp"
>>>>>>> master
/**
 * Storage of FreeRTOS task instances.
 */
namespace TaskList {
    inline std::optional<UartDMATask> uartDMATask;
    inline std::optional<TimeKeepingTask> timeKeepingTask;
    inline std::optional<MCUTemperatureTask> mcuTemperatureTask;
    inline std::optional<HousekeepingTask> housekeepingTask;
    inline std::optional<ReportParametersTask> reportParametersTask;
    inline std::optional<UpdateParametersTask> updateParametersTask;
    inline std::optional<TimeBasedSchedulingTask> timeBasedSchedulingTask;
    inline std::optional<AmbientTemperatureTask> ambientTemperatureTask;
    inline std::optional<WatchdogTask> watchdogTask;
}

#endif //OBC_SOFTWARE_TASKLIST_H
