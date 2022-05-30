#ifndef FDIR_DEMO_TEMPERATURETASK_HPP
#define FDIR_DEMO_TEMPERATURETASK_HPP

#include "FreeRTOS.h"
#include <queue.h>
#include <atomic>
#include "etl/String.hpp"
#include "lib/ecss-services/lib/logger/inc/Logger.hpp"
#include "Message.hpp"
#include "MessageParser.hpp"

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

    static constexpr int MaxInputSize = 100;

    void execute();

    UARTRXTask();

    __attribute__ ((optimize("-Ofast")))
    void ingress() {
        if (currentRXbyte == 0) {
            xQueueSendToBackFromISR(rxQueue, static_cast<void *>(&buffer1), nullptr);
            currentReadLocation = 0;
            new(&(UARTRXTask::buffer1)) UARTRXTask::Buffer{};
        } else {
            if (currentReadLocation == MaxInputSize) {
                overRun = true;
                currentReadLocation = 0;
            } else {
                buffer1.message[currentReadLocation++] = currentRXbyte;
            }
        }
    }

private:
    struct Buffer {
        char message[MaxInputSize];
    };

    static constexpr int Capacity = 10;

    char currentRXbyte;
    int currentReadLocation = 0;

    std::atomic<bool> overRun = false;

    QueueHandle_t rxQueue;

    static Buffer buffer1;
    Buffer buffer2{};
    etl::string<MaxInputSize> cobsBuffer;
};

#endif //FDIR_DEMO_TEMPERATURETASK_HPP