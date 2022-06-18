#include "FreeRTOSTasks/TimeKeepingTask.hpp"

void TimeKeepingTask::execute() {
    static tm dateTime;
    setEpoch(dateTime);
    RTC_TimeSet(&dateTime);

    while (true) {
        if (xTaskNotifyWait(0, 0, nullptr, portMAX_DELAY) == pdTRUE) {
            RTC_TimeGet(&dateTime);
            setTimePlatformParameters(dateTime);
            printOnBoardTime();
        }
    }
}

/**
 * This function prints the on-board time.
 */
void TimeKeepingTask::printOnBoardTime() {
    etl::string<29> printTime = "";
    printTime += "\rTime:";
    etl::to_string(PlatformParameters::onBoardHour.getValue(), printTime, true);
    printTime += "-";
    etl::to_string(PlatformParameters::onBoardMinute.getValue(), printTime, true);
    printTime += "-";
    etl::to_string(PlatformParameters::onBoardSecond.getValue(), printTime, true);
    printTime += " -- ";
    etl::to_string(PlatformParameters::onBoardDay.getValue(), printTime, true);
    printTime += "/";
    etl::to_string(PlatformParameters::onBoardMonth.getValue(), printTime, true);
    printTime += "/";
    etl::to_string(PlatformParameters::onBoardYear.getValue(), printTime, true);
    printTime += "\n";
    LOG_DEBUG << printTime.data();
}

void TimeKeepingTask::setTimePlatformParameters(tm &dateTime) {
    PlatformParameters::onBoardSecond.setValue(dateTime.tm_sec);
    PlatformParameters::onBoardMinute.setValue(dateTime.tm_min);
    PlatformParameters::onBoardHour.setValue(dateTime.tm_hour);
    PlatformParameters::onBoardDay.setValue(dateTime.tm_mday);
    PlatformParameters::onBoardMonth.setValue(dateTime.tm_mon + 1);
    PlatformParameters::onBoardYear.setValue(dateTime.tm_year + yearBase);

}

void TimeKeepingTask::setEpoch(tm &dateTime) {
    dateTime.tm_sec = PlatformParameters::onBoardSecond.getValue();
    dateTime.tm_min = PlatformParameters::onBoardMinute.getValue();
    dateTime.tm_hour = PlatformParameters::onBoardHour.getValue();
    dateTime.tm_mon = PlatformParameters::onBoardMonth.getValue() - 1;
    dateTime.tm_mday = PlatformParameters::onBoardDay.getValue();
    dateTime.tm_year = PlatformParameters::onBoardYear.getValue() - yearBase;

}
