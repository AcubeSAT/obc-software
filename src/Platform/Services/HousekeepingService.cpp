#include "Parameters/HousekeepingService.hpp"

void HousekeepingService::initializeHousekeepingStructures() {
    ::housekeepingStructureParameters p;

    for (uint8_t i = 0; i < p.structIds.size(); i++) {
        createHousekeepingReportStructure(p.structIds[i], p.collectionIntervals[p.structIds[i]],
                                          p.numsOfSimplyCommutatedParams[p.structIds[i]],
                                          p.structureParameters[p.structIds[i]]);
        enablePeriodicHousekeepingParametersReport(p.structIds.size(), p.structIds);
    }
}