#include "InitializationTask.hpp"

void InitializationTask::execute() {
        initializeTasks();
        initializeAmbientTemperatureTask();
        housekeepingTask.emplace();
        timeBasedSchedulingTask.emplace();
        statisticsReportingTask.emplace();
        afec0HandlingTask.emplace();
        timeSyncTask.emplace();
        requestParamADCSTask.emplace();

        statisticsReportingTask->createTask();
        housekeepingTask->createTask();
        timeBasedSchedulingTask->createTask();
        afec0HandlingTask->createTask();
        timeSyncTask->createTask();
        requestParamADCSTask->createTask();

        vTaskSuspend(NULL);
}