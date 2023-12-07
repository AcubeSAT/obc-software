#include "InitializationTask.hpp"

void InitializationTask::execute() {
        initializeTasks();
        housekeepingTask.emplace();
        timeBasedSchedulingTask.emplace();
        statisticsReportingTask.emplace();
        tcHandlingTask.emplace();
        afec0HandlingTask.emplace();

        statisticsReportingTask->createTask();
        housekeepingTask->createTask();
        timeBasedSchedulingTask->createTask();
        tcHandlingTask->createTask();
        afec0HandlingTask->createTask();

        vTaskSuspend(NULL);
}