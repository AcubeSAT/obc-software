#include "InitializationTask.hpp"

void InitializationTask::execute() {
        initializeTasks();
        housekeepingTask.emplace();
        timeBasedSchedulingTask.emplace();
        statisticsReportingTask.emplace();
        afec0HandlingTask.emplace();
        timeSyncTask.emplace();
        timeRequestUponResetTask.emplace();

        statisticsReportingTask->createTask();
        housekeepingTask->createTask();
        timeBasedSchedulingTask->createTask();
        afec0HandlingTask->createTask();
        timeSyncTask->createTask();
        timeRequestUponResetTask->createTask();

        vTaskSuspend(NULL);
}
