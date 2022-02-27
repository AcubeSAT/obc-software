#ifndef ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP
#define ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP

#include "PlatformParameters.hpp"
#include "Services/HousekeepingService.hpp"

struct housekeepingStructureParameters {
    etl::vector<uint8_t, ECSSMaxHousekeepingStructures> structIds = {0, 1};
    etl::vector<uint32_t, ECSSMaxHousekeepingStructures> collectionIntervals = {500, 500};
    etl::vector<uint16_t, ECSSMaxHousekeepingStructures> numsOfSimplyCommutatedParams = {2, 3};
    etl::vector<etl::vector<uint16_t, ECSSMaxSimplyCommutatedParameters>, ECSSMaxHousekeepingStructures> structureParameters =
            {{PlatformParameters::OnBoardSecond, PlatformParameters::AvailableHeap},
             {PlatformParameters::OnBoardDay,    PlatformParameters::OnBoardHour, PlatformParameters::OnBoardMinute}};
};

#endif