#ifndef OBC_SOFTWARE_RTCHELPER_HPP
#define OBC_SOFTWARE_RTCHELPER_HPP

#include "PlatformParameters.hpp"

const uint16_t yearBase = 1900;

void setEpoch(struct tm &dateTime) {
    dateTime.tm_sec = PlatformParameters::onBoardSecond.getValue();
    dateTime.tm_min = PlatformParameters::onBoardMinute.getValue();
    dateTime.tm_hour = PlatformParameters::onBoardHour.getValue();
    dateTime.tm_mon = PlatformParameters::onBoardMonth.getValue() - 1;
    dateTime.tm_mday = PlatformParameters::onBoardDay.getValue();
    dateTime.tm_year = PlatformParameters::onBoardYear.getValue() - yearBase;
}

void setTimePlatformParameters(struct tm &dateTime) {
    PlatformParameters::onBoardSecond.setValue(dateTime.tm_sec);
    PlatformParameters::onBoardMinute.setValue(dateTime.tm_min);
    PlatformParameters::onBoardHour.setValue(dateTime.tm_hour);
    PlatformParameters::onBoardDay.setValue(dateTime.tm_mday);
    PlatformParameters::onBoardMonth.setValue(dateTime.tm_mon + 1);
    PlatformParameters::onBoardYear.setValue(dateTime.tm_year + yearBase);
}

void printOnBoardTime() {
    LOG_DEBUG << "\rTime:"
              << PlatformParameters::onBoardHour.getValue() << "-"
              << PlatformParameters::onBoardMinute.getValue() << "-"
              << PlatformParameters::onBoardSecond.getValue() << " -- "
              << PlatformParameters::onBoardDay.getValue() << "/"
              << PlatformParameters::onBoardMonth.getValue() << "/"
              << PlatformParameters::onBoardYear.getValue()
              << "\n";
}


#endif //OBC_SOFTWARE_RTCHELPER_HPP
