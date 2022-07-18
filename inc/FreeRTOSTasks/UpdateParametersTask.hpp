#ifndef OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP
#define OBC_SOFTWARE_UPDATEPARAMETERSTASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task for periodically updating specific parameters using ParameterService functionality.
 */
class UpdateParametersTask : public Task {
private:
    const uint16_t delayMs = 3000;
public:
    const static inline uint16_t taskStackDepth = 6000;

    StackType_t taskStack[taskStackDepth];
    void execute();

    UpdateParametersTask() : Task("ParameterUpdating", nullptr, taskStackDepth) {}
};

#endif
