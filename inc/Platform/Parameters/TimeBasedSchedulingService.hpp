#ifndef ECSS_SERVICES_TIMEBASESCHEDULING_HPP
#define ECSS_SERVICES_TIMEBASESCHEDULING_HPP

#include "PlatformParameters.hpp"

namespace TimeBasedActivities {
    static etl::array<Message, ECSSMaxNumberOfTimeSchedActivities> Activities = {
            {Message(), Message(), Message(), Message(), Message(), Message(), Message()}
    };
}

#endif
