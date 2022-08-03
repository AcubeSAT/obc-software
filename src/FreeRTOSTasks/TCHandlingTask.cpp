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

etl::string<MaxTCSize> TCHandlingTask::savedMessage{""};

TCHandlingTask::TCHandlingTask() : Task("TCHandling") {
    messageQueue = xQueueCreateStatic(MaxTCSize, sizeof(etl::string<MaxTCSize>), messageQueueStorageArea, &staticQueue);
    configASSERT(messageQueue);
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
        overRun = true;
    }
    if (byteIn == 0x00) {
        xQueueSendToBackFromISR(messageQueue, static_cast<void *>(&savedMessage), nullptr);
        new(&(TCHandlingTask::savedMessage)) etl::string<MaxTCSize>;
        currentReadLocation = 0;
    } else {
        savedMessage[currentReadLocation++] = byteIn;
    }
}

void TCHandlingTask::execute() {
    while (true) {
        xQueueReceive(messageQueue, static_cast<void *>(&messageOut), portMAX_DELAY);

        char message[MaxTCSize];

        auto ecssTC = MessageParser::parseECSSTC(reinterpret_cast<const uint8_t *>(messageOut.c_str()));

        MessageParser::execute(ecssTC);
//        LOG_DEBUG << "Received new  TC[" << "," << "]";
    }
}
