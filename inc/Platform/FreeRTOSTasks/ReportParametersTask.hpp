#ifndef OBC_SOFTWARE_REPORTPARAMETERSTASK_HPP
#define OBC_SOFTWARE_REPORTPARAMETERSTASK_HPP

#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "Task.hpp"

/**
 * FreeRTOS task for periodically reporting specific parameters using ParameterService functionality.
 * @see ParameterService
 */
class ReportParametersTask : public Task {
private:
    const uint16_t numberOfIDs = 11;
    const uint16_t delayMs = 1000;
public:
    /**
     * Periodic parameter reporting.
     */
    void execute() override;

    ReportParametersTask() = default;
};

#endif