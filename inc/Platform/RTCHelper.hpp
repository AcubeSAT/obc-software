#ifndef OBC_SOFTWARE_RTCHELPER_HPP
#define OBC_SOFTWARE_RTCHELPER_HPP

#include "PlatformParameters.hpp"

const uint16_t yearBase = 1900;

/**
 * This function sets the epoch time.
 * @param dateTime is a tm struct witch keeps the time from MCU.
 */
void setEpoch(struct tm &dateTime) {
    dateTime.tm_sec = PlatformParameters::onBoardSecond.getValue();
    dateTime.tm_min = PlatformParameters::onBoardMinute.getValue();
    dateTime.tm_hour = PlatformParameters::onBoardHour.getValue();
    dateTime.tm_mon = PlatformParameters::onBoardMonth.getValue() - 1;
    dateTime.tm_mday = PlatformParameters::onBoardDay.getValue();
    dateTime.tm_year = PlatformParameters::onBoardYear.getValue() - yearBase;
}

/**
 * This function sets the AcubeSAT's time parameters using a tm struct.
 * @param dateTime is a tm struct witch keeps the time from MCU.
 */
void setTimePlatformParameters(struct tm &dateTime) {
    PlatformParameters::onBoardSecond.setValue(dateTime.tm_sec);
    PlatformParameters::onBoardMinute.setValue(dateTime.tm_min);
    PlatformParameters::onBoardHour.setValue(dateTime.tm_hour);
    PlatformParameters::onBoardDay.setValue(dateTime.tm_mday);
    PlatformParameters::onBoardMonth.setValue(dateTime.tm_mon + 1);
    PlatformParameters::onBoardYear.setValue(dateTime.tm_year + yearBase);
}

/**
 * This function prints the on-board time.
 */
void printOnBoardTime() {
    etl::string<29> printTime = "";
    printTime+="\rTime:";
    etl::to_string(PlatformParameters::onBoardHour.getValue(),printTime,true);
    printTime+="-";
    etl::to_string(PlatformParameters::onBoardMinute.getValue(),printTime,true);
    printTime+="-";
    etl::to_string(PlatformParameters::onBoardSecond.getValue(),printTime,true);
    printTime+=" -- ";
    etl::to_string(PlatformParameters::onBoardDay.getValue(),printTime,true);
    printTime+="/";
    etl::to_string(PlatformParameters::onBoardMonth.getValue(),printTime,true);
    printTime+="/";
    etl::to_string(PlatformParameters::onBoardYear.getValue(),printTime,true);
    printTime+="\n";
    LOG_DEBUG << printTime.data();
}

#endif //OBC_SOFTWARE_RTCHELPER_HPP
