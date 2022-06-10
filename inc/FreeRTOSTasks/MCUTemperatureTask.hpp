#ifndef OBC_SOFTWARE_MCUTEMPERATURETASK_HPP
#define OBC_SOFTWARE_MCUTEMPERATURETASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task for periodically printing the value of the internal temperature sensor.
 */
class MCUTemperatureTask : public Task {
private:
    const uint16_t delayMs = 10000;
public:
    void execute();

    MCUTemperatureTask() : Task("MCUTemperatureSensor", nullptr, 1000) {}
};

#endif
