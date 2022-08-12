#include <optional>
#include "FreeRTOSTasks/TCHandlingTask.hpp"
#include <Logger.hpp>
#include <definitions.h>
#include <MessageParser.hpp>
#include <cobs.h>
#include "COBS.hpp"
#include "task.h"


TCHandlingTask::TCHandlingTask() : Task("TCHandling") {
    messageQueueHandle = xQueueCreateStatic(TCQueueCapacity, sizeof(etl::string<MaxUsartTCSize>), messageQueueStorageArea,
                                      &byteQueue);

    if (messageQueueHandle == 0) {
        LOG_ERROR << "Failed to create queue, suspending task...\r\n";
        vTaskSuspend(taskHandle);
    }

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

void TCHandlingTask::ingress() {
    if (savedMessage.full()) {
        new(&(TCHandlingTask::savedMessage)) etl::string<MaxUsartTCSize>;
    }
    if (byteIn == 0x00) {
        xQueueSendToBackFromISR(messageQueueHandle, static_cast<void *>(&savedMessage), nullptr);
        new(&(TCHandlingTask::savedMessage)) etl::string<MaxUsartTCSize>;
        if (firstPass) {
            firstPass = false;
            xQueueReset(messageQueueHandle);
        }
    } else {
        savedMessage.push_back(byteIn);
    }
}

void TCHandlingTask::execute() {
    while (true) {
        xQueueReceive(messageQueueHandle, static_cast<void *>(&messageOut), portMAX_DELAY);
        messageOut.repair();

        auto cobsDecodedMessage = COBSdecode<MaxUsartTCSize>(messageOut);

        auto ecssTC = MessageParser::parse(const_cast<uint8_t *>(reinterpret_cast<const uint8_t *>(cobsDecodedMessage.c_str())), MaxUsartTCSize);
        MessageParser::execute(ecssTC);

        LOG_DEBUG << "Received new  TC[" << ecssTC.serviceType << "," << ecssTC.messageType << "]" << "\r\n";
    }
}
