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
    /**
     * Periodic printing of message, for testing purposes.
     */
    void execute() override;

    XUartDMATask() = default;
};

#endif