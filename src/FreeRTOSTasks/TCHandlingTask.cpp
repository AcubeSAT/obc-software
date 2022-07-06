#include <optional>
#include "FreeRTOSTasks/TCHandlingTask.hpp"
#include <Logger.hpp>
#include <definitions.h>
#include <MessageParser.hpp>
#include <cobs.h>
#include "COBS.h"
#include "etl/compare.h"

using ECSSMessage = Message;
uint8_t ctr = 0;

TCHandlingTask::TCHandlingTask() {

    messageQueue = xQueueCreate(messageQueueLength, sizeof(Message));

    byteQueue = xQueueCreate(byteQueueLength, sizeof(char));

    USART1_Read(&byteIn, 1);

    USART1_ReadCallbackRegister([](uintptr_t object) {
        TCHandlingTask *TCTask = reinterpret_cast<TCHandlingTask *>(object);

        if (USART1_ReadCountGet() == 0) {
            ErrorHandler::reportInternalError(ErrorHandler::InternalErrorType::UsartFailedRead);
        } else {
            xQueueSendToBackFromISR(TCTask->byteQueue, static_cast<void *>(&TCTask->byteIn), nullptr);
        }
        USART1_Read(&(TCTask->byteIn), 1);
    }, reinterpret_cast<uintptr_t>(this));
}

void TCHandlingTask::createTC() {
    char byteOut;
    xQueueReceive(byteQueue, static_cast<void *>(&byteOut), portMAX_DELAY);
    byteBuffer.message[currentReadLocation++] = byteOut;
    if(byteOut == 0) {
        xQueueSendToBack(messageQueue, static_cast<void *>(&byteBuffer.message), portMAX_DELAY);
        messageComplete = true;
        currentReadLocation = 0;
    }
}

void TCHandlingTask::execute() {
    while (true) {
        createTC();
        if (messageComplete) {
            Buffer output{""};
            xQueueReceive(messageQueue, static_cast<void *>(&output.message), portMAX_DELAY);
            messageComplete = false;
            LOG_DEBUG << "message is" << byteBuffer.message;
            byteBuffer = Buffer{""};
        }
    }
}
