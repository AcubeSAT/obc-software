#ifndef OBC_SOFTWARE_RTCHELPER_HPP
#define OBC_SOFTWARE_RTCHELPER_HPP

#include "PlatformParameters.hpp"

void setEpoch(struct tm &dateTime) {
    dateTime.tm_sec = PlatformParameters::onBoardSecond.getValue();
    dateTime.tm_min = PlatformParameters::onBoardMinute.getValue();
    dateTime.tm_hour = PlatformParameters::onBoardHour.getValue();
    dateTime.tm_mon = PlatformParameters::onBoardMonth.getValue() - 1;
    dateTime.tm_mday = PlatformParameters::onBoardDay.getValue();
    dateTime.tm_year = PlatformParameters::onBoardYear.getValue() - 1900;
}

#endif //OBC_SOFTWARE_RTCHELPER_HPP
