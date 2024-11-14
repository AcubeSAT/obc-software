#pragma once

#include "Task.hpp"
#include  "ApplicationLayer.hpp"

class TimeSyncTask : public Task {
private:
    bool timeRequested = false;

public:
    const int TimeSyncPeriod = 10000;

    const static inline uint16_t TaskStackDepth = 2300;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    TimeSyncTask() : Task("TimeSyncTask") {
    }

    void setTimeRequested(bool requested) {
        timeRequested = requested;
    }

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        xTaskCreateStatic(vClassTask<TimeSyncTask>, this->TaskName, TimeSyncTask::TaskStackDepth, this,
                          tskIDLE_PRIORITY, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<TimeSyncTask> timeSyncTask;
