#include "TCHandlingTask.hpp"
#include <Logger.hpp>
#include <definitions.h>
#include <MessageParser.hpp>
#include "COBS.hpp"
#include "task.h"

TCHandlingTask::TCHandlingTask() : Task("TCHandling") {
    messageQueueHandle = xQueueCreateStatic(TCQueueCapacity, sizeof(etl::string<MaxUsartTCSize>),
                                            messageQueueStorageArea,
                                            &messageQueue);
    configASSERT(messageQueueHandle);

    UART0_ReadCallbackRegister([](uintptr_t object) -> void {
        TCHandlingTask *task = reinterpret_cast<TCHandlingTask * >(object);

        if (UART0_ReadCountGet() == 0) {
            UART_ERROR uartError = UART0_ErrorGet();
        } else {
            task->ingress();
        }

        UART0_Read(&(task->byteIn), sizeof(this->byteIn));
    }, reinterpret_cast<uintptr_t>(this));

    UART0_Read(&byteIn, sizeof(byteIn));
}

void TCHandlingTask::resetInput() {
    new(&(TCHandlingTask::savedMessage)) etl::string<MaxUsartTCSize>;
}

void TCHandlingTask::ingress() {
    BaseType_t higherPriorityTaskWoken = pdFALSE;

    if (savedMessage.full()) {
        resetInput();
    }

    if (byteIn == MessageEndDelimiter) {
        xQueueSendToBackFromISR(messageQueueHandle, static_cast<void *>(&savedMessage), &higherPriorityTaskWoken);
        resetInput();
    } else {
        savedMessage.push_back(byteIn);
    }

    if (higherPriorityTaskWoken) {
        portYIELD_FROM_ISR(higherPriorityTaskWoken);
    }
}

void TCHandlingTask::execute() {
    while (true) {
        xQueueReceive(messageQueueHandle, static_cast<void *>(&messageOut), portMAX_DELAY);

        // xQueueReceive does a low-level copy of the message string, so we need to call
        // etl::string::repair() to rearrange the string pointers and prevent memory errors.
        messageOut.repair();
        auto cobsDecodedMessage = COBSdecode<MaxUsartTCSize>(messageOut);

        uint8_t messageLength = cobsDecodedMessage.size();
        uint8_t *ecssTCBytes = reinterpret_cast<uint8_t *>(cobsDecodedMessage.data());

        auto ecssTC = MessageParser::parse(ecssTCBytes, messageLength);

        LOG_DEBUG << "Received new TC[" << ecssTC.serviceType << "," << ecssTC.messageType << "]";

        MessageParser::execute(ecssTC);
    }
}
