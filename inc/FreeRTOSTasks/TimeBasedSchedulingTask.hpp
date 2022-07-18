#ifndef ECSS_SERVICES_TimeBasedSchedulingTask_HPP
#define ECSS_SERVICES_TimeBasedSchedulingTask_HPP

#include "Task.hpp"

class TimeBasedSchedulingTask : public Task {
public:
    const static inline uint16_t taskStackDepth = 4000;

    StackType_t taskStack[taskStackDepth];

    void execute();

    TimeBasedSchedulingTask() : Task("TimeBasedSchedulingTask", nullptr, taskStackDepth) {}
};

#endif
