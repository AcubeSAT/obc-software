#include <optional>
#include "FreeRTOSTasks/UARTRXTask.hpp"
#include <Logger.hpp>
#include <definitions.h>
#include <MessageParser.hpp>
#include <Helpers/COBS.hpp>
#include "etl/compare.h"

using ECSSMessage = Message;
UARTRXTask::Buffer UARTRXTask::UartQueueInBuffer;

UARTRXTask::UARTRXTask() {
    rxQueue = xQueueCreate(UartRXQueueLength, sizeof(Message));

    USART1_Read(&currentRXbyte, 1);

    USART1_ReadCallbackRegister([](uintptr_t object) {
        auto rxTask = reinterpret_cast<UARTRXTask *>(object);

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
        xQueueReceive(rxQueue, static_cast<void *>(&UartQueueOutBuffer.message), portMAX_DELAY);

        if (overrun) {
            overrun = false;
            LOG_ERROR << "RX too large message";
        }

        char test[UartRXBufferSize] = "";
        if (!std::equal(std::begin(UartQueueOutBuffer.message), std::end(UartQueueOutBuffer.message),
                        std::begin(test))) {
//            auto cobsDecodedMessage = COBSdecode<UartRXBufferSize>(
//                    reinterpret_cast<uint8_t *>(UartQueueOutBuffer.message),
//                    UartRXBufferSize);
            uint8_t arr[64];
            std::copy(std::begin(UartQueueOutBuffer.message), std::end(UartQueueOutBuffer.message), std::begin(arr));

            ECSSMessage ecss = MessageParser::parseECSSTC(arr);
            MessageParser::execute(ecss);

        }


//        MessageParser::execute(ecss);
        // Create a TC message and execute it.
//        Message mess(UartQueueInBuffer.message[1], UartQueueInBuffer.message[2], Message::TC, 1);
//        MessageParser::execute(mess);


    }
}