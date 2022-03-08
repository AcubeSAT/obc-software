#ifndef OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP
#define OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP

#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"

/**
 * FreeRTOS task for periodically updating specific parameters using ParameterService functionality.
 */
class UpdateParametersTask {
public:
    TaskHandle_t updateParametersHandle;
private:
    const uint16_t delayMs = 300;
public:
    /**
     * Periodic parameter updating.
     * @param taskName pointer to a const char pointer necessary to create a FreeRTOS TaskHandle_t variable to keep
     * track of the minimum available stack of \ref reportParameters.
     */
    void updateParameters(void *taskName);

    UpdateParametersTask() = default;
};

#endif