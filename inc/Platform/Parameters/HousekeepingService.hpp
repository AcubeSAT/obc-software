#ifndef ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP
#define ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP

#include "AcubeSATParameters.hpp"
#include "Services/HousekeepingService.hpp"

namespace HousekeepingStructures {
    using namespace AcubeSATParameters;

    static etl::array <HousekeepingStructure, ECSSMaxHousekeepingStructures> structures = {
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
                    // ADCS Parameters that will be monitored every 0.01 sec in the campaign
                    {3, 10, false,
                     {ADCSMagnetometerRawX,
                      ADCSMagnetometerRawY,
                      ADCSMagnetometerRawZ,
                      ADCSGyroscopeRateX,
                      ADCSGyroscopeRateY,
                      ADCSGyroscopeRateZ}},
                    // ADCS Parameters that will be monitored every 3 seconds in the campaign
                    {4, 3000, true,
                     {ADCSMagnetometerFrequency,
                      ADCSMagnetometerCycleCountX,
                      ADCSMagnetometerCycleCountY,
                      ADCSMagnetometerCycleCountZ,
                      ADCSMagnetometerSelfTest,
                      ADCSGyroscopeXTemperature,
                      ADCSGyroscopeYTemperature,
                      ADCSGyroscopeZTemperature,
                      ADCSBoardTemperature1,
                      ADCSBoardTemperature2,
                      ADCSMCUTemperature,
                      ADCSBootCounter,
                      ADCSOnBoardTime,
                      ADCSSystick}},
                    // ADCS Parameters that might not be used
                    {5, 5000, false,
                     {ADCSMagnetometerSignX,
                      ADCSMagnetometerSignY,
                      ADCSMagnetometerSignZ,
                      ADCSGyroscopeRateX,
                      ADCSGyroscopeRateY,
                      ADCSGyroscopeRateZ,
                      ADCSGyroBiasX,
                      ADCSGyroBiasY,
                      ADCSGyroBiasZ,
                      ADCSFLASHInt,
                      ADCSSRAMInt}},
            }
    };
}

#endif
