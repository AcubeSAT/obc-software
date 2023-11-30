#include "InitializationTask.hpp"

void InitializationTask::execute() {
        initializeTasks();
        housekeepingTask.emplace();
        timeBasedSchedulingTask.emplace();
        statisticsReportingTask.emplace();

        statisticsReportingTask->createTask();
        housekeepingTask->createTask();
        timeBasedSchedulingTask->createTask();

        vTaskSuspend(NULL);
}