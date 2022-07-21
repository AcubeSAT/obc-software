#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "TimeKeepingTask.hpp"
#include "HousekeepingTask.hpp"
#include "MCUTemperatureTask.hpp"
#include "UpdateParametersTask.hpp"
#include "TimeBasedSchedulingTask.hpp"
#include "AmbientTemperatureTask.hpp"
#include "UARTGatekeeperTask.hpp"
#include "WatchdogTask.hpp"
#include "CANTransmitTask.hpp"

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
    inline std::optional<UARTGatekeeperTask> uartGatekeeperTask;
    inline std::optional<WatchdogTask> watchdogTask;
    inline std::optional<CANTransmitTask> canTransmitTask;
}

#endif //OBC_SOFTWARE_TASKLIST_H
