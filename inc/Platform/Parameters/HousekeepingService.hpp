#ifndef ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP
#define ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP

#include "PlatformParameters.hpp"
#include "Services/HousekeepingService.hpp"

namespace HousekeepingStructures {
    etl::array<HousekeepingStructure, ECSSMaxHousekeepingStructures> structures = {
            {0, 900, 900, true,
             {PlatformParameters::OnBoardSecond, PlatformParameters::AvailableHeap},
             1, 1000, 900, true,
             {PlatformParameters::OnBoardDay, PlatformParameters::OnBoardHour, PlatformParameters::OnBoardMinute}
            },
    };
}


#endif