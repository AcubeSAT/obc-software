#ifndef OBC_SOFTWARE_GATEKEEPERPRINT_H
#define OBC_SOFTWARE_GATEKEEPERPRINT_H

#include "Task.hpp"
#include "queue.h"

class UARTGatekeeper : public Task{
public:
    [[noreturn]] void execute();
    QueueHandle_t xPrintQueue;
    UARTGatekeeper(QueueHandle_t queue) : Task("Gatekeeper", nullptr, 1000) {
        this->xPrintQueue = queue;
    }
};

#endif //OBC_SOFTWARE_GATEKEEPERPRINT_H
