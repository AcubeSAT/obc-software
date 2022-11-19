#pragma once

#include "Task.hpp"
#include "LCLDefinitions.hpp"
#include "HousekeepingTask.hpp"
#include "UpdateParametersTask.hpp"
#include "TimeBasedSchedulingTask.hpp"
#include "StatisticsReportingTask.hpp"
#include "CANTransmitTask.hpp"
#include "TCHandlingTask.hpp"
#include "TaskInitialization.hpp"

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

    InitialisationTask() : Task("InitialisationTask") {}

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        taskHandle = xTaskCreateStatic(vClassTask < InitialisationTask > , this->TaskName,
                                       InitialisationTask::TaskStackDepth,
                                       this, configMAX_PRIORITIES, this->taskStack,
                                       &(this->taskBuffer));
    }

    /**
     *
     */
    void initialisePeripherals();

    /**
     *
     */
    void initialisePeriodicTasks();

};

inline std::optional<InitialisationTask> initialisationTask;
