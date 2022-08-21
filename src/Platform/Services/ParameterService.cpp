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
                  {PlatformParameters::SUMCUBootCounter,                  PlatformParameters::suMCUBootCounter},
                  {PlatformParameters::SUMCUSysTick,                      PlatformParameters::suMCUSysTick},
                  {PlatformParameters::SUMCUTemperature,                  PlatformParameters::suMCUTemperature},
                  {PlatformParameters::SUMCUInputVoltage,                 PlatformParameters::suMCUInputVoltage},
                  {PlatformParameters::FlashIntUsedPercentage,            PlatformParameters::flashIntUsedPercentage},
                  {PlatformParameters::FlashUsedPercentage,               PlatformParameters::flashUsedPercentage},
                  {PlatformParameters::SRAMUsedPercentage,                PlatformParameters::sramUsedPercentage},
                  {PlatformParameters::NANDCurrentlyUsedPartition,  PlatformParameters::nandCurrentlyUsedPartition},
                  {PlatformParameters::NANDFlashLCLOn,              PlatformParameters::nandFlashLclOn},
                  {PlatformParameters::NANDFlashLCLThreshold,           PlatformParameters::nandFlashLclThreshold},
                  {PlatformParameters::NANDFlashScrubbingFrequency,     PlatformParameters::nandFlashScrubbingFrequency},
                  {PlatformParameters::RAMScrubbingFrequency,           PlatformParameters::ramScrubbingFrequency},
                  {PlatformParameters::ProgramFlashScrubbingFrequency,  PlatformParameters::programFlashScrubbingFrequency},
                  {PlatformParameters::ControlPumpFlashLCLOn,           PlatformParameters::controlPumpFlashLclOn},
                  {PlatformParameters::ControlPumpFlashLCLThreshold,    PlatformParameters::controlPumpFlashLclThreshold},
                  {PlatformParameters::FlowPumpFlashOn,                 PlatformParameters::flowPumpFlashOn},
                  {PlatformParameters::FlowPumpFlashLCLThreshold,       PlatformParameters::flowPumpFlashLclThreshold},
                  {PlatformParameters::CameraON,                        PlatformParameters::cameraOn},
                  {PlatformParameters::CameraLCLThreshold,              PlatformParameters::cameraLclThreshold},
                  {PlatformParameters::PCBTemperature1,                 PlatformParameters::pcbTemperature1},
                  {PlatformParameters::PCBTemperature2,                 PlatformParameters::pcbTemperature2},
                  {PlatformParameters::PCBTemperatureControlValves,     PlatformParameters::pcbTemperatureControlValves},
                  {PlatformParameters::PCBTemperatureFlowValves,        PlatformParameters::pcbTemperatureFlowValves},
                  {PlatformParameters::CameraTemperature,               PlatformParameters::cameraTemperature},
                  {PlatformParameters::PDMSTemperature,                 PlatformParameters::pdmsTemperature},
                  {PlatformParameters::GrowthMediumTemperature,         PlatformParameters::growthMediumTemperature},
                  {PlatformParameters::LastFailedEvent,                 PlatformParameters::lastFailedEvent},
                  {PlatformParameters::PressureLevelSensor1,            PlatformParameters::pressureLevelSensor1},
                  {PlatformParameters::PressureLevelSensor2,            PlatformParameters::pressureLevelSensor2},
                  {PlatformParameters::HumidityLevelSensor1,            PlatformParameters::humidityLevelSensor1},
                  {PlatformParameters::HumidityLevelSensor2,            PlatformParameters::humidityLevelSensor2},
                  {PlatformParameters::RADFET,                          PlatformParameters::radfet},
                  {PlatformParameters::PumpFlowRate1,                   PlatformParameters::pumpFlowRate1},
                  {PlatformParameters::PumpFlowRate2,                   PlatformParameters::pumpFlowRate2},
                  {PlatformParameters::ControlChamberValve1,            PlatformParameters::controlChamberValve1},
                  {PlatformParameters::ControlChamberValve2,            PlatformParameters::controlChamberValve2},
                  {PlatformParameters::ControlChamberValve3,            PlatformParameters::controlChamberValve3},
                  {PlatformParameters::ControlSandwitchValve1,          PlatformParameters::controlSandwitchValve1},
                  {PlatformParameters::ControlSandwitchValve2,          PlatformParameters::controlSandwitchValve2},
                  {PlatformParameters::ControlSandwitchValve3,          PlatformParameters::controlSandwitchValve3},
                  {PlatformParameters::FlowValveInlet1,                 PlatformParameters::flowValveInlet1},
                  {PlatformParameters::FlowValveInlet2,                 PlatformParameters::flowValveInlet2},
                  {PlatformParameters::FlowValveInlet3,                 PlatformParameters::flowValveInlet3},
                  {PlatformParameters::FlowValveOutlet1,                PlatformParameters::flowValveOutlet1},
                  {PlatformParameters::FlowValveOutlet2,                PlatformParameters::flowValveOutlet2},
                  {PlatformParameters::FlowValveOutlet3,                PlatformParameters::flowValveOutlet3},
                  {PlatformParameters::FlowValveTest1,                  PlatformParameters::flowValveTest1},
                  {PlatformParameters::FlowValveTest2,                  PlatformParameters::flowValveTest2},
                  {PlatformParameters::LEDIntensity1,          PlatformParameters::ledIntensity1},
                  {PlatformParameters::LEDIntensity2,          PlatformParameters::ledIntensity2},
                  {PlatformParameters::LEDIntensity3,          PlatformParameters::ledIntensity3},
                  {PlatformParameters::LEDIntensity4,          PlatformParameters::ledIntensity4},
                  {PlatformParameters::NumberOfPhotosTaken,    PlatformParameters::numberOfPhotosTaken},
                  {PlatformParameters::PhotoExposureTime,      PlatformParameters::photoExposureTime},
                  {PlatformParameters::PhotoInterval,          PlatformParameters::photoInterval},
                  {PlatformParameters::PhotoCroppedResolution, PlatformParameters::photoCroppedResolution},
                  {PlatformParameters::PhotoCompressionRate,   PlatformParameters::photoCompressionRate},
                  {PlatformParameters::ExperimentNumber,       PlatformParameters::experimentNumber},
                  {PlatformParameters::SUOnBoardTime,          PlatformParameters::suOnBoardTime},
                  //---------------------------------------------------------------------------------------------
                  {PlatformParameters::ADCSUseRTT,             PlatformParameters::adcsUseRTT},
                  {PlatformParameters::ADCSUseUART,            PlatformParameters::adcsUseUART},
                  {PlatformParameters::ADCSUseCAN,             PlatformParameters::adcsUseCAN},
                  {PlatformParameters::ADCSMCUTemperature,     PlatformParameters::adcsMCUTemperature},
                  {PlatformParameters::ADCSBootCounter,        PlatformParameters::adcsBootCounter},
                  {PlatformParameters::ADCSMCUOnBoardTime,     PlatformParameters::adcsMCUOnBoardTime},
                  {PlatformParameters::ADCSSystick,            PlatformParameters::adcsSystick},
                  {PlatformParameters::MagnetometerRawX,       PlatformParameters::magnetometerRawX},
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
                  {PlatformParameters::PanelTemperatureXPlus,       PlatformParameters::panelTemperatureXPlus},
                  {PlatformParameters::PanelTemperatureXMinus,      PlatformParameters::panelTemperatureXMinus},
                  {PlatformParameters::PanelTemperatureYPlus,       PlatformParameters::panelTemperatureYPlus},
                  {PlatformParameters::PanelTemperatureYMinus,      PlatformParameters::panelTemperatureYMinus},
                  {PlatformParameters::PanelTemperatureZ,           PlatformParameters::panelTemperatureZ},
                  {PlatformParameters::EPSPCBTemperatureSensor1,    PlatformParameters::epsPCBTemperatureSensor1},
                  {PlatformParameters::EPSPCBTemperatureSensor2,    PlatformParameters::epsPCBTemperatureSensor2},
                  {PlatformParameters::BatteryTemperatureSensor1,   PlatformParameters::batteryTemperatureSensor1},
                  {PlatformParameters::BatteryTemperatureSensor2,   PlatformParameters::batteryTemperatureSensor2},
                  //---------------------------------------------------------------------------------------------
                  {PlatformParameters::UHFBandPATemperature,        PlatformParameters::uhfBandPATemperature},
                  {PlatformParameters::SBandPATemperature,          PlatformParameters::sBandPATemperature},
                  {PlatformParameters::COMMSPCBTemperature,         PlatformParameters::commsPCBTemperature},
                  {PlatformParameters::AntennaDeploymentStatus,     PlatformParameters::antennaDeploymentStatus},
                  {PlatformParameters::DataRateUHFTX,               PlatformParameters::dataRateUHFTX},
                  {PlatformParameters::DataRateUHFRX,               PlatformParameters::dataRateUHFRX},
                  {PlatformParameters::SymbolRateSBand,             PlatformParameters::symbolRateSBand},
                  {PlatformParameters::CWInterval,                  PlatformParameters::cwInterval},
                  {PlatformParameters::GMSKBeaconInterval,          PlatformParameters::gmskBeaconInterval},
                  {PlatformParameters::UHFBandTXPower,              PlatformParameters::uhfBandTXPower},
                  {PlatformParameters::SBandTXPower,                PlatformParameters::sBandTXPower},
                  {PlatformParameters::ChannelNumberUHFBand,        PlatformParameters::channelNumberUHFBand},
                  {PlatformParameters::ChannelNumberSBand,          PlatformParameters::channelNumberSBand},
                  {PlatformParameters::LNAGain,                     PlatformParameters::lnaGain},
                  {PlatformParameters::PAGainUHFBand,               PlatformParameters::paGainUHFBand},
                  {PlatformParameters::PAGainSBand,                 PlatformParameters::paGainSBand},
                  {PlatformParameters::VGAGain,                     PlatformParameters::vgaGain},
                  {PlatformParameters::RSSI,                        PlatformParameters::rssi},
                  {PlatformParameters::UHFBandTXOnOff,              PlatformParameters::uhfBandTXOnOff},
                  {PlatformParameters::UHFBandRXOnOff,              PlatformParameters::uhfBandRXOnOff},
                  {PlatformParameters::SBandTXOnOff,                PlatformParameters::sBandTXOnOff},
                  {PlatformParameters::PacketsRejectedCOMMS,        PlatformParameters::packetsRejectedCOMMS},
                  {PlatformParameters::InvalidHMAC,                 PlatformParameters::invalidHMAC},
                  {PlatformParameters::InvalidPacketStructure,      PlatformParameters::invalidPacketStructure},
                  {PlatformParameters::InvalidSpacecraftID,         PlatformParameters::invalidSpacecraftID},
                  {PlatformParameters::FrameSequenceCounter,        PlatformParameters::frameSequenceCounter},
                  {PlatformParameters::COMMSPCBTemperature1,        PlatformParameters::commsPCBTemperature1},
                  {PlatformParameters::COMMSPCBTemperature2,        PlatformParameters::commsPCBTemperature2},
                  {PlatformParameters::COMMSMCUTemperature,         PlatformParameters::commsMCUTemperature},
                  {PlatformParameters::COMMSMCUInputVoltage,        PlatformParameters::commsMCUInputVoltage},
                  {PlatformParameters::COMMSMCUBootCounter,         PlatformParameters::commsMCUBootCounter},
                  {PlatformParameters::COMMSOnBoardTime,            PlatformParameters::commsOnBoardTime},
                  {PlatformParameters::COMMSNANDCurrentlyUsedMemoryPartition,   PlatformParameters::commsNANDCurrentlyUsedMemoryPartition},
                  {PlatformParameters::COMMSLastFailedEvent,                    PlatformParameters::commsLastFailedEvent},
                  {PlatformParameters::COMMSMCUSystick,                         PlatformParameters::commsMCUSystick}};
}

#endif
