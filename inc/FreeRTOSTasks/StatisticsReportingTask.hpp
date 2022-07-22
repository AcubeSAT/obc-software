#pragma once

#include "Task.hpp"

class StatisticsReportingTask : public Task {
public:
    /**
     * @see ParameterStatisticsService
     */
    void execute();

    const static inline uint16_t taskStackDepth = 3000;

    StackType_t taskStack[taskStackDepth];

    StatisticsReportingTask() : Task("StatisticsReporting") {}
};
