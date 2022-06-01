#include <optional>
#include "FreeRTOSTasks/UARTRXTask.hpp"
#include <Logger.hpp>
#include <definitions.h>
#include <MessageParser.hpp>
#include <Helpers/COBS.hpp>

using ECSSMessage = Message;
UARTRXTask::Buffer UARTRXTask::UartQueueInBuffer;

UARTRXTask::UARTRXTask() {
    rxQueue = xQueueCreate(UartRXQueueLength, sizeof(Message));

    USART1_Read(&currentRXbyte, 1);

    USART1_ReadCallbackRegister([](uintptr_t object) {
        // This function is called whenever a single byte arrives

        auto rxTask = reinterpret_cast<UARTRXTask *>(object); // Work-around through library API to pass object

        if (USART1_ReadCountGet() == 0) {
            ErrorHandler::reportInternalError(ErrorHandler::InternalErrorType::UsartFailedRead);
        } else {
            rxTask->ingress();
        }

        USART1_Read(&(rxTask->currentRXbyte), 1);
    }, reinterpret_cast<uintptr_t>(this));
}

void UARTRXTask::execute() {
    while (true) {
        xQueueReceive(rxQueue, static_cast<void *>(&UartQueueOutBuffer), portMAX_DELAY);

        if (overrun) {
            overrun = false;
            LOG_ERROR << "RX too large message";
        }

        // Create a TC message and execute it.
        Message mess(UartQueueInBuffer.message[1], UartQueueInBuffer.message[2], Message::TC, 1);
        MessageParser::execute(mess);

//        cobsDecodedMessage = COBSdecode<MaxInputSize>(reinterpret_cast<uint8_t*>(buffer2.message), MaxInputSize);

        ECSSMessage ecss = MessageParser::parseECSSTC(reinterpret_cast<const uint8_t*>(cobsDecodedMessage.c_str()));

//        MessageParser::execute(ecss);
    }
}