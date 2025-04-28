#include "ECSS_Configuration.hpp"
#include "FreeRTOS.h"
#include "TimeBasedSchedulingTask.hpp"

#ifdef SERVICE_TIMESCHEDULING

#include "Services/TimeBasedSchedulingService.hpp"


void TimeBasedSchedulingService::notifyNewActivityAddition() {
    if (scheduledActivities.size() >= 1) {
        xTaskNotify(timeBasedSchedulingTask->taskHandle, 0, eNoAction);
    }
}

#endif