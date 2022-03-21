#include "ECSS_Configuration.hpp"

#ifdef SERVICE_HOUSEKEEPING

#include "Services/HousekeepingService.hpp"
#include "Parameters/HousekeepingService.hpp"

void HousekeepingService::initializeHousekeepingStructures() {
    for (auto &structure: HousekeepingStructures::structures) {
        housekeepingStructures.insert({structure.structureId, structure});
    }
}

#endif