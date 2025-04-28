#include  "TimeSyncTask.hpp"

static void updateTimeOnReset(const Time::DefaultCUC& constAdcsCurrentTime) {
    if (timeSyncTask->taskHandle != nullptr) {
        Time::DefaultCUC adcsCurrentTime = constAdcsCurrentTime;
        UTCTimestamp utc = adcsCurrentTime.toUTCtimestamp();
        tm currentTime{
            utc.second, utc.minute, utc.hour, utc.day, utc.month + CAN::Application::MonthOffset, utc.year, 0, 0, 0
        };
        RTC_TimeSet(&currentTime);
        timeSyncTask->setTimeRequested(true);
        xTaskNotifyGive(timeSyncTask->taskHandle);
        AcubeSATParameters::adcsOnBoardTime.unsetNotifier();
    }
}

void TimeSyncTask::execute() {
    while (true) {
        if (not timeRequested) {
            vTaskDelay(pdMS_TO_TICKS(TimeRequestDelay));
            AcubeSATParameters::adcsOnBoardTime.setNotifier(updateTimeOnReset,false);
            CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{AcubeSATParameters::ADCSOnBoardTime}, false);
            timeSyncTask->setTimeRequested(true);
            ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        } else {
            vTaskDelay(pdMS_TO_TICKS(TimeSendDelay));
            CAN::Application::sendUTCTimeMessage();
            vTaskDelay(pdMS_TO_TICKS(TimeSyncPeriod));
        }
    }
}
