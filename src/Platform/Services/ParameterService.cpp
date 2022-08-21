#include "ECSS_Configuration.hpp"

#ifdef SERVICE_PARAMETER

#include "Services/ParameterService.hpp"
#include "PlatformParameters.hpp"

void ParameterService::initializeParameterMap() {
    parameters = {{PlatformParameters::OnBoardYear,                 PlatformParameters::onBoardYear},
                  {PlatformParameters::OnBoardMonth,                PlatformParameters::onBoardMonth},
                  {PlatformParameters::OnBoardDay,                  PlatformParameters::onBoardDay},
                  {PlatformParameters::OnBoardHour,                 PlatformParameters::onBoardHour},
                  {PlatformParameters::OnBoardMinute,               PlatformParameters::onBoardMinute},
                  {PlatformParameters::OnBoardSecond,                 PlatformParameters::onBoardSecond},
                  {PlatformParameters::ReportParametersUnusedStack,   PlatformParameters::reportParametersUnusedStack},
                  {PlatformParameters::AvailableHeap,                 PlatformParameters::availableHeap},
                  {PlatformParameters::OBCBootCounter,                PlatformParameters::obcBootCounter},
                  {PlatformParameters::OBCSystick,                          PlatformParameters::obcSysTick},
                  {PlatformParameters::OBCMCUTemperature,                   PlatformParameters::obcMCUTemperature},
                  {PlatformParameters::OBCUseRTT,                           PlatformParameters::obcUseRTT},
                  {PlatformParameters::OBCUseUART,                          PlatformParameters::obcUseUART},
                  {PlatformParameters::OBCUseCAN,                           PlatformParameters::obcUseCAN},
                  //-----------------------------------------------------------------------------------------------
                  {PlatformParameters::OBCPCBTemperature1,                  PlatformParameters::obcPCBTemperature1},
                  {PlatformParameters::OBCPCBTemperature2,                  PlatformParameters::obcPCBTemperature2},
                  {PlatformParameters::OBCMCUInputVoltage,                  PlatformParameters::obcMCUInputVoltage},
                  {PlatformParameters::OBCMCUBootCounter,             PlatformParameters::obcMCUBootCounter},
                  {PlatformParameters::OBCAFlashInt,                PlatformParameters::obcAFlashInt},
                  {PlatformParameters::OBCASRAMInt,                 PlatformParameters::obcASRAMInt},
                  {PlatformParameters::OBCOFLASHInt,                PlatformParameters::obcOFLASHInt},
                  {PlatformParameters::OBCOSRAMInt,                    PlatformParameters::obcOSRAMInt},
                  {PlatformParameters::OBCMRAM,                           PlatformParameters::obcMRAM},
                  {PlatformParameters::OBCNAND,                           PlatformParameters::obcNAND},
                  {PlatformParameters::OBCSpacecraftTimeRef,              PlatformParameters::obcMCUTime},
                  {PlatformParameters::OBCMCUTime,                        PlatformParameters::obcSpacecraftTimeRef},
                  {PlatformParameters::OBCOperationalMode,                PlatformParameters::obcOperationalMode},
                  {PlatformParameters::OBCMemoryPartition,                PlatformParameters::obcMemoryPartition},
                  {PlatformParameters::OBCReconfigurationTimer,           PlatformParameters::obcReconfigurationTimer},
                  {PlatformParameters::OBCLastFailedEvent,                PlatformParameters::obcLastFailedEvent},
                  {PlatformParameters::OBCMCUSystick,                     PlatformParameters::obcMCUSystick},
                  {PlatformParameters::OBCCANBUSLoad1,                    PlatformParameters::obcCANBUSLoad1},
                  {PlatformParameters::OBCCANBUSLoad2,                    PlatformParameters::obcCANBUSLoad2},
                  {PlatformParameters::OBCCANBUSActive,                   PlatformParameters::obcCANBUSActive},
                  {PlatformParameters::OBCMCUFDIR,                        PlatformParameters::obcMCUFDIR},
                  {PlatformParameters::OBCMCURestartSafeModeThreshold,    PlatformParameters::obcMCURestartSafeModeThreshold},
                  {PlatformParameters::OBCNANDFLASHLCLThreshold,          PlatformParameters::obcNANDFLASHLCLThreshold},
                  {PlatformParameters::OBCMRAMLCLThreshold,               PlatformParameters::obcMRAMLCLThreshold},
                  {PlatformParameters::OBCNANDFLASHON,                    PlatformParameters::obcNANDFLASHON},
                  {PlatformParameters::OBCMRAMON,                         PlatformParameters::obcNANDFlashScrubbingFrequency},
                  {PlatformParameters::OBCNANDFLASHScrubbingFrequency,    PlatformParameters::obcMRAMON},
                  {PlatformParameters::OBCRAMScrubbingFrequency,          PlatformParameters::obcRAMScrubbingFrequency},
                  {PlatformParameters::OBCProgramFlashScrubbingFrequency, PlatformParameters::obcProgramFlashScrubbingFrequency},
                  //-----------------------------------------------------------------------------------------------
                  {PlatformParameters::SUMCUBootCounter,               PlatformParameters::suMCUBootCounter},
                  {PlatformParameters::SUMCUSysTick,                   PlatformParameters::suMCUSysTick},
                  {PlatformParameters::SUMCUTemperature,                 PlatformParameters::suMCUTemperature},
                  {PlatformParameters::SUMCUInputVoltage,                PlatformParameters::suMCUInputVoltage},
                  {PlatformParameters::SUFlashIntUsedPercentage,         PlatformParameters::suFlashIntUsedPercentage},
                  {PlatformParameters::SUFlashUsedPercentage,            PlatformParameters::suFlashUsedPercentage},
                  {PlatformParameters::SUSRAMUsedPercentage,             PlatformParameters::suSRAMUsedPercentage},
                  {PlatformParameters::SUNANDCurrentlyUsedPartition,     PlatformParameters::suNANDCurrentlyUsedPartition},
                  {PlatformParameters::SUNANDFlashLCLOn,                 PlatformParameters::suNANDFlashLclOn},
                  {PlatformParameters::SUNANDFlashLCLThreshold,          PlatformParameters::suNANDFlashLclThreshold},
                  {PlatformParameters::SUNANDFlashScrubbingFrequency,    PlatformParameters::suNANDFlashScrubbingFrequency},
                  {PlatformParameters::SURAMScrubbingFrequency,          PlatformParameters::suRAMScrubbingFrequency},
                  {PlatformParameters::SUProgramFlashScrubbingFrequency, PlatformParameters::suProgramFlashScrubbingFrequency},
                  {PlatformParameters::SUControlPumpFlashLCLOn,        PlatformParameters::suControlPumpFlashLclOn},
                  {PlatformParameters::SUControlPumpFlashLCLThreshold, PlatformParameters::suControlPumpFlashLclThreshold},
                  {PlatformParameters::SUFlowPumpFlashOn,             PlatformParameters::suFlowPumpFlashOn},
                  {PlatformParameters::SUFlowPumpFlashLCLThreshold,   PlatformParameters::suFlowPumpFlashLclThreshold},
                  {PlatformParameters::SUCameraON,                    PlatformParameters::suCameraOn},
                  {PlatformParameters::SUCameraLCLThreshold,          PlatformParameters::suCameraLCLThreshold},
                  {PlatformParameters::SUPCBTemperature1,             PlatformParameters::suPCBTemperature1},
                  {PlatformParameters::SUPCBTemperature2,             PlatformParameters::suPCBTemperature2},
                  {PlatformParameters::SUPCBTemperatureControlValves, PlatformParameters::suPCBTemperatureControlValves},
                  {PlatformParameters::SUPCBTemperatureFlowValves, PlatformParameters::suPCBTemperatureFlowValves},
                  {PlatformParameters::SUCameraTemperature,       PlatformParameters::suCameraTemperature},
                  {PlatformParameters::SUPDMSTemperature,         PlatformParameters::suPDMSTemperature},
                  {PlatformParameters::SUGrowthMediumTemperature, PlatformParameters::suGrowthMediumTemperature},
                  {PlatformParameters::SULastFailedEvent,      PlatformParameters::suLastFailedEvent},
                  {PlatformParameters::SUPressureLevelSensor1,   PlatformParameters::suPressureLevelSensor1},
                  {PlatformParameters::SUPressureLevelSensor2,   PlatformParameters::suPressureLevelSensor2},
                  {PlatformParameters::SUHumidityLevelSensor1,   PlatformParameters::suHumidityLevelSensor1},
                  {PlatformParameters::SUHumidityLevelSensor2,   PlatformParameters::suHumidityLevelSensor2},
                  {PlatformParameters::SURADFET,                 PlatformParameters::suRadfet},
                  {PlatformParameters::SUPumpFlowRate1,          PlatformParameters::suPumpFlowRate1},
                  {PlatformParameters::SUPumpFlowRate2,          PlatformParameters::suPumpFlowRate2},
                  {PlatformParameters::SUControlChamberValve1,   PlatformParameters::suCcontrolChamberValve1},
                  {PlatformParameters::SUControlChamberValve2,   PlatformParameters::suControlChamberValve2},
                  {PlatformParameters::SUControlChamberValve3,   PlatformParameters::suControlChamberValve3},
                  {PlatformParameters::SUControlSandwitchValve1, PlatformParameters::suControlSandwitchValve1},
                  {PlatformParameters::SUControlSandwitchValve2, PlatformParameters::suControlSandwitchValve2},
                  {PlatformParameters::SUControlSandwitchValve3, PlatformParameters::suControlSandwitchValve3},
                  {PlatformParameters::SUFlowValveInlet1,      PlatformParameters::suFlowValveInlet1},
                  {PlatformParameters::SUFlowValveInlet2,      PlatformParameters::suFlowValveInlet2},
                  {PlatformParameters::SUFlowValveInlet3,      PlatformParameters::suFlowValveInlet3},
                  {PlatformParameters::SUFlowValveOutlet1,     PlatformParameters::suFlowValveOutlet1},
                  {PlatformParameters::SUFlowValveOutlet2,     PlatformParameters::suFlowValveOutlet2},
                  {PlatformParameters::SUFlowValveOutlet3,       PlatformParameters::suFlowValveOutlet3},
                  {PlatformParameters::SUFlowValveTest1,         PlatformParameters::suFlowValveTest1},
                  {PlatformParameters::SUFlowValveTest2,         PlatformParameters::suFlowValveTest2},
                  {PlatformParameters::SULEDIntensity1,          PlatformParameters::suLEDIntensity1},
                  {PlatformParameters::SULEDIntensity2,          PlatformParameters::suLEDIntensity2},
                  {PlatformParameters::SULEDIntensity3,          PlatformParameters::suLEDIntensity3},
                  {PlatformParameters::SULEDIntensity4,          PlatformParameters::suLEDIntensity4},
                  {PlatformParameters::SUNumberOfPhotosTaken,    PlatformParameters::suNumberOfPhotosTaken},
                  {PlatformParameters::SUPhotoExposureTime,      PlatformParameters::suPhotoExposureTime},
                  {PlatformParameters::SUPhotoInterval,          PlatformParameters::suPhotoInterval},
                  {PlatformParameters::SUPhotoCroppedResolution, PlatformParameters::suPhotoCroppedResolution},
                  {PlatformParameters::SUPhotoCompressionRate,   PlatformParameters::suPhotoCompressionRate},
                  {PlatformParameters::SUExperimentNumber,       PlatformParameters::suExperimentNumber},
                  {PlatformParameters::SUOnBoardTime,            PlatformParameters::suOnBoardTime},
                  //---------------------------------------------------------------------------------------------
                  {PlatformParameters::ADCSUseRTT,               PlatformParameters::adcsUseRTT},
                  {PlatformParameters::ADCSUseUART,              PlatformParameters::adcsUseUART},
                  {PlatformParameters::ADCSUseCAN,               PlatformParameters::adcsUseCAN},
                  {PlatformParameters::ADCSMCUTemperature,       PlatformParameters::adcsMCUTemperature},
                  {PlatformParameters::ADCSBootCounter,          PlatformParameters::adcsBootCounter},
                  {PlatformParameters::ADCSMCUOnBoardTime,       PlatformParameters::adcsMCUOnBoardTime},
                  {PlatformParameters::ADCSSystick,              PlatformParameters::adcsSystick},
                  {PlatformParameters::MagnetometerRawX,         PlatformParameters::magnetometerRawX},
                  {PlatformParameters::MagnetometerRawY,       PlatformParameters::magnetometerRawY},
                  {PlatformParameters::MagnetometerRawZ,            PlatformParameters::magnetometerRawZ},
                  {PlatformParameters::MagnetometerFrequency,       PlatformParameters::magnetometerFrequency},
                  {PlatformParameters::MagnetometerCycleCountX,     PlatformParameters::magnetometerCycleCountX},
                  {PlatformParameters::MagnetometerCycleCountY,     PlatformParameters::magnetometerCycleCountY},
                  {PlatformParameters::MagnetometerCycleCountZ,     PlatformParameters::magnetometerCycleCountZ},
                  {PlatformParameters::MagnetometerSelfTest,        PlatformParameters::magnetometerSelfTest},
                  {PlatformParameters::GyroscopeX,                  PlatformParameters::gyroscopeX},
                  {PlatformParameters::GyroscopeY,                  PlatformParameters::gyroscopeY},
                  {PlatformParameters::GyroscopeZ,                  PlatformParameters::gyroscopeZ},
                  {PlatformParameters::GyroXLOCST1Register,         PlatformParameters::gyroXLOCST1Register},
                  {PlatformParameters::GyroXLOCST0Register,         PlatformParameters::gyroXLOCST0Register},
                  {PlatformParameters::GyroXHICST1Register,         PlatformParameters::gyroXHICST1Register},
                  {PlatformParameters::GyroXHICST0Register,         PlatformParameters::gyroXHICST0Register},
                  {PlatformParameters::GyroXQUAD1Register,          PlatformParameters::gyroXQUAD1Register},
                  {PlatformParameters::GyroXQUAD0Register,          PlatformParameters::gyroXQUAD0Register},
                  {PlatformParameters::GyroXFAULT1Register,         PlatformParameters::gyroXFAULT1Register},
                  {PlatformParameters::GyroXFAULT0Register,         PlatformParameters::gyroXFAULT0Register},
                  {PlatformParameters::GyroYLOCST1Register,         PlatformParameters::gyroYLOCST1Register},
                  {PlatformParameters::GyroYLOCST0Register,         PlatformParameters::gyroYLOCST0Register},
                  {PlatformParameters::GyroYHICST1Register,         PlatformParameters::gyroYHICST1Register},
                  {PlatformParameters::GyroYHICST0Register,         PlatformParameters::gyroYHICST0Register},
                  {PlatformParameters::GyroYQUAD1Register,          PlatformParameters::gyroYQUAD1Register},
                  {PlatformParameters::GyroYQUAD0Register,          PlatformParameters::gyroYQUAD0Register},
                  {PlatformParameters::GyroYFAULT1Register,         PlatformParameters::gyroYFAULT1Register},
                  {PlatformParameters::GyroYFAULT0Register,         PlatformParameters::gyroYFAULT0Register},
                  {PlatformParameters::GyroZLOCST1Register,         PlatformParameters::gyroZLOCST1Register},
                  {PlatformParameters::GyroZLOCST0Register,         PlatformParameters::gyroZLOCST0Register},
                  {PlatformParameters::GyroZHICST1Register,         PlatformParameters::gyroZHICST1Register},
                  {PlatformParameters::GyroZHICST0Register,         PlatformParameters::gyroZHICST0Register},
                  {PlatformParameters::GyroZQUAD1Register,          PlatformParameters::gyroZQUAD1Register},
                  {PlatformParameters::GyroZQUAD0Register,          PlatformParameters::gyroZQUAD0Register},
                  {PlatformParameters::GyroZFAULT1Register,         PlatformParameters::gyroZFAULT1Register},
                  {PlatformParameters::GyroZFAULT0Register,         PlatformParameters::gyroZFAULT0Register},
                  {PlatformParameters::GyroscopeXTemperature,       PlatformParameters::gyroscopeXTemperature},
                  {PlatformParameters::GyroscopeYTemperature,       PlatformParameters::gyroscopeYTemperature},
                  {PlatformParameters::GyroscopeZTemperature,       PlatformParameters::gyroscopeZTemperature},
                  {PlatformParameters::ADCSBoardTemperature1,       PlatformParameters::adcsBoardTemperature1},
                  {PlatformParameters::ADCSBoardTemperature2,       PlatformParameters::adcsBoardTemperature2},
                  {PlatformParameters::MagnetometerSignX,           PlatformParameters::magnetometerSignX},
                  {PlatformParameters::MagnetometerSignY,           PlatformParameters::magnetometerSignY},
                  {PlatformParameters::MagnetometerSignZ,           PlatformParameters::magnetometerSignZ},
                  {PlatformParameters::GyroSignX,                   PlatformParameters::gyroSignX},
                  {PlatformParameters::GyroSignY,                   PlatformParameters::gyroSignY},
                  {PlatformParameters::GyroSignZ,                   PlatformParameters::gyroSignZ},
                  {PlatformParameters::GyroBiasX,                   PlatformParameters::gyroBiasX},
                  {PlatformParameters::GyroBiasY,                   PlatformParameters::gyroBiasY},
                  {PlatformParameters::GyroBiasZ,                   PlatformParameters::gyroBiasZ},
                  //---------------------------------------------------------------------------------------------
                  {PlatformParameters::EPSSwitch3V1,                PlatformParameters::epsSwitch3V1},
                  {PlatformParameters::EPSSwitch3V2,                PlatformParameters::epsSwitch3V2},
                  {PlatformParameters::EPSSwitch3V3,                PlatformParameters::epsSwitch3V3},
                  {PlatformParameters::EPSSwitch3V4,                PlatformParameters::epsSwitch3V4},
                  {PlatformParameters::EPSSwitch5V1,                PlatformParameters::epsSwitch5V1},
                  {PlatformParameters::EPSSwitch5V2,                PlatformParameters::epsSwitch5V2},
                  {PlatformParameters::EPSSwitch5V3,                PlatformParameters::epsSwitch5V3},
                  {PlatformParameters::EPSSwitch5V4,                PlatformParameters::epsSwitch5V4},
                  {PlatformParameters::EPSSwitch1,                  PlatformParameters::epsSwitch1},
                  {PlatformParameters::EPSSwitch2,                  PlatformParameters::epsSwitch2},
                  {PlatformParameters::EPSSwitch3,                  PlatformParameters::epsSwitch3},
                  {PlatformParameters::EPSSwitch4,                  PlatformParameters::epsSwitch4},
                  {PlatformParameters::EPSSwitch5,                  PlatformParameters::epsSwitch5},
                  {PlatformParameters::CurrentForRail3V1,           PlatformParameters::currentForRail3V1},
                  {PlatformParameters::CurrentForRail3V2,           PlatformParameters::currentForRail3V2},
                  {PlatformParameters::CurrentForRail3V3,           PlatformParameters::currentForRail3V3},
                  {PlatformParameters::CurrentForRail3V4,           PlatformParameters::currentForRail3V4},
                  {PlatformParameters::CurrentForRail5V1,           PlatformParameters::currentForRail5V1},
                  {PlatformParameters::CurrentForRail5V2,           PlatformParameters::currentForRail5V2},
                  {PlatformParameters::CurrentForRail5V3,           PlatformParameters::currentForRail5V3},
                  {PlatformParameters::CurrentForRail5V4,           PlatformParameters::currentForRail5V4},
                  {PlatformParameters::CurrentForRail1,             PlatformParameters::currentForRail1},
                  {PlatformParameters::CurrentForRail2,             PlatformParameters::currentForRail2},
                  {PlatformParameters::CurrentForRail3,             PlatformParameters::currentForRail3},
                  {PlatformParameters::CurrentForRail4,             PlatformParameters::currentForRail4},
                  {PlatformParameters::CurrentForRail5,             PlatformParameters::currentForRail5},
                  {PlatformParameters::VoltageForEachRail3V1,       PlatformParameters::voltageForEachRail3V1},
                  {PlatformParameters::VoltageForEachRail3V2,       PlatformParameters::voltageForEachRail3V2},
                  {PlatformParameters::VoltageForEachRail3V3,       PlatformParameters::voltageForEachRail3V3},
                  {PlatformParameters::VoltageForEachRail3V4,       PlatformParameters::voltageForEachRail3V4},
                  {PlatformParameters::VoltageForEachRail5V1,       PlatformParameters::voltageForEachRail5V1},
                  {PlatformParameters::VoltageForEachRail5V2,       PlatformParameters::voltageForEachRail5V2},
                  {PlatformParameters::VoltageForEachRail5V3,       PlatformParameters::voltageForEachRail5V3},
                  {PlatformParameters::VoltageForEachRail5V4,       PlatformParameters::voltageForEachRail5V4},
                  {PlatformParameters::VoltageForEachRail12V1,      PlatformParameters::voltageForEachRail12V1},
                  {PlatformParameters::VoltageForEachRail12V2,      PlatformParameters::voltageForEachRail12V2},
                  {PlatformParameters::VoltageForEachRail12V3,      PlatformParameters::voltageForEachRail12V3},
                  {PlatformParameters::VoltageForEachRail12V4,      PlatformParameters::voltageForEachRail12V4},
                  {PlatformParameters::PanelVoltageXPlus,           PlatformParameters::panelVoltageXPlus},
                  {PlatformParameters::PanelVoltageXMinus,          PlatformParameters::panelVoltageXMinus},
                  {PlatformParameters::PanelVoltageYPlus,           PlatformParameters::panelVoltageYPlus},
                  {PlatformParameters::PanelVoltageYMinus,          PlatformParameters::panelVoltageYMinus},
                  {PlatformParameters::PanelVoltageZ,               PlatformParameters::panelVoltageZ},
                  {PlatformParameters::PanelCurrentXPlus,           PlatformParameters::panelCurrentXPlus},
                  {PlatformParameters::PanelCurrentXMinus,          PlatformParameters::panelCurrentXMinus},
                  {PlatformParameters::PanelCurrentYPlus,           PlatformParameters::panelCurrentYPlus},
                  {PlatformParameters::PanelCurrentYMinus,          PlatformParameters::panelCurrentYMinus},
                  {PlatformParameters::PanelCurrentZ,               PlatformParameters::panelCurrentZ},
                  {PlatformParameters::BatteryPackVoltage,          PlatformParameters::batteryPackVoltage},
                  {PlatformParameters::PanelTemperatureXPlus,        PlatformParameters::panelTemperatureXPlus},
                  {PlatformParameters::PanelTemperatureXMinus,       PlatformParameters::panelTemperatureXMinus},
                  {PlatformParameters::PanelTemperatureYPlus,        PlatformParameters::panelTemperatureYPlus},
                  {PlatformParameters::PanelTemperatureYMinus,       PlatformParameters::panelTemperatureYMinus},
                  {PlatformParameters::PanelTemperatureZ,            PlatformParameters::panelTemperatureZ},
                  {PlatformParameters::EPSPCBTemperatureSensor1,     PlatformParameters::epsPCBTemperatureSensor1},
                  {PlatformParameters::EPSPCBTemperatureSensor2,     PlatformParameters::epsPCBTemperatureSensor2},
                  {PlatformParameters::BatteryTemperatureSensor1,    PlatformParameters::batteryTemperatureSensor1},
                  {PlatformParameters::BatteryTemperatureSensor2,    PlatformParameters::batteryTemperatureSensor2},
                  //---------------------------------------------------------------------------------------------
                  {PlatformParameters::COMMSUHFBandPATemperature,    PlatformParameters::commsUHFBandPATemperature},
                  {PlatformParameters::COMMSSBandPATemperature,      PlatformParameters::commsSBandPATemperature},
                  {PlatformParameters::COMMSPCBTemperature,          PlatformParameters::commsPCBTemperature},
                  {PlatformParameters::COMMSAntennaDeploymentStatus, PlatformParameters::commsAntennaDeploymentStatus},
                  {PlatformParameters::COMMSDataRateUHFTX,           PlatformParameters::commsDataRateUHFTX},
                  {PlatformParameters::COMMSDataRateUHFRX,           PlatformParameters::commsDataRateUHFRX},
                  {PlatformParameters::COMMSSymbolRateSBand,         PlatformParameters::commsSymbolRateSBand},
                  {PlatformParameters::COMMSCWInterval,              PlatformParameters::commsCWInterval},
                  {PlatformParameters::COMMSGMSKBeaconInterval,      PlatformParameters::commsGMSKBeaconInterval},
                  {PlatformParameters::COMMSUHFBandTXPower,          PlatformParameters::commsUHFBandTXPower},
                  {PlatformParameters::COMMSSBandTXPower,            PlatformParameters::commsSBandTXPower},
                  {PlatformParameters::COMMSChannelNumberUHFBand,    PlatformParameters::commsChannelNumberUHFBand},
                  {PlatformParameters::COMMSChannelNumberSBand,      PlatformParameters::commsChannelNumberSBand},
                  {PlatformParameters::COMMSLNAGain,                 PlatformParameters::commsLNAGain},
                  {PlatformParameters::COMMSPAGainUHFBand,        PlatformParameters::commsPAGainUHFBand},
                  {PlatformParameters::COMMSPAGainSBand,          PlatformParameters::commsPAGainSBand},
                  {PlatformParameters::COMMSVGAGain,              PlatformParameters::commsVGAGain},
                  {PlatformParameters::COMMSRSSI,                 PlatformParameters::commsRSSI},
                  {PlatformParameters::COMMSUHFBandTXOnOff,       PlatformParameters::commsUHFBandTXOnOff},
                  {PlatformParameters::COMMSUHFBandRXOnOff,       PlatformParameters::commsUHFBandRXOnOff},
                  {PlatformParameters::COMMSSBandTXOnOff,         PlatformParameters::commsSBandTXOnOff},
                  {PlatformParameters::COMMSPacketsRejectedCOMMS, PlatformParameters::commsPacketsRejectedCOMMS},
                  {PlatformParameters::COMMSInvalidHMAC,          PlatformParameters::commsInvalidHMAC},
                  {PlatformParameters::COMMSInvalidPacketStructure, PlatformParameters::commsInvalidPacketStructure},
                  {PlatformParameters::COMMSInvalidSpacecraftID,    PlatformParameters::commsInvalidSpacecraftID},
                  {PlatformParameters::COMMSFrameSequenceCounter,   PlatformParameters::commsFrameSequenceCounter},
                  {PlatformParameters::COMMSPCBTemperature1,        PlatformParameters::commsPCBTemperature1},
                  {PlatformParameters::COMMSPCBTemperature2,        PlatformParameters::commsPCBTemperature2},
                  {PlatformParameters::COMMSMCUTemperature,         PlatformParameters::commsMCUTemperature},
                  {PlatformParameters::COMMSMCUInputVoltage,        PlatformParameters::commsMCUInputVoltage},
                  {PlatformParameters::COMMSMCUBootCounter,         PlatformParameters::commsMCUBootCounter},
                  {PlatformParameters::COMMSOnBoardTime,            PlatformParameters::commsOnBoardTime},
                  {PlatformParameters::COMMSNANDCurrentlyUsedMemoryPartition, PlatformParameters::commsNANDCurrentlyUsedMemoryPartition},
                  {PlatformParameters::COMMSLastFailedEvent,                  PlatformParameters::commsLastFailedEvent},
                  {PlatformParameters::COMMSMCUSystick,                       PlatformParameters::commsMCUSystick}};
}

#endif
