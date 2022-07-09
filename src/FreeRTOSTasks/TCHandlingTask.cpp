#include <optional>
#include "FreeRTOSTasks/TCHandlingTask.hpp"
#include <Logger.hpp>
#include <definitions.h>
#include <MessageParser.hpp>
#include <cobs.h>
#include "COBS.h"
#include "etl/compare.h"

using ECSSMessage = Message;

TCHandlingTask::TCHandlingTask() {

    messageQueue = xQueueCreate(messageQueueLength, sizeof(Message));

    byteQueue = xQueueCreate(byteQueueLength, sizeof(char));

    USART1_Read(&byteIn, 1);

    USART1_ReadCallbackRegister([](uintptr_t object) {
        TCHandlingTask *TCTask = reinterpret_cast<TCHandlingTask *>(object);

        if (USART1_ReadCountGet() == 0) {
            ErrorHandler::reportInternalError(ErrorHandler::InternalErrorType::UsartFailedRead);
        } else {
            TCTask->ingress();
        }
        USART1_Read(&(TCTask->byteIn), 1);
    }, reinterpret_cast<uintptr_t>(this));
}

void TCHandlingTask::ingress() {
    xQueueSendToBackFromISR(byteQueue, static_cast<void *>(&byteIn), nullptr);
    currentReadLocation = 0;
    if (currentReadLocation == byteBufferSize) {
        overrun = true;
        currentReadLocation = 0;
    }
}


void TCHandlingTask::createTC() {
    while(!messageComplete) {
        char byteOut;
        xQueueReceive(byteQueue, static_cast<void *>(&byteOut), portMAX_DELAY);
        byteBuffer.message[currentReadLocation++] = byteOut;
        if(byteOut == 0) {
            currentReadLocation = 0;
            messageComplete = true;
        }
    }
}

void TCHandlingTask::execute() {
    while (true) {
        createTC();
        messageComplete = false;
    }
}
