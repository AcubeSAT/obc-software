#include "FreeRTOSTasks/TestServiceTask.hpp"

void TestServiceTask::execute() {
    auto &testService = Services.testService;
    Message message = Message(TestService::ServiceType, TestService::MessageType::AreYouAliveTest, Message::TC, 1);
    while (true) {
        MessageParser::execute(message);
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}


