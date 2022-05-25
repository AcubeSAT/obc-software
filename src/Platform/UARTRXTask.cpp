#include <optional>
#include "UARTRXTask.hpp"
#include <Logger.hpp>
#include <definitions.h>
#include <MessageParser.hpp>

using ECSSMessage = Message;

std::optional<UARTRXTask> uartRXtask;
UARTRXTask::Message UARTRXTask::buffer1;

UARTRXTask::UARTRXTask() {
    rxQueue = xQueueCreate(Capacity, sizeof(Message));

    USART1_Read(&rxBuffer, MaxMessageSize);

    USART1_ReadCallbackRegister([](uintptr_t object) {
        // This function is called whenever a single byte arrives

        auto rxTask = reinterpret_cast<UARTRXTask*>(object); // Work-around through library API to pass object

        if (USART1_ReadCountGet() == 0) {
            // Some error occurred
        } else {
            rxTask->ingress();
            USART1_Write(&buffer1, sizeof(buffer1));
        }

        // Initiate next read
        USART1_Read(&(rxTask->currentRXbyte), 1);
    }, reinterpret_cast<uintptr_t>(this));
}

void UARTRXTask::operator()() {
    while (true) {
        xQueueReceive(rxQueue, static_cast<void*>(&buffer2), portMAX_DELAY);

        if (overRun) {
            overRun = false;
            LOG_ERROR << "RX too large message";
        }
        LOG_INFO << "\r\nRECEIVED FUCKING SHITTY MESSAGE\n";

        ECSSMessage ecss = MessageParser::parseECSSTC(reinterpret_cast<const uint8_t*>(cobsBuffer.c_str()));

        LOG_INFO << "Received new [" << ecss.serviceType << "," << ecss.messageType << "] TC";

        MessageParser::execute(ecss);
    }
}


