#include "FreeRTOSTasks/TimeBasedSchedulingTask.hpp"

void TimeBasedSchedulingTask::execute() {
    auto &timeBasedScheduling = Services.timeBasedScheduling;
    Message TCMessage(TimeBasedSchedulingService::ServiceType,TimeBasedSchedulingService::MessageType::InsertActivities, Message::TC, 1);
    TCMessage.appendUint16(4);
    int i=0;
    for (auto &message: TimeBasedActivities::Activities) {
        message.serviceType = 17;
        message.messageType = 1;
        message.packetType = Message::TC;
        message.applicationId = 0;
        message.appendUint16(4864);
//        TCMessage.appendUint32(100+i);
        Time::CustomCUC_t currentTime;
        currentTime.elapsed100msTicks = xTaskGetTickCount()+10+i;
        TCMessage.appendCustomCUCTimeStamp(currentTime);
        TCMessage.appendMessage(message, ECSSTCRequestStringSize);
        i+=10;
    }

    timeBasedScheduling.insertActivities(TCMessage);
   //Message receivedMessage1(TimeBasedSchedulingService::ServiceType, TimeBasedSchedulingService::MessageType::EnableTimeBasedScheduleExecutionFunction, Message::TC, 1);
   //timeBasedScheduling.enableScheduleExecution(receivedMessage1);
   //MessageParser::execute(receivedMessage1);
    TCMessage.readPosition=0;
//  TickType_t xLastWakeTime = xTaskGetTickCount();

    auto activities = timeBasedScheduling.getScheduledActivities(timeBasedScheduling);
    while (true) {

        MessageParser::execute(TimeBasedActivities::Activities[0]);
        //MessageParser::execute(activities.at(0)->request);
       // vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(nextactivity));

//        Message receivedMessage(TimeBasedSchedulingService::ServiceType,
//                                TimeBasedSchedulingService::MessageType::DetailReportAllScheduledActivities,
//                                Message::TC, 1);
//        timeBasedScheduling.detailReportAllActivities(receivedMessage);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
