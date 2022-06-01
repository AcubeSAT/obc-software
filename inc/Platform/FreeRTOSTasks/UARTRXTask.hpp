#ifndef FDIR_DEMO_TEMPERATURETASK_HPP
#define FDIR_DEMO_TEMPERATURETASK_HPP

#include "FreeRTOS.h"
#include <queue.h>
#include <atomic>
#include "etl/String.hpp"
#include "lib/ecss-services/lib/logger/inc/Logger.hpp"
#include "Message.hpp"
#include "MessageParser.hpp"
#include "OBC_Definitions.hpp"

/**
 * This task is responsible for receiving incoming TC messages from UART, and executing them.
 * @author <Kanavouras Konstantinos>
 */
class UARTRXTask {
public:
    /**
     * Name of each task.
     */
    const char *taskName = "UartRX";
    /**
     * Handle of each FreeRTOS task.
     */
    TaskHandle_t taskHandle = NULL;
    /**
     * The stack depth of each FreeRTOS task, defined as the number of words the stack can hold. For example, in an
     * architecture with 4 byte stack, assigning 100 to the usStackDepth argument, will allocate 4x100=400 bytes.
     */
    const uint16_t taskStackDepth = 1000;

    void execute();

    UARTRXTask();

    __attribute__ ((optimize("-Ofast")))
    void ingress() {
        if (currentRXbyte == 0) {
            xQueueSendToBackFromISR(rxQueue, static_cast<void *>(&UartQueueInBuffer), nullptr);
            currentReadLocation = 0;
            new(&(UARTRXTask::UartQueueInBuffer)) UARTRXTask::Buffer{};
        } else {
            if (currentReadLocation == UartRXBufferSize) {
                overrun = true;
                currentReadLocation = 0;
            } else {
                UartQueueInBuffer.message[currentReadLocation++] = currentRXbyte;
            }
        }
    }

private:
    struct Buffer {
        char message[UartRXBufferSize];
    };

    /**
     * The byte currently being received.
     */
    char currentRXbyte;
    /**
     * Pointer to the location of the buffer, to write the next byte, when received.
     */
    int currentReadLocation = 0;
    /**
     * Returns true when the UartRXBuffer is full.
     */
    std::atomic<bool> overrun = false;
    /**
     * Used for storing the received data as soon as a full message has been received.
     */
    QueueHandle_t rxQueue;
    /**
     * Stores the incoming bytes, directly after their reception. When full, the whole message is transferred into the
     * queue.
     */
    static Buffer UartQueueInBuffer;
    /**
     * Gets the received data from the queue.
     */
    Buffer UartQueueOutBuffer{};
    /**
     *
     */
    etl::string<UartRXBufferSize> cobsDecodedMessage;
};

#endif //FDIR_DEMO_TEMPERATURETASK_HPP