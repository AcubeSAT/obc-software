#ifndef OBC_SOFTWARE_XUARTDMATASK_HPP
#define OBC_SOFTWARE_XUARTDMATASK_HPP

#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"

/**
 * FreeRTOS task for periodically printing "testing" using Direct Memory Access in tandem with USART1.
 * Intended for demonstration purposes.
 */
class XUartDMATask {
private:
    const uint16_t delayMs = 3000;
public:
    /**
     * Periodic printing of message, for testing purposes.
     * @param pvParameters used for passing parameters inside FreeRTOS tasks.
     */
    void xUartDMA(void *pvParameters);

    XUartDMATask() = default;
};

#endif