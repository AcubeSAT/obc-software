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

TCHandlingTask::TCHandlingTask() : Task("TCHandling") {


    byteQueue = xQueueCreate(ByteQueueLength, sizeof(char));

    USART1_Read(&byteIn, sizeof(byteIn));

    USART1_ReadCallbackRegister([](uintptr_t object) {
        TCHandlingTask *TCTask = reinterpret_cast<TCHandlingTask *>(object);
        BaseType_t xHigherPriorityTaskWoken;
        if (USART1_ReadCountGet() == 0) {
            ErrorHandler::reportInternalError(ErrorHandler::InternalErrorType::UsartFailedRead);
        } else {
            xQueueSendToBackFromISR(TCTask->byteQueue, static_cast<void *>(&TCTask->byteIn), nullptr);
        }

        USART1_Read(&(TCTask->byteIn), sizeof(TCTask->byteIn));
    }, reinterpret_cast<uintptr_t>(this));
}


void TCHandlingTask::createTC() {
    char byteOut;
    xQueueReceive(byteQueue, static_cast<void *>(&byteOut), portMAX_DELAY);
    if (byteOut == 0x69) {
        messageComplete = true;
        currentReadLocation = 0;
    } else {
        byteBuffer.message[currentReadLocation++] = byteOut;
    }
}

void TCHandlingTask::execute() {
    while (true) {
        createTC();
        if (messageComplete) {
            messageComplete = false;

            auto cobsDecodedMessage = COBSdecode<ByteBufferSize>(
                    reinterpret_cast<uint8_t *>(byteBuffer.message),
                    ByteBufferSize);

            uint8_t message[ByteBufferSize];
            std::copy(std::begin(cobsDecodedMessage), std::end(cobsDecodedMessage), std::begin(message));


            ECSSMessage ecssTC = MessageParser::parse(message, ByteBufferSize);
            MessageParser::execute(ecssTC);

            LOG_DEBUG << "Received new  TC[" << ecssTC.serviceType << "," << ecssTC.messageType << "]";
            new(&(byteBuffer)) Buffer{};
        }
    }
}
