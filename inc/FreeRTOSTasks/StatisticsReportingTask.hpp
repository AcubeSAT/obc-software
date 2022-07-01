#pragma once

#include "Task.hpp"
#include "semphr.h"

class StatisticsReportingTask : public Task {
public:
    /**
     * @see ParameterStatisticsService
     */
    void execute();

    StatisticsReportingTask() : Task("StatisticsReporting", nullptr, 2000) {}
};
