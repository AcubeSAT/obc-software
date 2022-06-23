#ifndef OBC_SOFTWARE_HOUSEKEEPINGTASK_HPP
#define OBC_SOFTWARE_HOUSEKEEPINGTASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task implementing the ST[03] Housekeeping Service.
 */
class HousekeepingTask : public Task {
public:
    /**
      * @see HousekeepingService
      */
    void execute();

    HousekeepingTask() : Task("Housekeeping", nullptr, 2*configMINIMAL_STACK_SIZE) {}

};

#endif
