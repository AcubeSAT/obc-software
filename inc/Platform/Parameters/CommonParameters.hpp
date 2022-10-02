#pragma once

#include "Helpers/Parameter.hpp"
#include "OBC_Definitions.hpp"
#include "PlatformParameters.hpp"

namespace CommonParameters {
    inline auto &boardTemperature1 = PlatformParameters::obcPCBTemperature1;
    inline auto &mcuTemperature = PlatformParameters::obcMCUTemperature;
    inline auto &time = PlatformParameters::obcMCUTime;
    inline auto &useRTT = PlatformParameters::obcUseRTT;
    inline auto &useUART = PlatformParameters::obcUseUART;
    inline auto &useCAN = PlatformParameters::obcUseCAN;
}
