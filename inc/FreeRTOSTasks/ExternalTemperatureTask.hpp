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
    MCP9808 sensor;
    float externalTemperature;
public:
    void execute();

    ExternalTemperatureTask() : Task("ExternalTemperatureSensor", nullptr, 1000) {}
};

#endif
