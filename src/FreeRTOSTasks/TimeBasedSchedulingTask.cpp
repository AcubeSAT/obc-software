#include "FreeRTOSTasks/TimeBasedSchedulingTask.hpp"

void TimeBasedSchedulingTask::execute() {
    auto &timeBasedScheduling = Services.timeBasedScheduling;
    Message TCMessage(TimeBasedSchedulingService::ServiceType,
                      TimeBasedSchedulingService::MessageType::InsertActivities, Message::TC, 1);
    TCMessage.appendUint16(4);
    int i = 0;
    for (auto &message: TimeBasedActivities::Activities) {
        message.serviceType = 17;
        message.messageType = 1;
        message.packetType = Message::TC;
        Time::CustomCUC_t exe;
        Time::CustomCUC_t now = TimeGetter::getCurrentTimeCustomCUC();
        exe = now + i;
        TCMessage.append(exe);
        TCMessage.appendMessage(message, ECSSTCRequestStringSize);
        i += 1000;
    }

    timeBasedScheduling.insertActivities(TCMessage);
    TCMessage.readPosition = 0;

    Message receivedMessage1(TimeBasedSchedulingService::ServiceType,
                             TimeBasedSchedulingService::MessageType::EnableTimeBasedScheduleExecutionFunction,
                             Message::TC, 1);
    timeBasedScheduling.enableScheduleExecution(receivedMessage1);

    TickType_t xLastWakeTime = xTaskGetTickCount();

    int j = 0;
    while (true) {
        auto activity = timeBasedScheduling.getScheduledActivities();

        Time::CustomCUC_t now = TimeGetter::getCurrentTimeCustomCUC();
        TickType_t nextActivity = activity.requestReleaseTime.elapsed100msTicks - now.elapsed100msTicks;
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextActivity * 10));

        MessageParser::execute(activity.request);

//        Message receivedMessage(TimeBasedSchedulingService::ServiceType,
//                                TimeBasedSchedulingService::MessageType::DetailReportAllScheduledActivities,
//                                Message::TC, 1);
//        timeBasedScheduling.detailReportAllActivities(receivedMessage);
    }
}
