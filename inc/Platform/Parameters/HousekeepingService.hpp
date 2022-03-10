#ifndef ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP
#define ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP

#include "PlatformParameters.hpp"
#include "Services/HousekeepingService.hpp"

struct HousekeepingStructureParameters {
    etl::vector<uint8_t, ECSSMaxHousekeepingStructures> structIds = {0, 1};
    etl::vector<uint32_t, ECSSMaxHousekeepingStructures> collectionIntervals = {900, 1000};
    etl::vector<bool, ECSSMaxHousekeepingStructures> periodicGenerationStatuses = {true, true};
    etl::vector<etl::vector<uint16_t, ECSSMaxSimplyCommutatedParameters>, ECSSMaxHousekeepingStructures> structureParameters =
            {{PlatformParameters::OnBoardSecond, PlatformParameters::AvailableHeap},
             {PlatformParameters::OnBoardDay,    PlatformParameters::OnBoardHour, PlatformParameters::OnBoardMinute}};
};

#endif