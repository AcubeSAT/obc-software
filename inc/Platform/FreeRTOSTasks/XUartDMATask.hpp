#ifndef OBC_SOFTWARE_XUARTDMATASK_HPP
#define OBC_SOFTWARE_XUARTDMATASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task for periodically printing "testing" using Direct Memory Access in tandem with USART1.
 * Intended for demonstration purposes.
 */
class XUartDMATask : public Task {
private:
    const uint16_t delayMs = 3000;
public:
    void execute() override;

    XUartDMATask(const char *taskName, TaskHandle_t taskHandle, const uint16_t taskStackDepth,
                 const uint16_t delayMs) : Task(taskName, taskHandle, taskStackDepth), delayMs(delayMs) {}
};

#endif
