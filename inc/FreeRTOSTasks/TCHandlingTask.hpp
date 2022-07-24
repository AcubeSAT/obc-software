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
#include "Task.hpp"

/**
 * FreeRTOS task implementing TC execution.
 */
class TCHandlingTask {
private:
    struct Buffer {
        char message[ByteBufferSize] = "";
    };

    /**
     * Pointer to the location of the buffer, to write the next byte, when received.
     */
    uint8_t currentReadLocation = 0;

    /**
     * Returns true when the byte buffer is full.
     */
    std::atomic<bool> overrun = false;

    /**
     * Incoming byte
     */
    char byteIn = 0;

    /**
     * Saves incoming bytes by inserting them into a queue.
     */
    QueueHandle_t byteQueue;

    /**
     * Appends the bytes from the queue and then its contents is used to create an ECSS TC
     */
    Buffer byteBuffer;

    /**
     * Signals if a message is ready.
     */
    bool messageComplete = false;

public:

    /**
     * Name of the task
     */
    const char *taskName = "TCHandling";

    /**
     * The stack depth of each FreeRTOS task, defined as the number of words the stack can hold. For example, in an
     * architecture with 4 byte stack, assigning 100 to the usStackDepth argument, will allocate 4x100=400 bytes.
     */
    const uint16_t taskStackDepth = 3000;

    TCHandlingTask();

    /**
     * Stores the received bytes into the buffer and generates a TC-ready signal.
     */
    void createTC();


    void execute();


};


#endif
