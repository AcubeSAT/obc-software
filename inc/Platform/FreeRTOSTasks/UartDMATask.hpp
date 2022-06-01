#ifndef OBC_SOFTWARE_UARTDMATASK_HPP
#define OBC_SOFTWARE_UARTDMATASK_HPP

#include "FreeRTOS.h"
#include "task.h"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "Platform/Parameters/PlatformParameters.hpp"

/**
 * FreeRTOS task for periodically printing "testing" using Direct Memory Access in tandem with USART1.
 * Intended for demonstration purposes.
 */
class UartDMATask {
private:
    const uint16_t delayMs = 3000;

public:
    /**
     * Name of each task.
     */
    const char *taskName = "UartDMA";
    /**
     * Handle of each FreeRTOS task.
     */
    TaskHandle_t taskHandle = NULL;
    /**
     * The stack depth of each FreeRTOS task, defined as the number of words the stack can hold. For example, in an
     * architecture with 4 byte stack, assigning 100 to the usStackDepth argument, will allocate 4x100=400 bytes.
     */
    const uint16_t taskStackDepth = 18000;

    void execute();

};

#endif
