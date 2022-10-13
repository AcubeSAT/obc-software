#pragma once

#include "CAN/Message.hpp"
#include "Task.hpp"
#include "queue.h"

/**
 * Contains functionality of a Gatekeeper Task for the CAN Bus. It has the sole access to CAN, to avoid any
 * deadlocks that might be caused by simultaneous requests of access to the same resource. It works by having anyone
 * needing to access CAN, send the data in a queue. Then this task receives queue elements and sends them via CAN.
 */

class CANGatekeeperTask : public Task {
private:
    QueueHandle_t xCanQueue;

    const static inline uint16_t TaskStackDepth = 2000;

    StackType_t taskStack[TaskStackDepth];

public:
    void execute();

    CANGatekeeperTask();

    /**
     * Adds an CAN::Message to the CAN Gatekeeper's queue.
     *
     * This function was added as an extra abstraction layer to house the `xQueueSendToBack` function.
     * It can be used from anywhere in the code to get access to the CAN queue/CAN Gatekeeper task, without having to
     * know the low level details of the queue.
     *
     * If the queue is full, the message is not added to the queue and is lost.
     * @param message the CAN::Message to be added in the queue of the CAN Gatekeeper task.
     */
    void addToQueue(const CAN::Message &message) {
        xQueueSendToBack(xCanQueue, &message, 0);
    }

    void createTask() {
        xTaskCreateStatic(vClassTask < CANGatekeeperTask > , this->TaskName, CANGatekeeperTask::TaskStackDepth, this,
                          tskIDLE_PRIORITY + 2, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<CANGatekeeperTask> canGatekeeperTask;
