#ifndef ECSS_SERVICES_PLATFORMPARAMETERS_HPP
#define ECSS_SERVICES_PLATFORMPARAMETERS_HPP

#include "Helpers/Parameter.hpp"
#include "Helpers/TimeAndDate.hpp"

namespace PlatformParameters {
    /**
     * ID enumeration of OBDH subsystem's specific parameters
     */
    enum ParameterID : uint16_t {
        OnBoardYear = 0,
        OnBoardMonth = 1,
        OnBoardDay = 2,
        OnBoardHour = 3,
        OnBoardMinute = 4,
        OnBoardSecond = 5,
        StackUsage1 = 6,
        StackUsage2 = 7
    };

    /**
     * Declaration of OBDH subsystem's specific parameters
     */
    inline Parameter<uint16_t> currentYear(2022);
    inline Parameter<uint8_t> currentMonth(2);
    inline Parameter<uint8_t> currentDay(19);
    inline Parameter<uint8_t> currentHour(6);
    inline Parameter<uint8_t> currentMinute(48);
    inline Parameter<uint8_t> currentSecond(32);
    inline Parameter<uint16_t> taskStackUsage1(0);
    inline Parameter<uint16_t> taskStackUsage2(0);
}

#endif