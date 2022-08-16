#include "FreeRTOSTasks/TCHandlingTask.hpp"
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

    USART1_ReadCallbackRegister([](uintptr_t object) -> void {
        TCHandlingTask *task = reinterpret_cast<TCHandlingTask * >(object);

        if (USART1_ReadCountGet() == 0) {
            USART_ERROR usartError = USART1_ErrorGet();
        } else {
            task->ingress();
        }

        USART1_Read(&(task->byteIn), sizeof(this->byteIn));
    }, reinterpret_cast<uintptr_t>(this));

    USART1_Read(&byteIn, sizeof(byteIn));
}

void TCHandlingTask::resetInput() {
    new(&(TCHandlingTask::savedMessage)) etl::string<MaxUsartTCSize>;
}

void TCHandlingTask::ingress() {
    if (savedMessage.full()) {
        resetInput();
    }
    if (byteIn == messageEndDelimiter) {
        xQueueSendToBackFromISR(messageQueueHandle, static_cast<void *>(&savedMessage), nullptr);
        resetInput();
    } else {
        savedMessage.push_back(byteIn);
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
        uint8_t ecssTCBytes[messageLength];

        etl::copy(cobsDecodedMessage.begin(), cobsDecodedMessage.end(), ecssTCBytes);
        auto ecssTC = MessageParser::parse(ecssTCBytes, messageLength);

        LOG_DEBUG << "Received new  TC[" << ecssTC.serviceType << "," << ecssTC.messageType << "]";

        MessageParser::execute(ecssTC);
    }
}
