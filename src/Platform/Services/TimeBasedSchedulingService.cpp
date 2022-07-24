#include "ECSS_Configuration.hpp"
#include "FreeRTOS.h"
#include "TaskList.hpp"

#ifdef SERVICE_TIMESCHEDULING

#include "Services/TimeBasedSchedulingService.hpp"

void TimeBasedSchedulingService::notifyNewActivityAddition() {
    if (scheduledActivities.size() >= 1) {
        xTaskNotify(TaskList::timeBasedSchedulingTask->taskHandle, 0, eNoAction);
    }
}

#endif