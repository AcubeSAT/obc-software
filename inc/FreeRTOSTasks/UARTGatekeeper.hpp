#ifndef OBC_SOFTWARE_GATEKEEPERPRINT_H
#define OBC_SOFTWARE_GATEKEEPERPRINT_H

#include "Task.hpp"
#include "queue.h"

class UARTGatekeeper : public Task {
private:
    QueueHandle_t xUartQueue;

public:

    void execute();

    UARTGatekeeper();

    /**
     * This function was added as an extra abstraction layer to house the `xQueueSendToBack` function.
     * It can be used from anywhere in the code to get access to the UART queue/UART Gatekeeper task, without having to
     * know the low level details of the queue.
     *
     * Adds an etl::string to the UART Gatekeeper's queue.
     *
     * If the queue is full, the string is not added to the queue and is lost.
     * @param message the etl::string to be added in the queue of the UART Gatekeeper task.
     */
    void addToQueue(const etl::string<LOGGER_MAX_MESSAGE_SIZE> & message) {
        xQueueSendToBack(xUartQueue, &message, 0);
    }

};

#endif //OBC_SOFTWARE_GATEKEEPERPRINT_H
