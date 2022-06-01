#ifndef OBC_SOFTWARE_UARTDMATASK_HPP
#define OBC_SOFTWARE_UARTDMATASK_HPP

#include "Task.hpp"

/**
 * FreeRTOS task for periodically printing "testing" using Direct Memory Access in tandem with USART1.
 * Intended for demonstration purposes.
 */
class UartDMATask : public Task {
private:
    const uint16_t delayMs = 500;
public:
    void execute();

    UartDMATask() : Task("UartDMA", nullptr, 15000){}
};

#endif
