#include <optional>
#include "FreeRTOSTasks/TCHandlingTask.hpp"
#include <Logger.hpp>
#include <definitions.h>
#include <MessageParser.hpp>
#include <cobs.h>
#include "COBS.hpp"
#include "task.h"


TCHandlingTask::TCHandlingTask() : Task("TCHandling") {
    messageQueue = xQueueCreateStatic(TCQueueCapacity, sizeof(etl::string<MaxTCSize>), messageQueueStorageArea,
                                      &staticQueue);
    configASSERT(messageQueue);

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
    new(&(TCHandlingTask::savedMessage)) etl::string<MaxTCSize>;
}

void TCHandlingTask::ingress() {
    if (savedMessage.full()) {
        new(&(TCHandlingTask::savedMessage)) etl::string<MaxTCSize>;
    }
    if (byteIn == 0x00) {
        xQueueSendToBackFromISR(messageQueue, static_cast<void *>(&savedMessage), nullptr);
        new(&(TCHandlingTask::savedMessage)) etl::string<MaxTCSize>;
        if (firstPass) {
            firstPass = false;
            xQueueReset(messageQueue);
        }
    } else {
        savedMessage.push_back(byteIn);
    }
}

void TCHandlingTask::execute() {
    while (true) {
        xQueueReceive(messageQueue, static_cast<void *>(&messageOut), portMAX_DELAY);
        messageOut.repair();

        auto cobsDecodedMessage = COBSdecode<MaxTCSize>(messageOut);

        auto ecssTC = MessageParser::parse(const_cast<uint8_t *>(reinterpret_cast<const uint8_t *>(cobsDecodedMessage.c_str())), MaxTCSize);
        MessageParser::execute(ecssTC);

        LOG_DEBUG << "Received new  TC[" << ecssTC.serviceType << "," << ecssTC.messageType << "]" << "\r\n";
    }
}
