#ifndef OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP
#define OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP

#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "Task.hpp"

/**
 * FreeRTOS task for periodically updating specific parameters using ParameterService functionality.
 */
class UpdateParametersTask : public Task {
private:
    const uint16_t delayMs = 300;
public:
    /**
     * Periodic parameter updating.
     * @param taskName pointer to a const char pointer necessary to create a FreeRTOS TaskHandle_t variable to keep
     * track of the minimum available stack of \ref reportParameters.
     */
    void execute() override;

    UpdateParametersTask() = default;
};

#endif