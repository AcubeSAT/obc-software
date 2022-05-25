#ifndef OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP
#define OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task for periodically updating specific parameters using ParameterService functionality.
 */
class UpdateParametersTask : public Task {
private:
    const uint16_t delayMs = 300;
public:
    void execute();

    UpdateParametersTask(const char *taskName, TaskHandle_t taskHandle, const uint16_t taskStackDepth,
                         const uint16_t delayMs) : Task(taskName, taskHandle, taskStackDepth), delayMs(delayMs) {}
};

#endif
