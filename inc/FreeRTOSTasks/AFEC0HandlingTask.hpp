#pragma once

#include "Task.hpp"
#include "queue.h"
#include "Peripheral_Definitions.hpp"

/**
 * FreeRTOS task for handling the conversion of the AFEC0 Peripheral channels.
 */
class AFEC0HandlingTask : public Task {
public:
    /**
     * This variable is used to store a task handle for a temperature sensor task.
     */
    inline static TaskHandle_t AFEC0HandlingTaskHandle = nullptr;

    void execute();

    AFEC0HandlingTask();

    void createTask() {
        AFEC0HandlingTaskHandle = xTaskCreateStatic(vClassTask < AFEC0HandlingTask > , this->TaskName,
                                                    AFEC0HandlingTask::TaskStackDepth, this, tskIDLE_PRIORITY + 2,
                                                    this->taskStack, &(this->taskBuffer));
    }

private:
    const uint16_t delayMs = 10000;

    const static inline uint16_t TaskStackDepth = 10000;

    StackType_t taskStack[TaskStackDepth];

    /**
     * This variable is used to store the maximum time the task should wait for the notification in ticks.
     * The number 1000ms was considered a good value arbitrarily
     */
    TickType_t maxDelay = pdMS_TO_TICKS(1000);

};

inline std::optional<AFEC0HandlingTask> afec0HandlingTask;
