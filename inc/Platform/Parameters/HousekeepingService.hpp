#ifndef ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP
#define ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP

#include "PlatformParameters.hpp"
#include "Services/HousekeepingService.hpp"

namespace HousekeepingStructures {
    using namespace PlatformParameters;

    static etl::array<HousekeepingStructure, ECSSMaxHousekeepingStructures> structures = {
{
        /**
        * ADCS Parameters that will be monitored every 0.1 sec in the campaign
        */
        {0, 10, true,
        {ADCSMagnetometerRawX,
        ADCSMagnetometerRawY,
        ADCSMagnetometerRawZ,
        ADCSGyroscopeX,
        ADCSGyroscopeY,
        ADCSGyroscopeZ}},
        /**
        * OBC Mission Database parameters
        */
        {1, 3000, true,
        {/* TODO: Add OnBoardTime here once it's merged */
               ReportParametersUnusedStack,
               AvailableHeap,
               OBCUseCAN,
               OBCUseRTT,
               OBCUseUART,
               ADCSUseCAN,
               ADCSUseRTT,
               ADCSUseUART,
               OBCPCBTemperature1,
               OBCPCBTemperature2,
               OBCSpacecraftTimeRef,
               OBCOperationalMode,
               OBCReconfigurationTimer,
               OBCLastFailedEvent,
               OBCMCUSystick}},
        /**
        * ADCS Parameters that will be monitored every 3 seconds in the campaign
        */
        {2, 3000, true,
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
        ADCSMCUOnBoardTime,
        ADCSSystick}},
        /**
        * ADCS Parameters that might not be used
        */
        {3, 5000, false,
        {ADCSMagnetometerSignX,
        ADCSMagnetometerSignY,
        ADCSMagnetometerSignZ,
        ADCSGyroscopeX,
        ADCSGyroscopeY,
        ADCSGyroscopeZ,
        ADCSGyroBiasX,
        ADCSGyroBiasY,
        ADCSGyroBiasZ}},
        /**
        * OBC Parameters that will be monitored in the campaign
        */
        {4, 1000, true,
        {OBCPCBTemperature1,
        OBCPCBTemperature2,
        OBCMCUTemperature,
        OBCMCUBootCounter,
               /*OBCOnBoardTime once it's merged*/
        OBCMemoryPartition,
        OBCMCUSystick,
        OBCCANBUSLoad1,
        OBCCANBUSLoad2,
        OBCCANBUSActive,
        OBCNANDFLASHLCLThreshold,
        OBCMRAMLCLThreshold,
        OBCNANDFLASHON,
        OBCMRAMON}}
        }
    };
}

#endif
