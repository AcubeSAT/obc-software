#include "Helpers/TimeGetter.hpp"
#include "CommonParameters.hpp"

UTCTimestamp TimeGetter::getCurrentTimeUTC() {
    return getCurrentTimeDefaultCUC().toUTCtimestamp();
}

Time::DefaultCUC TimeGetter::getCurrentTimeDefaultCUC() {
    return CommonParameters::time.getValue();
}