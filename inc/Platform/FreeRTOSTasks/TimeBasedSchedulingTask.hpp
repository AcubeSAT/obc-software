#ifndef ECSS_SERVICES_TimeBasedSchedulingTask_HPP
#define ECSS_SERVICES_TimeBasedSchedulingTask_HPP

#include "Task.hpp"
#include "TimeBasedSchedulingService.hpp"

class TimeBasedSchedulingTask : public Task {
private:
    const uint16_t delayMs = 1000;
public:
    void execute();

    TimeBasedSchedulingTask(const char *taskName, TaskHandle_t taskHandle, const uint16_t taskStackDepth,
                    const uint16_t delayMs) : Task(taskName, taskHandle, taskStackDepth), delayMs(delayMs) {}
};

#endif
