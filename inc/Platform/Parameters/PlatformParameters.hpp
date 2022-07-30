#ifndef ECSS_SERVICES_PLATFORMPARAMETERS_HPP
#define ECSS_SERVICES_PLATFORMPARAMETERS_HPP

#include "Helpers/Parameter.hpp"

namespace PlatformParameters {
    /**
     * ID enumeration of OBDH subsystem's specific parameters.
     */
    enum ParameterID : uint16_t {
        OnBoardYear = 0,
        OnBoardMonth = 1,
        OnBoardDay = 2,
        OnBoardHour = 3,
        OnBoardMinute = 4,
        OnBoardSecond = 5,
        ReportParametersUnusedStack = 6,
        AvailableHeap = 7,
        OBCBoardTemperature1 = 290,
        OBCMCUTemperature = 293,
        OBCBootCounter = 301,
        OBCSystick = 329,
    };

    // Parameters used for testing
    inline Parameter<uint16_t> onBoardYear(2022);
    inline Parameter<uint8_t> onBoardMonth(1);
    inline Parameter<uint8_t> onBoardDay(1);
    inline Parameter<uint8_t> onBoardHour(0);
    inline Parameter<uint8_t> onBoardMinute(0);
    inline Parameter<uint8_t> onBoardSecond(0);
    inline Parameter<uint16_t> reportParametersUnusedStack(0);
    inline Parameter<uint16_t> availableHeap(0);

    // OBDH parameters
    inline Parameter<uint16_t> obcBootCounter(0);
    inline Parameter<uint64_t> obcSysTick(0);
    inline Parameter<float> mcuTemperature(0);
    inline Parameter<float> obcBoardTemperature1(0);
}

#endif
