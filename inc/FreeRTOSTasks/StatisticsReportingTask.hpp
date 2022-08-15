#pragma once

#include "Task.hpp"

class StatisticsReportingTask : public Task {
public:
    /**
     * @see ParameterStatisticsService
     */
    void execute();

    const static inline uint16_t TaskStackDepth = 3000;

    StackType_t taskStack[TaskStackDepth];

    StatisticsReportingTask() : Task("StatisticsReporting") {}
};

inline std::optional<StatisticsReportingTask> statisticsReportingTask;
