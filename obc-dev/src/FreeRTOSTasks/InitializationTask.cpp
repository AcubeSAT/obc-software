#include "InitializationTask.hpp"

void InitializationTask::execute() {
        initializeTasks();
        initializeAmbientTemperatureTask();
        housekeepingTask.emplace();
        timeBasedSchedulingTask.emplace();
        statisticsReportingTask.emplace();
        afec0HandlingTask.emplace();
        timeSyncTask.emplace();

        statisticsReportingTask->createTask();
        housekeepingTask->createTask();
        timeBasedSchedulingTask->createTask();
        afec0HandlingTask->createTask();
        timeSyncTask->createTask();

        vTaskSuspend(NULL);
}
