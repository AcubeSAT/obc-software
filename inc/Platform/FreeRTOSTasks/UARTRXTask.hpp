#ifndef FDIR_DEMO_TEMPERATURETASK_HPP
#define FDIR_DEMO_TEMPERATURETASK_HPP

#include "FreeRTOS.h"
#include <queue.h>
#include <atomic>
#include "etl/String.hpp"

class UARTRXTask {
public:
    static constexpr int MaxInputSize = 100;

    void operator()();

    UARTRXTask();

    __attribute__ ((optimize("-Ofast")))
    void ingress() {
        if (currentRXbyte == 0) {
            xQueueSendToBackFromISR(rxQueue, static_cast<void *>(&buffer1), nullptr);
            currentReadLocation = 0;
            new(&(UARTRXTask::buffer1)) UARTRXTask::Message{};
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
    struct Message {
        char message[MaxInputSize];
    };

    static constexpr int Capacity = 10;

    char currentRXbyte;
    int currentReadLocation = 0;

    std::atomic<bool> overRun = false;

    QueueHandle_t rxQueue;

    static Message buffer1;
    Message buffer2{};
    etl::string<MaxInputSize> cobsBuffer;
};

extern std::optional<UARTRXTask> uartRXtask;


#endif //FDIR_DEMO_TEMPERATURETASK_HPP