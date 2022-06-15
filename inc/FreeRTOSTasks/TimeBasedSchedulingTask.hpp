#ifndef ECSS_SERVICES_TimeBasedSchedulingTask_HPP
#define ECSS_SERVICES_TimeBasedSchedulingTask_HPP

#include "Task.hpp"

class TimeBasedSchedulingTask : public Task {
public:
    void execute();

    TimeBasedSchedulingTask() : Task("TimeBasedSchedulingTask", nullptr, 3000) {}
};

#endif
