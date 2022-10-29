#pragma once

#include "CAN/ApplicationLayer.hpp"
#include "CAN/Frame.hpp"
#include "Task.hpp"
#include "queue.h"

/**
 * Contains functionality of a Gatekeeper Task for the CAN Bus. It has the sole access to CAN, to avoid any
 * deadlocks that might be caused by simultaneous requests of access to the same resource. It works by having anyone
 * needing to access CAN, send the data in a queue. Then this task receives queue elements and sends them via CAN.
 */

class CANGatekeeperTask : public Task {
private:
    QueueHandle_t outgoingQueue;

    QueueHandle_t incomingQueue;

    const static inline uint16_t TaskStackDepth = 2000;

    StackType_t taskStack[TaskStackDepth];

public:
    void execute();

    /**
     * The constructor initializes the FreeRTOS queues for incoming and outgoing messages.
     * It sets the required functions for the interrupt callbacks, as well as the Message RAM which is a necessary
     * memory region for communication with the peripheral. The function also calls disableInactiveBus(), which disables
     * interrupts for the initially inactive bus.
     */
    CANGatekeeperTask();

    /**
     * Adds an CAN::Frame to the CAN Gatekeeper's queue.
     *
     * This function was added as an extra abstraction layer to house the `xQueueSendToBack` function.
     * It can be used from anywhere in the code to get access to the CAN queue/CAN Gatekeeper task, without having to
     * know the low level details of the queue.
     *
     * If the queue is full, the message is not added to the queue and is lost.
     * @param message the CAN::Frame to be added in the queue of the CAN Gatekeeper task.
     */
    inline void send(const CAN::Frame &message) {
        xQueueSendToBack(outgoingQueue, &message, 0);
    }

    /**
     * Adds a CAN::Frame to the incomingQueue.
     * If the queue is full the message is lost.
     * @param message The incoming CAN::Frame.
     */
    inline void addToIncoming(const CAN::Frame &message) {
        BaseType_t taskShouldYield = pdFALSE;

        xQueueSendToBackFromISR(incomingQueue, &message, &taskShouldYield);

        if (taskShouldYield) {
            taskYIELD()
        }
    }

    /**
     * An abstraction layer over the freeRTOS queue API to get the number of messages in the incoming queue.
     * @return The number of messages in the queue.
     */
    inline uint8_t getIncomingMessagesCount() {
        return uxQueueMessagesWaiting(incomingQueue);
    }

    /**
     * Receives a CAN::Frame from the CAN Gatekeeper's queue.
     *
     * This function was added as an extra abstraction layer to house the `xQueueReceive` function.
     * It can be used from anywhere in the code to get access to the CAN queue/CAN Gatekeeper task, without having to
     * know the low level details of the queue.
     *
     * If the queue is empty, the returned message is empty.
     */
    inline CAN::Frame getFromQueue() {
        CAN::Frame message;
        xQueueReceive(incomingQueue, &message, 0);
        return message;
    }

    void createTask() {
        xTaskCreateStatic(vClassTask < CANGatekeeperTask > , this->TaskName, CANGatekeeperTask::TaskStackDepth, this,
                          tskIDLE_PRIORITY + 2, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<CANGatekeeperTask> canGatekeeperTask;
