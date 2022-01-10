#ifndef ECSS_SERVICES_PLATFORMPARAMETERS_HPP
#define ECSS_SERVICES_PLATFORMPARAMETERS_HPP

#include "Helpers/Parameter.hpp"
#include "OBC_Definitions.hpp"

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
        AvailableStack = 6,
        AvailableHeap = 7,
        OBCBootCounter = 301,
        OBCSystick = 329
    };

     // Parameters used for testing //
    inline Parameter<uint16_t> currentYear(2022);
    inline Parameter<uint8_t> currentMonth(2);
    inline Parameter<uint8_t> currentDay(19);
    inline Parameter<uint8_t> currentHour(6);
    inline Parameter<uint8_t> currentMinute(48);
    inline Parameter<uint8_t> currentSecond(32);
    inline Parameter<uint16_t> reportParametersAvailableStack(FreeRTOSTaskStackDepth);
    inline Parameter<uint16_t> availableHeap(0);

    // OBDH parameters //
    inline Parameter<uint16_t> obcBootCounter(0);
    inline Parameter<uint64_t> obcSysTick(0);
}

#endif
