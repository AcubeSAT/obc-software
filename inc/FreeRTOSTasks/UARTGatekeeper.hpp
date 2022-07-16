#ifndef OBC_SOFTWARE_UARTGATEKEEPER_H
#define OBC_SOFTWARE_UARTGATEKEEPER_H

#include "Task.hpp"
#include "queue.h"

/**
 * Contains functionality of a Gatekeeper Task for the UART resource. It has the sole access to UART, to avoid any
 * deadlocks that might be caused by simultaneous requests of access to the same resource. It works by having anyone
 * needing to access UART, send the data in a queue. Then, this task receives queue elements and sends them to UART.
 */
class UARTGatekeeper : public Task {
private:
    QueueHandle_t xUartQueue;

public:
    StackType_t taskStack[configMINIMAL_STACK_SIZE * 2];

    void execute();

    UARTGatekeeper();

    /**
     * Adds an etl::string to the UART Gatekeeper's queue.
     * 
     * This function was added as an extra abstraction layer to house the `xQueueSendToBack` function.
     * It can be used from anywhere in the code to get access to the UART queue/UART Gatekeeper task, without having to
     * know the low level details of the queue.
     *
     * If the queue is full, the string is not added to the queue and is lost.
     * @param message the etl::string to be added in the queue of the UART Gatekeeper task.
     */
    void addToQueue(const etl::string<LOGGER_MAX_MESSAGE_SIZE> & message) {
        xQueueSendToBack(xUartQueue, &message, 0);
    }

};

#endif //OBC_SOFTWARE_UARTGATEKEEPER_H
