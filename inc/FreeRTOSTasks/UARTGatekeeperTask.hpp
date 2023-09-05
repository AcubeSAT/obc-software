#pragma once

#include "COBS.hpp"
#include "Task.hpp"
#include "queue.h"
#include "Peripheral_Definitions.hpp"

/**
 * Contains functionality of a Gatekeeper Task for the UART resource. It has the sole access to UART, to avoid any
 * deadlocks that might be caused by simultaneous requests of access to the same resource. It works by having anyone
 * needing to access UART, send the data in a queue. Then, this task receives queue elements and sends them to UART.
 */
class UARTGatekeeperTask : public Task {
private:
    QueueHandle_t xUartQueue;

    StaticQueue_t xStaticQueue;

    uint8_t ucQueueStorageArea[UARTQueueSize * sizeof(etl::string<LOGGER_MAX_MESSAGE_SIZE>)];

    const static inline uint16_t TaskStackDepth = 2000;

    StackType_t taskStack[TaskStackDepth];

    /**
     * This variable is used to store a task handle for a UART gatekeeper task.
     * The uartGatekeeperTaskHandle and the task notification mechanism are used to coordinate
     * and synchronize the UART gatekeeper task with the completion of the XDMAC transfer.
     * It allows the UART gatekeeper task to efficiently wait for and respond to these events
     * without continuously polling for their completion.
     */
    inline static TaskHandle_t uartGatekeeperTaskHandle = nullptr;

    /**
     * This variable is used to store the status of a Direct Memory Access (DMA) transaction event
     * in order to check for errors during the XDMAC transfer.
     */
    inline static XDMAC_TRANSFER_EVENT dmaTransactionStatus = XDMAC_TRANSFER_NONE;

    /**
     * This variable is used to store the maximum time the task should wait for the notification in ticks.
     * The number 1000ms was considered a good value arbitrarily
     */
    TickType_t maxDelay = pdMS_TO_TICKS(1000);

public:
    void execute();

    UARTGatekeeperTask();

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
    void addToQueue(const etl::string<LOGGER_MAX_MESSAGE_SIZE> &message) {
        xQueueSendToBack(xUartQueue, &message, 0);
    }

    void createTask() {
        uartGatekeeperTaskHandle = xTaskCreateStatic(vClassTask < UARTGatekeeperTask > , this->TaskName,
                                                     UARTGatekeeperTask::TaskStackDepth, this,
                                                     tskIDLE_PRIORITY + 2, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<UARTGatekeeperTask> uartGatekeeperTask;
