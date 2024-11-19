#include  "TimeSyncTask.hpp"

static void updateTimeOnReset(const Time::DefaultCUC& time)
{
    Time::DefaultCUC time1 = time;
    UTCTimestamp utc = time1.toUTCtimestamp();
    const int MonthOffset = -1;
    tm now{utc.second, utc.minute, utc.hour, utc.day, utc.month + MonthOffset, utc.year, 0, 0, 0};
    RTC_TimeSet(&now);
    timeSyncTask->setTimeRequested(true);
    xTaskNotifyGive(timeSyncTask->taskHandle);
    AcubeSATParameters::adcsOnBoardTime.unsetNotifier();
}

void TimeSyncTask::execute()
{
    while (true){
        if (timeSyncTask.has_value()){
            if (timeRequested == false){
                vTaskDelay(pdMS_TO_TICKS(1000));
                AcubeSATParameters::adcsOnBoardTime.setNotifier(updateTimeOnReset);
                CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,
                                                                 {AcubeSATParameters::ADCSOnBoardTime}, false);
                ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
            }else{
                vTaskDelay(pdMS_TO_TICKS(100));
                CAN::Application::sendUTCTimeMessage();
                vTaskDelay(pdMS_TO_TICKS(TimeSyncPeriod));
            }
        }else{
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
}
