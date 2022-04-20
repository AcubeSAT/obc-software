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
Logger::LogEntry &operator<<(Logger::LogEntry &entry, const std::string &value) {
    entry.message.append("\rTime:");
    etl::to_string(PlatformParameters::onBoardHour.getValue(), entry.message, true);
    entry.message.append("-");
    etl::to_string(PlatformParameters::onBoardMinute.getValue(), entry.message, true);
    entry.message.append("-");
    etl::to_string(PlatformParameters::onBoardSecond.getValue(), entry.message, true);
    entry.message.append(" -- ");
    etl::to_string(PlatformParameters::onBoardDay.getValue(), entry.message, true);
    entry.message.append("/");
    etl::to_string(PlatformParameters::onBoardMonth.getValue(), entry.message, true);
    entry.message.append("/");
    etl::to_string(PlatformParameters::onBoardYear.getValue(), entry.message, true);

    return entry;
}

#endif //OBC_SOFTWARE_RTCHELPER_HPP
