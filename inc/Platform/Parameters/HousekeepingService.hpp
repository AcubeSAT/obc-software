#ifndef ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP
#define ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP

#include "PlatformParameters.hpp"
#include "Services/HousekeepingService.hpp"

namespace HousekeepingStructures {
    using namespace PlatformParameters;

    static etl::array<HousekeepingStructure, ECSSMaxHousekeepingStructures> structures = {
            {
                    {0, 1000, true, {OBCPCBTemperature1, OBCPCBTemperature2, OBCMCUTemperature, OBCMCUInputVoltage,
                                     OBCMCUBootCounter}},
                    {1, 1000, true, {OBCAFlashInt, OBCASRAMInt, OBCOFLASHInt, OBCOSRAMInt, OBCMRAM, OBCNAND}},
                    {2, 1000, true,
                     {OBCSpacecraftTimeRef, OBCMCUTime, OBCOperationalMode, OBCMemoryPartition, OBCReconfigurationTimer,
                      OBCLastFailedEvent, OBCMCUSystick}},
                    {3, 1000, true,
                     {OBCCANBUSLoad1, OBCCANBUSLoad1, OBCCANBUSActive, OBCMCUFDIR, OBCMCURestartSafeModeThreshold,
                      OBCNANDFLASHLCLThreshold, OBCMRAMLCLThreshold, OBCNANDFLASHON, OBCMRAMON}},
                    {4, 1000, true,
                     {OBCNANDFLASHScrubbingFrequency, OBCRAMScrubbingFrequency, OBCProgramFlashScrubbingFrequency}},
            }
    };
}


#endif