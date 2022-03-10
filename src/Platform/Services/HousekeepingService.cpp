#include "ECSS_Configuration.hpp"

#ifdef SERVICE_HOUSEKEEPING

#include "Services/HousekeepingService.hpp"
#include "Parameters/HousekeepingService.hpp"

void HousekeepingService::initializeHousekeepingStructures() {
    HousekeepingStructure structure;
    HousekeepingStructureParameters parameters;
    
    for (uint8_t idx = 0; idx < parameters.structIds.size(); idx++) {
        structure.structureId = parameters.structIds.at(idx);
        structure.periodicGenerationActionStatus = parameters.periodicGenerationStatuses.at(idx);
        structure.timeToNextReport = parameters.collectionIntervals.at(idx);
        structure.collectionInterval = parameters.collectionIntervals.at(idx);
        structure.simplyCommutatedParameterIds = parameters.structureParameters.at(idx);
        housekeepingStructures.insert({structure.structureId, structure});
    }
}

#endif