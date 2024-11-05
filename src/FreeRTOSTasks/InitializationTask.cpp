#include "InitializationTask.hpp"

#include "TimeSyncTask.hpp"

void InitializationTask::execute() {
        initializeTasks();
        housekeepingTask.emplace();
        timeBasedSchedulingTask.emplace();
        statisticsReportingTask.emplace();
        afec0HandlingTask.emplace();
        TimeSyncTask.emplace();

        statisticsReportingTask->createTask();
        housekeepingTask->createTask();
        timeBasedSchedulingTask->createTask();
        afec0HandlingTask->createTask();
        TimeSyncTask->createTask();

        vTaskSuspend(NULL);
}
