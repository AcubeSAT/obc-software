#include "InitializationTask.hpp"
#include "FlashTestTask.hpp"

void InitializationTask::execute() {
        initializeTasks();
        flashTestTask.emplace();

//        timeBasedSchedulingTask.emplace();
//        statisticsReportingTask.emplace();
//        afec0HandlingTask.emplace();

//        statisticsReportingTask->createTask();
       housekeepingTask->createTask();
//        timeBasedSchedulingTask->createTask();
//        afec0HandlingTask->createTask();
    flashTestTask->execute();


        vTaskSuspend(NULL);
}