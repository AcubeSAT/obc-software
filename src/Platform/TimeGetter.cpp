#include "TimeGetter.hpp"

UTCTimestamp TimeGetter::getCurrentTimeUTC() {
    using namespace PlatformParameters;
    UTCTimestamp currentTime(onBoardYear.getValue(), onBoardMonth.getValue(),
                             onBoardDay.getValue(), onBoardHour.getValue(), onBoardMinute.getValue(),
                             onBoardSecond.getValue());
    return currentTime;
}

uint64_t TimeGetter::getCurrentTimeCustomCUC() {
    UTCTimestamp timeUTC = getCurrentTimeUTC();
    TimeStamp<Time::CUCSecondsBytes, Time::CUCFractionalBytes> timeCUC(timeUTC);
    TimeGetter::CUCTimeFormat CUCtime = timeCUC.asCustomCUCTimestamp().elapsed100msTicks;
    return CUCtime;
}