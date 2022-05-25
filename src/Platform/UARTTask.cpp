#include "UARTTask.hpp"

std::optional<UARTTask> uartTask;


void UARTTask::operator()() {
    while (true) {
        if (queue.pop(buffer)) {
            USART1_Write(buffer.data(), buffer.size());
            while (USART1_WriteIsBusy()) {
                taskYIELD();
            }
        } else {
            taskYIELD();
        }
    }
}
