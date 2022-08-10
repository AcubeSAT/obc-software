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
class TCHandlingTask : public Task {
private:
    /**
     * A buffer to save incoming TC bytes and later queue it for later use
     */
    inline static etl::string<MaxTCSize> savedMessage;

    /**
     * A buffer to save TC bytes coming out of the queue.
     */
    etl::string<MaxTCSize> messageOut;

    /**
     * Pointer to the location of the buffer, to write the next byte, when received.
     */
    uint8_t currentReadLocation = 0;

    /**
     * Returns true when the byte buffer is full.
     */
    bool overRun = false;

    /**
     * A flag to clear the queue when the task starts.
     */
    bool firstPass = false;

    /**
     * Incoming byte
     */
    char byteIn = 0;

    /**
     * Saves incoming bytes by inserting them into a queue.
     */
    uint8_t messageQueueStorageArea[MaxTCSize * sizeof(etl::string<MaxTCSize>)];
    inline static StaticQueue_t staticQueue;
    QueueHandle_t messageQueue;

public:

    /**
     * The stack depth of each FreeRTOS task, defined as the number of words the stack can hold. For example, in an
     * architecture with 4 byte stack, assigning 100 to the usStackDepth argument, will allocate 4x100=400 bytes.
     */
    const static inline uint16_t taskStackDepth = 3000;

    StackType_t taskStack[taskStackDepth];


    TCHandlingTask();

    /**
     * Appends bytes into a buffer and then queues them ready.
     */
    void ingress();

    void execute();

};


#endif
