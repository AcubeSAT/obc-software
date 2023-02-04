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
    etl::string<MaxUsartTCSize> savedMessage;

    /**
     * A buffer containing TC bytes coming out of the queue.
     */
    etl::string<MaxUsartTCSize> messageOut;

    /**
     * Incoming TC byte
     */
    uint8_t byteIn = 0;

    /**
     * The value that signals a message is done being transmitted.1
     */
    const inline static uint8_t MessageEndDelimiter = 0x00;

    /**
     * Saves incoming bytes by inserting them into a queue.
     */
    uint8_t messageQueueStorageArea[TCQueueCapacity * sizeof(etl::string<MaxUsartTCSize>)];
    StaticQueue_t messageQueue;
    QueueHandle_t messageQueueHandle;

public:
    /**
     * The stack depth of each FreeRTOS task, defined as the number of words the stack can hold. For example, in an
     * architecture with 4 byte stack, assigning 100 to the usStackDepth argument, will allocate 4x100=400 bytes.
     */
    const static inline uint16_t TaskStackDepth = 6000;

    StackType_t taskStack[TaskStackDepth];

    TCHandlingTask();

    /**
     * Resets the savedMessage input buffer.
     */
    void resetInput();

    /**
     * Appends bytes into a buffer and then queues them ready.
     *
     * This function receives a single byte from the microcontroller's UART, and stores it to the buffer.
     * It should be called by an interrupt as soon as possible, so that no bytes are lost.
     */
    void ingress();

    void execute();

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        xTaskCreateStatic(vClassTask<TCHandlingTask>, this->TaskName, TCHandlingTask::TaskStackDepth, this,
                          tskIDLE_PRIORITY + 1, this->taskStack, &(this->taskBuffer));
    }

};

inline std::optional<TCHandlingTask> tcHandlingTask;


#endif
