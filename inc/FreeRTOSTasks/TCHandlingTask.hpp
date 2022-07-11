#ifndef OBC_SOFTWARE_TCHANDLINGTASK_HPP
#define OBC_SOFTWARE_TCHANDLINGTASK_HPP

#include "FreeRTOS.h"
#include <queue.h>
#include <atomic>
#include "etl/String.hpp"
#include "lib/ecss-services/lib/logger/inc/Logger.hpp"
#include "Message.hpp"
#include "MessageParser.hpp"
#include "OBC_Definitions.hpp"

/**
 * FreeRTOS task implementing TC execution.
 */
class TCHandlingTask {
public:
    /**
     * Name of each task.
     */
    const char *taskName = "TCHandling";

    /**
     * Handle of each FreeRTOS task.
     */
    TaskHandle_t taskHandle = NULL;

    /**
     * The stack depth of each FreeRTOS task, defined as the number of words the stack can hold. For example, in an
     * architecture with 4 byte stack, assigning 100 to the usStackDepth argument, will allocate 4x100=400 bytes.
     */
    const uint16_t taskStackDepth = 3000;

    TCHandlingTask();

    void execute();

    /**
     * Stores the received bytes into the buffer and generates a TC-ready signal.
     */
    void createTC();

    void ingress();
private:
    struct Buffer {
        char message[byteBufferSize] = "";
    };

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
    QueueHandle_t byteQueue;


    QueueHandle_t messageQueue;

    bool messageComplete = false;

    /**
     * Stores the incoming bytes, directly after their reception. When full, the whole message is transferred into the
     * queue.
     */
    Buffer byteBuffer;


    /**
     * Incoming byte
     */
    char byteIn = 0;

    char byteOut = 0;

    uint8_t delimiterCounter = 0;
    /**
     * The buffer containing the decoded (COBS) message.
     */

    etl::string<byteBufferSize> cobsDecodedMessage = "";
};

#endif
