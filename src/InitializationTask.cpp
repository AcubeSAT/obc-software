//
// Created by giorgos on 5/29/23.
//
#include "InitializationTask.hpp"

void InitializationTask::execute()
{
    initializeTasks();

    housekeepingTask.emplace();
    timeBasedSchedulingTask.emplace();
    statisticsReportingTask.emplace();
    tcHandlingTask.emplace();

    statisticsReportingTask->createTask();
    housekeepingTask->createTask();
    timeBasedSchedulingTask->createTask();
    tcHandlingTask->createTask();

    vTaskSuspend(reinterpret_cast<TaskHandle_t>(initializeTasks));
}