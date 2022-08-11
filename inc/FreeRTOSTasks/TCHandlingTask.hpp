#ifndef OBC_SOFTWARE_TCHANDLINGTASK_HPP
#define OBC_SOFTWARE_TCHANDLINGTASK_HPP

#include "FreeRTOS.h"
#include <queue.h>
#include "etl/String.hpp"
#include "Logger.hpp"
#include "Message.hpp"
#include "MessageParser.hpp"
#include "OBC_Definitions.hpp"
#include "Task.hpp"

/**
 * FreeRTOS task implementing TC execution received externally using usart.
 */
class TCHandlingTask : public Task {
private:
    /**
     * A buffer to save externally incoming TC bytes using usart. This buffer is queued for later use.
     */
    inline static etl::string<MaxUsartTCSize> savedMessage;

    /**
     * A buffer containing TC bytes coming out of the queue.
     */
    etl::string<MaxUsartTCSize> messageOut;

    /**
     * A flag to clear the queue when the task starts.
     */
    bool firstPass = true;

    /**
     * Incoming TC byte
     */
    uint8_t byteIn = 0;

    /**
     * Saves incoming bytes by inserting them into a queue.
     */
    uint8_t messageQueueStorageArea[TCQueueCapacity * sizeof(etl::string<MaxUsartTCSize>)];
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
     * Resets the input buffer after the queue insertion or in an over run case.
     */
    void resetInput();

    /**
     * Appends bytes into a buffer and then queues them ready.
     */
    void ingress();

    void execute();

};


#endif
