#ifndef ECSS_SERVICES_TimeBasedSchedulingTask_HPP
#define ECSS_SERVICES_TimeBasedSchedulingTask_HPP

#include "Task.hpp"

class TimeBasedSchedulingTask : public Task {
public:
    static StackType_t taskStack[configMINIMAL_STACK_SIZE * 4];

    void execute();

    TimeBasedSchedulingTask() : Task("TimeBasedSchedulingTask", nullptr, 4000) {}
};

#endif
