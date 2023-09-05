#ifndef ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP
#define ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP

#include "PeakSatParameters.hpp"
#include "Services/HousekeepingService.hpp"

namespace HousekeepingStructures {
    using namespace PeakSatParameters;

    static etl::array<HousekeepingStructure, ECSSMaxHousekeepingStructures> structures = {
            {
                    // OBC Parameters that will be monitored in the campaign
                    {0, 1000, true,
                     {OBCPCBTemperature1,
                      OBCPCBTemperature2,
                      OBCMCUTemperature,
                      OBCMCUBootCounter,
                      OBCMemoryPartition,
                      OBCMCUSystick,
                      OBCCANBUSLoad1,
                      OBCCANBUSLoad2,
                      OBCCANBUSActive,
                      OBCNANDFLASHLCLThreshold,
                      OBCMRAMLCLThreshold,
                      OBCNANDFLASHON,
                      OBCMRAMON,
                      OBCUseCAN,
                      OBCUseUART,
                      OBCUseRTT,
                      OBCOnBoardTime}},
                    // OBC Mission Database parameters monitored every 3 sec
                    {1, 3000, true,
                     {OBCPCBTemperature1,
                      OBCPCBTemperature2,
                      OBCSpacecraftTimeRef,
                      OBCOperationalMode,
                      OBCMemoryPartition,
                      OBCReconfigurationTimer,
                      OBCLastFailedEvent,
                      OBCMCUSystick
                     }},
                    // OBC Mission Database parameters not sampled
                    {2, 5000, false,
                     {OBCMCUInputVoltage,
                      OBCFlashInt,
                      OBCSRAMInt,
                      OBCAvailableMRAM,
                      OBCAvailableNAND,
                      OBCCANBUSLoad1,
                      OBCCANBUSLoad2,
                      OBCCANBUSActive,
                      OBCMCUFDIR,
                      OBCMCURestartSafeModeThreshold,
                      OBCNANDFLASHLCLThreshold,
                      OBCMRAMLCLThreshold,
                      OBCNANDFLASHON,
                      OBCNANDFLASHScrubbingFrequency,
                      OBCRAMScrubbingFrequency,
                      OBCProgramFlashScrubbingFrequency}},

            }
    };
}

#endif
