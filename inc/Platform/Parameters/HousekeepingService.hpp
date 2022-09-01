#ifndef ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP
#define ECSS_SERVICES_HOUSEKEEPINGPARAMETERS_HPP

#include "PlatformParameters.hpp"
#include "Services/HousekeepingService.hpp"

namespace HousekeepingStructures {
    using namespace PlatformParameters;

    static etl::array<HousekeepingStructure, ECSSMaxHousekeepingStructures> structures = {{{0, 10, true,
                                                                                            {ADCSMagnetometerRawX,
                                                                                             ADCSMagnetometerRawY,
                                                                                             ADCSMagnetometerRawZ,
                                                                                             ADCSGyroscopeX,
                                                                                             ADCSGyroscopeY,
                                                                                             ADCSGyroscopeZ}},
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
                                                                                           {3, 5000, false,
                                                                                            {ADCSMagnetometerSignX,
                                                                                             ADCSMagnetometerSignY,
                                                                                             ADCSMagnetometerSignZ,
                                                                                             ADCSGyroscopeX,
                                                                                             ADCSGyroscopeY,
                                                                                             ADCSGyroscopeZ,
                                                                                             ADCSGyroBiasX,
                                                                                             ADCSGyroBiasY,
                                                                                             ADCSGyroBiasZ}}
                                                                                          }};
}

#endif
