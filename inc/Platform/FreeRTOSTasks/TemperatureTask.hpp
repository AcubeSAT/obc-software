#ifndef OBC_SOFTWARE_TEMPERATURETASK_HPP
#define OBC_SOFTWARE_TEMPERATURETASK_HPP

#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "Helper.hpp"

/**
 * FreeRTOS task for periodically printing the value of the internal temperature sensor.
 */
class TemperatureTask : public Task {
private:
    const uint16_t delayMs = 10000;
public:
    /**
     * Temperature reading from the temperature sensor.
     * @param pvParameters used for passing parameters inside FreeRTOS tasks.
     */
    void execute() override;

    TemperatureTask() = default;
};

#endif