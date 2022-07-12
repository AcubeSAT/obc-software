#ifndef OBC_SOFTWARE_HOUSEKEEPINGTASK_HPP
#define OBC_SOFTWARE_HOUSEKEEPINGTASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task implementing the ST[03] Housekeeping Service.
 */
class HousekeepingTask : public Task {
public:
    static StackType_t taskStack[configMINIMAL_STACK_SIZE * 2];
    /**
      * @see HousekeepingService
      */
    void execute();

    HousekeepingTask() : Task("Housekeeping", nullptr, 2000) {}

};

#endif
