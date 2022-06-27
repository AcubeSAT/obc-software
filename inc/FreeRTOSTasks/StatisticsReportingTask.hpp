#pragma once

#include "Task.hpp"

class StatisticsReportingTask : public Task {
public:
    /**
     * @see ParameterStatisticsService
     */
    void execute();

    StatisticsReportingTask() : Task("StatisticsReporting", nullptr, 2000) {}
};