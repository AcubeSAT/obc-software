#include "FreeRTOSTasks/TimeBasedSchedulingTask.hpp"

void TimeBasedSchedulingTask::execute() {
    static etl::array<Message, ECSSMaxNumberOfTimeSchedActivities> activities = {
            {Message(), Message(), Message(), Message(), Message(), Message(), Message()}
    };

    auto &timeBasedScheduling = Services.timeBasedScheduling;
    Message TCMessage(TimeBasedSchedulingService::ServiceType,
                      TimeBasedSchedulingService::MessageType::InsertActivities, Message::TC, 1);
    TCMessage.appendUint16(7);

    for (auto &message: activities) {
        message.serviceType = 17;
        message.messageType = 1;
        message.packetType = Message::TC;
        Time::CustomCUC_t exe;
        Time::CustomCUC_t now = TimeGetter::getCurrentTimeCustomCUC();
        exe = now + 80;
        TCMessage.append(exe);
        TCMessage.appendMessage(message, ECSSTCRequestStringSize);
    }

    MessageParser::execute(TCMessage);
    TCMessage.readPosition = 0;

    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (true) {
        auto activity = timeBasedScheduling.getScheduledActivities();

        Time::CustomCUC_t now = TimeGetter::getCurrentTimeCustomCUC();
        TickType_t nextActivity = activity.requestReleaseTime.elapsed100msTicks - now.elapsed100msTicks;
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextActivity*100));

        MessageParser::execute(activity.request);

        Message receivedMessage(TimeBasedSchedulingService::ServiceType,
                                TimeBasedSchedulingService::MessageType::DetailReportAllScheduledActivities,
                                Message::TC, 1);
        MessageParser::execute(receivedMessage);
    }
}
