#ifndef ECSS_SERVICES_PLATFORMPARAMETERS_HPP
#define ECSS_SERVICES_PLATFORMPARAMETERS_HPP

#include "Helpers/Parameter.hpp"
#include "OBC_Definitions.hpp"
#include "inc/Platform/FreeRTOSTasks/Task.hpp"

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
        OBCMCUTemperature = 293,
        OBCBootCounter = 301,
        OBCSystick = 329,
    };

     // Parameters used for testing
    inline Parameter<uint16_t> onBoardYear(2022);
    inline Parameter<uint8_t> onBoardMonth(2);
    inline Parameter<uint8_t> onBoardDay(19);
    inline Parameter<uint8_t> onBoardHour(6);
    inline Parameter<uint8_t> onBoardMinute(48);
    inline Parameter<uint8_t> onBoardSecond(32);
    inline Parameter<uint16_t> reportParametersUnusedStack(FreeRTOSTaskStackDepth);
    inline Parameter<uint16_t> availableHeap(0);

    // OBDH parameters
    inline Parameter<uint16_t> obcBootCounter(0);
    inline Parameter<uint64_t> obcSysTick(0);
    inline Parameter<float> mcuTemperature(0);
}

#endif
