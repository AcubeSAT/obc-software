#include "FreeRTOSTasks/TimeBasedSchedulingTask.hpp"

void TimeBasedSchedulingTask::execute() {
    static etl::array<Message, ECSSMaxNumberOfTimeSchedActivities> activities = {
            {Message(), Message(), Message(), Message(), Message(), Message(), Message()}
    };

    auto &timeBasedScheduling = Services.timeBasedScheduling;
    Message TCMessage(TimeBasedSchedulingService::ServiceType,
                      TimeBasedSchedulingService::MessageType::InsertActivities, Message::TC, 1);
    TCMessage.appendUint16(7);

    uint16_t i = 0;
    for (auto &message: activities) {
        message.serviceType = 17;
        message.messageType = 1;
        message.packetType = Message::TC;
        Time::CustomCUC_t exe;
        Time::CustomCUC_t now = TimeGetter::getCurrentTimeCustomCUC();
        exe = now + 80 + i;
        i += 4;
        TCMessage.append(exe);
        TCMessage.appendMessage(message, ECSSTCRequestStringSize);
    }

    MessageParser::execute(TCMessage);

    TickType_t xLastWakeTime = xTaskGetTickCount();

    Message receivedMessage(TimeBasedSchedulingService::ServiceType,
                            TimeBasedSchedulingService::MessageType::DetailReportAllScheduledActivities,
                            Message::TC, 1);
    while (true) {
        Time::CustomCUC_t now = TimeGetter::getCurrentTimeCustomCUC();
        auto nextActivityExecutionCUCTime = timeBasedScheduling.popScheduledActivity(now);
        TickType_t nextActivityExecutionTime = (nextActivityExecutionCUCTime - now).getMs();
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextActivityExecutionTime));

        MessageParser::execute(receivedMessage);
    }
}
