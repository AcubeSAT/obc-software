#ifndef OBC_SOFTWARE_GATEKEEPERPRINT_H
#define OBC_SOFTWARE_GATEKEEPERPRINT_H

#include "Task.hpp"
#include "queue.h"

class UARTGatekeeper : public Task {
public:

    void execute();
    QueueHandle_t xUartQueue;
    UARTGatekeeper();

};

#endif //OBC_SOFTWARE_GATEKEEPERPRINT_H
