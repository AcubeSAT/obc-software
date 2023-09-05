#pragma once

#include "Task.hpp"

class WatchdogTask : public Task {
private:
    /**
     * The delay in milliseconds between each watchdog reset. It is set to 14000ms, since the
     * maximum timeout is 16000ms, so the timer needs to clear before the next reset.
     * @see config/default/peripheral/wdt.c for the specific configuration.
     * Do not change this value, without also modifying the value in Harmony configurator.
     */
    const uint16_t WatchdogWindow = 14000;

    const static inline uint16_t TaskStackDepth = 1000;

    StackType_t taskStack[TaskStackDepth];

public:
    void execute();

    WatchdogTask() : Task("Watchdog") {}

    void createTask() {
        xTaskCreateStatic(vClassTask<WatchdogTask>, this->TaskName, WatchdogTask::TaskStackDepth, this,
                          tskIDLE_PRIORITY, this->taskStack, &(this->taskBuffer));
    }

};

inline std::optional<WatchdogTask> watchdogTask;

