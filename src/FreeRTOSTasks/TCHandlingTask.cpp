#include <optional>
#include "FreeRTOSTasks/TCHandlingTask.hpp"
#include <Logger.hpp>
#include <definitions.h>
#include <MessageParser.hpp>
#include <cobs.h>
#include "COBS.hpp"
#include "etl/compare.h"
#include "task.h"

using ECSSMessage = Message;

TCHandlingTask::Buffer TCHandlingTask::savedMessage;

TCHandlingTask::TCHandlingTask() : Task("TCHandling") {
    messageQueue = xQueueCreateStatic(MaxTCSize, sizeof(Buffer), messageQueueStorageArea, &staticQueue);
    USART1_Read(&byteIn, sizeof(byteIn));

    USART1_ReadCallbackRegister([](uintptr_t object) -> void {
        TCHandlingTask *task = reinterpret_cast<TCHandlingTask * >(object);
        if (USART1_ReadCountGet() == 0) {
            USART_ERROR usartError = USART1_ErrorGet();
        } else {
            task->ingress();
        }

        USART1_Read(&(task->byteIn), sizeof(task->byteIn));
    }, reinterpret_cast<uintptr_t>(this));
}

void TCHandlingTask::ingress() {
    if (savedMessage.full()) {
        overrun = true;
        savedMessage.erase(savedMessage.begin(), savedMessage.end());
    }
    if (byteIn == 0x69) {

        xQueueSendToBackFromISR(messageQueue, static_cast<void *>(&savedMessage), nullptr);
        savedMessage.clear();
    } else {
        savedMessage.append(1, byteIn);
    }
}

void TCHandlingTask::execute() {
    while (true) {
        xQueueReceive(messageQueue, static_cast<void *>(&messageOut), portMAX_DELAY);
        auto cobsDecodedMessage = COBSdecode<MaxTCSize>(messageOut);

        ECSSMessage ecssTC = MessageParser::parse(reinterpret_cast<uint8_t *>(cobsDecodedMessage.data()), MaxTCSize);
        MessageParser::execute(ecssTC);

        LOG_DEBUG << "Received new  TC[" << ecssTC.serviceType << "," << ecssTC.messageType << "]";

    }
}
