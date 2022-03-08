#ifndef OBC_SOFTWARE_REPORTPARAMETERSTASK_HPP
#define OBC_SOFTWARE_REPORTPARAMETERSTASK_HPP

#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"

/**
 * FreeRTOS task for periodically reporting specific parameters using ParameterService functionality.
 * @see ParameterService
 */
class ReportParametersTask {
public:
    TaskHandle_t reportParameterHandle;
private:
    const uint16_t numberOfIDs = 11;
    const uint16_t delayMs = 1000;
public:
    /**
     * Periodic parameter reporting.
     * @param pvParameters used for passing parameters inside FreeRTOS tasks.
     */
    void reportParameters(void *pvParameters);

    ReportParametersTask() = default;
};

#endif