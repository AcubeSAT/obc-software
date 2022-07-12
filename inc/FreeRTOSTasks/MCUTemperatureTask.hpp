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
    static StackType_t taskStack[configMINIMAL_STACK_SIZE * 1];

    void execute();

    MCUTemperatureTask() : Task("MCUTemperatureSensor", nullptr, 1000) {}
};

#endif
