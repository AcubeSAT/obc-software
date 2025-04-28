#pragma once

#include "Helpers/Parameter.hpp"
#include "OBC_Definitions.hpp"
#include "AcubeSATParameters.hpp"

namespace CommonParameters {
    inline auto &boardTemperature1 = AcubeSATParameters::obcPCBTemperature1;
    inline auto &boardTemperature2 = AcubeSATParameters::obcPCBTemperature2;
    inline auto &mcuTemperature = AcubeSATParameters::obcMCUTemperature;
    inline auto &time = AcubeSATParameters::obcOnBoardTime;
    inline auto &useRTT = AcubeSATParameters::obcUseRTT;
    inline auto &useUART = AcubeSATParameters::obcUseUART;
    inline auto &useCAN = AcubeSATParameters::obcUseCAN;
}
