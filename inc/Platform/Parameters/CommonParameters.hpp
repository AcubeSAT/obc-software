#pragma once

#include "Helpers/Parameter.hpp"
#include "OBC_Definitions.hpp"
#include "PlatformParameters.hpp"

namespace CommonParameters {
    inline auto &boardTemperature1 = PlatformParameters::obcBoardTemperature1;
    inline auto &mcuTemperature = PlatformParameters::obcMCUTemperature;
    inline auto &onBoardYear = PlatformParameters::onBoardYear;
    inline auto &onBoardMonth = PlatformParameters::onBoardMonth;
    inline auto &onBoardDay = PlatformParameters::onBoardDay;
    inline auto &onBoardHour = PlatformParameters::onBoardHour;
    inline auto &onBoardMinute = PlatformParameters::onBoardMinute;
    inline auto &onBoardSecond = PlatformParameters::onBoardSecond;
    inline auto &useRTT = PlatformParameters::useRTT;
    inline auto &useUART = PlatformParameters::useUART;
    inline auto &useCAN = PlatformParameters::useCAN;
}
