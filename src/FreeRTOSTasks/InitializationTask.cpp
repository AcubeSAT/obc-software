#include "InitializationTask.hpp"

void InitializationTask::execute() {
        initializeTasks();
        heaterTask.emplace();
        housekeepingTask.emplace();
        timeBasedSchedulingTask.emplace();
        statisticsReportingTask.emplace();
        afec0HandlingTask.emplace();

        statisticsReportingTask->createTask();
        heaterTask->createTask();
        housekeepingTask->createTask();
        timeBasedSchedulingTask->createTask();
        afec0HandlingTask->createTask();


        vTaskSuspend(NULL);
}