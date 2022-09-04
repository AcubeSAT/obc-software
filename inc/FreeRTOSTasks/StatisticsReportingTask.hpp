#pragma once

#include "Task.hpp"
#include "TaskInitialization.hpp"

class StatisticsReportingTask : public Task {
public:
    /**
     * @see ParameterStatisticsService
     */
    void execute();

    const static inline uint16_t TaskStackDepth = 3000;

    StackType_t taskStack[TaskStackDepth];

    StatisticsReportingTask() : Task("StatisticsReporting") {}

    /**
     *
     * @brief Initialize the freeRTOS StatisticsReporting Task
     *
     */
    void createTask(){
        xTaskCreateStatic(vClassTask<StatisticsReportingTask>, this->TaskName,
                          StatisticsReportingTask::TaskStackDepth, this, tskIDLE_PRIORITY + 1,
                          this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<StatisticsReportingTask> statisticsReportingTask;
