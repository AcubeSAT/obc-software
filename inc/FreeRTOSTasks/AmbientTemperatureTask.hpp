#ifndef OBC_SOFTWARE_AMBIENTTEMPERATURETASK_HPP
#define OBC_SOFTWARE_AMBIENTTEMPERATURETASK_HPP

#include "Task.hpp"
#include "MCP9808.hpp"

/**
 * FreeRTOS task for periodically printing the value of the MCP9808 external temperature sensor.
 */
class AmbientTemperatureTask : public Task {
private:
    const uint16_t delayMs = 1000;

    /**
     * The driver for the MCP9808 temperature sensor
     */
    MCP9808 sensor;

    /**
     * The value of the temperature, measured in Celsius
     */
    float ambientTemperature;
public:
    void execute();

    AmbientTemperatureTask() : Task("ExternalTemperatureSensor", nullptr, 1000) {}
};

#endif
