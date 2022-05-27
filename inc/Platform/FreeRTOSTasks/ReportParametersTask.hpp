#ifndef OBC_SOFTWARE_REPORTPARAMETERSTASK_HPP
#define OBC_SOFTWARE_REPORTPARAMETERSTASK_HPP

#include "FreeRTOS.h"
#include "task.h"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "Platform/Parameters/PlatformParameters.hpp"

/**
 * FreeRTOS task for periodically reporting specific parameters using ParameterService functionality.
 * @see ParameterService
 */
class ReportParametersTask {
private:
    const uint16_t numberOfIDs = 11;
    const uint16_t delayMs = 1200;
public:
    /**
     * Name of each task.
     */
    const char *taskName = "ParameterReporting";
    /**
     * Handle of each FreeRTOS task.
     */
    TaskHandle_t taskHandle = NULL;
    /**
     * The stack depth of each FreeRTOS task, defined as the number of words the stack can hold. For example, in an
     * architecture with 4 byte stack, assigning 100 to the usStackDepth argument, will allocate 4x100=400 bytes.
     */
    const uint16_t taskStackDepth = 3000;

    void execute();

};

#endif
