#ifndef OBC_SOFTWARE_TASKLIST_H
#define OBC_SOFTWARE_TASKLIST_H

#include "TimeKeepingTask.hpp"
#include "UartDMATask.hpp"
#include "HousekeepingTask.hpp"
#include "MCUTemperatureTask.hpp"
#include "ReportParametersTask.hpp"
#include "UpdateParametersTask.hpp"
#include "AmbientTemperatureTask.hpp"
#include "UARTGatekeeper.hpp"
#include "WatchdogTask.hpp"
#include "StatisticsReportingTask.hpp"

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
    inline std::optional<AmbientTemperatureTask> ambientTemperatureTask;
    inline std::optional<UARTGatekeeper> uartGatekeeper;
    inline std::optional<WatchdogTask> watchdogTask;
    inline std::optional<StatisticsReportingTask> statisticsReportingTask;
}

#endif //OBC_SOFTWARE_TASKLIST_H
