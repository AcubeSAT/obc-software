#pragma once

#include "Task.hpp"

/**
 * FreeRTOS task for periodically printing the value of the internal temperature sensor.
 */
class MCUTemperatureTask : public Task {
private:
    const uint16_t delayMs = 10000;

    const static inline uint16_t TaskStackDepth = 1000;

    StackType_t taskStack[TaskStackDepth];

public:
    void execute();

    MCUTemperatureTask() : Task("MCUTemperatureSensor") {}

    void createTask() {
        xTaskCreateStatic(vClassTask<MCUTemperatureTask>, this->TaskName, MCUTemperatureTask::TaskStackDepth, this,
                          tskIDLE_PRIORITY + 2, this->taskStack, &(this->taskBuffer));
    }

};

inline std::optional<MCUTemperatureTask> mcuTemperatureTask;
