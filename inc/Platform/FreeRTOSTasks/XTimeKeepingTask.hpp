#ifndef ECSS_SERVICES_XTIMEKEEPINGTASK_HPP
#define ECSS_SERVICES_XTIMEKEEPINGTASK_HPP

#include "Task.hpp"
#include "RTCHelper.hpp"

class XTimeKeepingTask : public Task {
private:
    const uint16_t delayMs = 1000;
public:
    /**
     * Keeps track of time, updating the time-related parameters.
     */
    void execute() override;

    XTimeKeepingTask(const char *taskName, TaskHandle_t taskHandle, const uint16_t taskStackDepth,
                     const uint16_t delayMs) : Task(taskName, taskHandle, taskStackDepth), delayMs(delayMs) {}
};

#endif