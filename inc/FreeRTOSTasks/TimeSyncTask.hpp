#pragma once

#include "Task.hpp"

class TimeSyncTask : public Task {
private:

public:
    const static inline uint16_t TaskStackDepth = 2300;

    StackType_t taskStack[TaskStackDepth];

    void execute();


    TimeSyncTask() : Task("TimeSyncTask") {}

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        xTaskCreateStatic(vClassTask < TimeSyncTask > , this->TaskName, TimeSyncTask::TaskStackDepth, this,
                         tskIDLE_PRIORITY+1, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<TimeSyncTask> TimeSyncTask;