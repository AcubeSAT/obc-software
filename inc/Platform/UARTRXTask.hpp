#ifndef FDIR_DEMO_TEMPERATURETASK_HPP
#define FDIR_DEMO_TEMPERATURETASK_HPP

#include "FreeRTOS.h"
#include <queue.h>
#include <atomic>
#include "etl/String.hpp"

class UARTRXTask {
public:
    static constexpr int MaxMessageSize = 10;

    void operator()();

    UARTRXTask();

    __attribute__ ((optimize("-Ofast")))
    void ingress() {    // todo: remove currentRXbyte
        if (currentRXbyte == 0) {
            xQueueSendToBackFromISR(rxQueue, static_cast<void *>(&buffer1), nullptr);
            currentReadLocation = 0;
            new(&(UARTRXTask::buffer1)) UARTRXTask::Message{};
        } else {
            if (currentReadLocation == MaxMessageSize) {
                overRun = true;
                currentReadLocation = 0;
            } else {
                memcpy(&buffer1.message, &rxBuffer, 10);
            }
        }
    }
private:
    struct Message {
        char message[MaxMessageSize];
    };

    static constexpr int Capacity = 10;

    char currentRXbyte;
    int currentReadLocation = 0;
    char rxBuffer[10];

    std::atomic<bool> overRun = false;

    QueueHandle_t rxQueue;

    static Message buffer1;
    Message buffer2{};
    etl::string<MaxMessageSize> cobsBuffer;
};

extern std::optional<UARTRXTask> uartRXtask;

#endif //FDIR_DEMO_TEMPERATURETASK_HPP
