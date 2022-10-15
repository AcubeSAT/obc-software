#ifndef ECSS_SERVICES_TimeBasedSchedulingTask_HPP
#define ECSS_SERVICES_TimeBasedSchedulingTask_HPP

#include "Task.hpp"

class TimeBasedSchedulingTask : public Task {
public:
    const static inline uint16_t TaskStackDepth = 2500;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    TimeBasedSchedulingTask() : Task("TimeBasedSchedulingTask") {}

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        this->taskHandle = xTaskCreateStatic(vClassTask<TimeBasedSchedulingTask>,
                                             this->TaskName,
                                             TimeBasedSchedulingTask::TaskStackDepth,
                                             this, tskIDLE_PRIORITY + 2,
                                             this->taskStack,
                                             &(this->taskBuffer));
    }
};

inline std::optional<TimeBasedSchedulingTask> timeBasedSchedulingTask;

#endif
