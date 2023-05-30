
#include "InitializationTask.hpp"

void InitializationTask::execute() {
        initializeTasks();
        housekeepingTask.emplace();
        timeBasedSchedulingTask.emplace();
        statisticsReportingTask.emplace();
        tcHandlingTask.emplace();

        statisticsReportingTask->createTask();
        housekeepingTask->createTask();
        timeBasedSchedulingTask->createTask();
        tcHandlingTask->createTask();

        vTaskSuspend(NULL);

        UBaseType_t uxHighWaterMark;
        uxHighWaterMark = uxTaskGetStackHighWaterMark(NULL);
        etl::string<30> mystring = "High Water Mark:";
        etl::to_string(uxHighWaterMark, mystring, true);
        LOG_DEBUG << mystring.data();

}