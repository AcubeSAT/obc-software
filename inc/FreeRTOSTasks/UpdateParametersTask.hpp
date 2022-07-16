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
    StackType_t taskStack[configMINIMAL_STACK_SIZE * 6];

    void execute();

    UpdateParametersTask() : Task("ParameterUpdating", nullptr, 6000) {}
};

#endif
