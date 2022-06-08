#ifndef OBC_SOFTWARE_EXTERNALTEMPERATURETASK_HPP
#define OBC_SOFTWARE_EXTERNALTEMPERATURETASK_HPP

#include "Task.hpp"
#include "MCP9808.hpp"

/**
 * FreeRTOS task for periodically printing the value of the MCP9808 external temperature sensor.
 */
class ExternalTemperatureTask : public Task {
private:
    const uint16_t delayMs = 1000;

    /**
     * The driver for the MCP9808 temperature sensor
     */
    MCP9808 sensor;

    /**
     * The value of the temperature, measured in Celsius
     */
    float externalTemperature;
public:
    void execute();

    ExternalTemperatureTask() : Task("ExternalTemperatureSensor", nullptr, 1000) {}
};

#endif
