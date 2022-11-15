#pragma once

#include "Task.hpp"

/**
 * FreeRTOS task to execute the proper initialisations.
 * Runs before all other tasks as soon as the scheduler starts.
 */
class InitialisationTask : public Task {
public:
    const static inline uint16_t TaskStackDepth = 2000;

    StackType_t taskStack[TaskStackDepth];

    /**
      * @see HousekeepingService
      */
    void execute();

    InitialisationTask() : Task("Housekeeping") {}

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        taskHandle = xTaskCreateStatic(vClassTask<InitialisationTask>, this->TaskName,
                                       InitialisationTask::TaskStackDepth,
                          this, configMAX_PRIORITIES, this->taskStack,
                          &(this->taskBuffer));
    }

};

inline std::optional<InitialisationTask> initialisationTask;
