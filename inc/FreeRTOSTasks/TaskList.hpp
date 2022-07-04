#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "TimeKeepingTask.hpp"
#include "HousekeepingTask.hpp"
#include "MCUTemperatureTask.hpp"
#include "UpdateParametersTask.hpp"
#include "AmbientTemperatureTask.hpp"

/**
 * Storage of FreeRTOS task instances.
 */
namespace TaskList {
    inline std::optional<TimeKeepingTask> timeKeepingTask;
    inline std::optional<MCUTemperatureTask> mcuTemperatureTask;
    inline std::optional<HousekeepingTask> housekeepingTask;
    inline std::optional<UpdateParametersTask> updateParametersTask;
    inline std::optional<AmbientTemperatureTask> ambientTemperatureTask;
}

#endif //OBC_SOFTWARE_TASKLIST_H
