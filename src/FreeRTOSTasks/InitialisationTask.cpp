#include "InitialisationTask.hpp"

void InitialisationTask::initialisePeripherals() {
    LCLDefinitions::enableAllLCLs();
}

void InitialisationTask::initialisePeriodicTasks() {
    initializeTasks();

    housekeepingTask.emplace();
    timeBasedSchedulingTask.emplace();
    statisticsReportingTask.emplace();
    updateParametersTask.emplace();
    canTransmitTask.emplace();
    tcHandlingTask.emplace();

    updateParametersTask->createTask();
    statisticsReportingTask->createTask();
    housekeepingTask->createTask();
    timeBasedSchedulingTask->createTask();
    tcHandlingTask->createTask();
    canTransmitTask->createTask();
}

void InitialisationTask::execute() {
    initialisePeripherals();
    initialisePeriodicTasks();
}
