#include "Helpers/TimeGetter.hpp"
#include "PlatformParameters.hpp"

UTCTimestamp TimeGetter::getCurrentTimeUTC() {
    using namespace PlatformParameters;
    UTCTimestamp currentTime(onBoardYear.getValue(), onBoardMonth.getValue(),
                             onBoardDay.getValue(), onBoardHour.getValue(), onBoardMinute.getValue(),
                             onBoardSecond.getValue());
    return currentTime;
}

Time::CustomCUC_t TimeGetter::getCurrentTimeCustomCUC() {
    UTCTimestamp timeUTC = getCurrentTimeUTC();
    TimeStamp<Time::CUCSecondsBytes, Time::CUCFractionalBytes> timeCUC(timeUTC);
    Time::CustomCUC_t CUCtime = timeCUC.asCustomCUCTimestamp();
    return CUCtime;
}