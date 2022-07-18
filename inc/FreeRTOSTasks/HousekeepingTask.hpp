#ifndef OBC_SOFTWARE_HOUSEKEEPINGTASK_HPP
#define OBC_SOFTWARE_HOUSEKEEPINGTASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task implementing the ST[03] Housekeeping Service.
 */
class HousekeepingTask : public Task {
public:
    const static inline uint16_t taskStackDepth = 2000;

    StackType_t taskStack[taskStackDepth];
    /**
      * @see HousekeepingService
      */
    void execute();

    HousekeepingTask() : Task("Housekeeping", nullptr) {}

};

#endif
