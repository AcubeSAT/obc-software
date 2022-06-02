#ifndef ECSS_SERVICES_TimeBasedSchedulingTask_HPP
#define ECSS_SERVICES_TimeBasedSchedulingTask_HPP

#include "Task.hpp"
#include "TimeBasedSchedulingService.hpp"

class TimeBasedSchedulingTask : public Task {
private:
    const uint16_t delayMs = 1000;
public:
    void execute();

    TimeBasedSchedulingTask() : Task("TimeBasedSchedulingTask", nullptr, 2000) {}
};

#endif
