#pragma once

#include "Task.hpp"
#include "ApplicationLayer.hpp"

class TimeSyncTask : public Task {
private:
    bool timeRequested = false;

public:
    const int TimeSyncPeriod = 10000;

    const static inline uint16_t TaskStackDepth = 800;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    TimeSyncTask() : Task("TimeSyncTask") {
    }

    void setTimeRequested(bool timeRequested) {
        this->timeRequested = timeRequested;
    }

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        this->taskHandle = xTaskCreateStatic(vClassTask<TimeSyncTask>, this->TaskName, TimeSyncTask::TaskStackDepth, this,
                          tskIDLE_PRIORITY, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<TimeSyncTask> timeSyncTask;
