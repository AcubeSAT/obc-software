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

    HousekeepingTask(const char *taskName, TaskHandle_t taskHandle, const uint16_t taskStackDepth) : Task(taskName,
                                                                                                          taskHandle,
                                                                                                          taskStackDepth) {}
};

#endif
