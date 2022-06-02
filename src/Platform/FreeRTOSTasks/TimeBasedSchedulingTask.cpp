#include "FreeRTOSTasks/TimeBasedSchedulingTask.hpp"

void TimeBasedSchedulingTask::execute() {
        auto &timeBasedScheduling = Services.timeBasedScheduling;

        Message TCMessage(TimeBasedSchedulingService::ServiceType,TimeBasedSchedulingService::MessageType::InsertActivities, Message::TC, 1);
        TCMessage.appendUint16(3);

        for (auto &message: TimeBasedActivities::Activities) {
            message.serviceType = 6;
            message.messageType = 5;
            message.packetType = Message::TC;
            message.applicationId = 8; // dummy ID
            message.appendUint16(4864); // dummy data
            TCMessage.appendUint32(6325772);
            TCMessage.appendMessage(message, ECSSTCRequestStringSize);
        }

        timeBasedScheduling.insertActivities(TCMessage);

        while (true) {
            Message receivedMessage(TimeBasedSchedulingService::ServiceType,
                                    TimeBasedSchedulingService::MessageType::DetailReportAllScheduledActivities,
                                    Message::TC, 1);
            timeBasedScheduling.detailReportAllActivities(receivedMessage);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
}
