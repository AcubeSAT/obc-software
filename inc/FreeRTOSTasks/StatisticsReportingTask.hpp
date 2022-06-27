#pragma once

#include "Task.hpp"

class StatisticsReportingTask : public Task {
private:
    uint16_t delayMs = 1000;
public:
    /**
     * @see ParameterStatisticsService
     */
    void execute();

    StatisticsReportingTask() : Task("StatisticsReporting", nullptr, 2000) {}
};