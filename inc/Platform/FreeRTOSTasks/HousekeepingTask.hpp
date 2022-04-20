#ifndef OBC_SOFTWARE_HOUSEKEEPINGTASK_HPP
#define OBC_SOFTWARE_HOUSEKEEPINGTASK_HPP

#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "Task.hpp"

/**
 * FreeRTOS task implementing the ST[03] Housekeeping Service.
 */
class HousekeepingTask : public Task {
public:
    /**
      * The task retrieves all Housekeeping Structures and reports their parameters
      * at the appropriate intervals through ST[03]s built in functions.
      * @see HousekeepingService
      */
    void execute() override;

    HousekeepingTask() = default;
};

#endif