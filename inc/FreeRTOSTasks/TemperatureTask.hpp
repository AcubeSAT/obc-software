#ifndef OBC_SOFTWARE_TEMPERATURETASK_HPP
#define OBC_SOFTWARE_TEMPERATURETASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task for periodically printing the value of the internal temperature sensor.
 */
class TemperatureTask : public Task {
private:
    const uint16_t delayMs = 10000;
public:
    void execute();

    TemperatureTask() : Task("TemperatureSensor", nullptr, 1000) {}
};

#endif
