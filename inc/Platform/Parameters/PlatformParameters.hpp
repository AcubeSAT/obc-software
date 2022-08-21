#ifndef ECSS_SERVICES_PLATFORMPARAMETERS_HPP
#define ECSS_SERVICES_PLATFORMPARAMETERS_HPP

#include "Helpers/Parameter.hpp"

namespace PlatformParameters {
    /**
     * ID enumeration of OBDH subsystem's specific parameters.
     */
    enum ParameterID : uint16_t {
        OnBoardYear = 0,
        OnBoardMonth = 1,
        OnBoardDay = 2,
        OnBoardHour = 3,
        OnBoardMinute = 4,
        OnBoardSecond = 5,
        ReportParametersUnusedStack = 6,
        AvailableHeap = 7,
        OBCUseRTT = 8,
        OBCUseUART = 9,
        OBCUseCAN = 10,
        OBCBootCounter = 301,
        OBCSystick = 329,

        /* OBDH Parameters */
        OBCPCBTemperature1 = 5000,
        OBCPCBTemperature2 = 5001,
        OBCMCUTemperature = 5002,
        OBCMCUInputVoltage = 5003,
        OBCMCUBootCounter = 5004,
        OBCAFlashInt = 5005,
        OBCASRAMInt = 5006,
        OBCOFLASHInt = 5007,
        OBCOSRAMInt = 5008,
        OBCMRAM = 5009,
        OBCNAND = 5010,
        OBCSpacecraftTimeRef = 5011,
        OBCMCUTime = 5012,
        OBCOperationalMode = 5013,
        OBCMemoryPartition = 5014,
        OBCReconfigurationTimer = 5015,
        OBCLastFailedEvent = 5016,
        OBCMCUSystick = 5017,
        OBCCANBUSLoad1 = 5018,
        OBCCANBUSLoad2 = 5019,
        OBCCANBUSActive = 5020,
        OBCMCUFDIR = 5021,
        OBCMCURestartSafeModeThreshold = 5022,
        OBCNANDFLASHLCLThreshold = 5023,
        OBCMRAMLCLThreshold = 5024,
        OBCNANDFLASHON = 5025,
        OBCMRAMON = 5026,
        OBCNANDFLASHScrubbingFrequency = 5027,
        OBCRAMScrubbingFrequency = 5028,
        OBCProgramFlashScrubbingFrequency = 5029,

        /* SU */
        SUMCUBootCounter = 4040,
        SUMCUSysTick = 4047,
        SUMCUTemperature = 4038,
        SUMCUInputVoltage = 4039,
        SUFlashIntUsedPercentage = 4041,
        SUFlashUsedPercentage = 4042,
        SUSRAMUsedPercentage = 4043,
        SUNANDCurrentlyUsedPartition = 4045,
        SUNANDFlashLCLOn = 4052,
        SUNANDFlashLCLThreshold = 4048,
        SUNANDFlashScrubbingFrequency = 4056,
        SURAMScrubbingFrequency = 4057,
        SUProgramFlashScrubbingFrequency = 4058,
        SUControlPumpFlashLCLOn = 4054,
        SUControlPumpFlashLCLThreshold = 4050,
        SUFlowPumpFlashOn = 4053,
        SUFlowPumpFlashLCLThreshold = 4049,
        SUCameraON = 4055,
        SUCameraLCLThreshold = 4051,
        SUPCBTemperature1 = 4000,
        SUPCBTemperature2 = 4001,
        SUPCBTemperatureControlValves = 4002,
        SUPCBTemperatureFlowValves = 4003,
        SUCameraTemperature = 4037,
        SUPDMSTemperature = 4004,
        SUGrowthMediumTemperature = 4005,
        SULastFailedEvent = 4046,
        SUPressureLevelSensor1 = 4010,
        SUPressureLevelSensor2 = 4011,
        SUHumidityLevelSensor1 = 4012,
        SUHumidityLevelSensor2 = 4013,
        SURADFET = 4036,
        SUPumpFlowRate1 = 4015,
        SUPumpFlowRate2 = 4016,
        SUControlChamberValve1 = 4017,
        SUControlChamberValve2 = 4018,
        SUControlChamberValve3 = 4019,
        SUControlSandwitchValve1 = 4020,
        SUControlSandwitchValve2 = 4021,
        SUControlSandwitchValve3 = 4022,
        SUFlowValveInlet1 = 4023,
        SUFlowValveInlet2 = 4024,
        SUFlowValveInlet3 = 4025,
        SUFlowValveOutlet1 = 4026,
        SUFlowValveOutlet2 = 4027,
        SUFlowValveOutlet3 = 4028,
        SUFlowValveTest1 = 4029,
        SUFlowValveTest2 = 4030,
        SULEDIntensity1 = 4006,
        SULEDIntensity2 = 4007,
        SULEDIntensity3 = 4008,
        SULEDIntensity4 = 4009,
        SUNumberOfPhotosTaken = 4014,
        SUPhotoExposureTime = 4031,
        SUPhotoInterval = 4032,
        SUPhotoCroppedResolution = 4033,
        SUPhotoCompressionRate = 4034,
        SUExperimentNumber = 4035,
        SUOnBoardTime = 4044,

        /* ADCS */
        ADCSUseRTT = 11,
        ADCSUseUART = 12,
        ADCSUseCAN = 13,
        ADCSMCUTemperature = 1218,
        ADCSBootCounter = 1220,
        ADCSMCUOnBoardTime = 1221,
        ADCSSystick = 1224,
        ADCSMagnetometerRawX = 1013,
        ADCSMagnetometerRawY = 1014,
        ADCSMagnetometerRawZ = 1015,
        ADCSMagnetometerFrequency = 1016,
        ADCSMagnetometerCycleCountX = 1017,
        ADCSMagnetometerCycleCountY = 1018,
        ADCSMagnetometerCycleCountZ = 1019,
        ADCSMagnetometerSelfTest = 1020,
        ADCSGyroscopeX = 1043,
        ADCSGyroscopeY = 1044,
        ADCSGyroscopeZ = 1045,
        ADCSGyroXLOCST1Register = 1046,
        ADCSGyroXLOCST0Register = 1047,
        ADCSGyroXHICST1Register = 1048,
        ADCSGyroXHICST0Register = 1049,
        ADCSGyroXQUAD1Register = 1050,
        ADCSGyroXQUAD0Register = 1051,
        ADCSGyroXFAULT1Register = 1052,
        ADCSGyroXFAULT0Register = 1053,
        ADCSGyroYLOCST1Register = 1054,
        ADCSGyroYLOCST0Register = 1055,
        ADCSGyroYHICST1Register = 1056,
        ADCSGyroYHICST0Register = 1057,
        ADCSGyroYQUAD1Register = 1058,
        ADCSGyroYQUAD0Register = 1059,
        ADCSGyroYFAULT1Register = 1060,
        ADCSGyroYFAULT0Register = 1061,
        ADCSGyroZLOCST1Register = 1062,
        ADCSGyroZLOCST0Register = 1063,
        ADCSGyroZHICST1Register = 1064,
        ADCSGyroZHICST0Register = 1065,
        ADCSGyroZQUAD1Register = 1066,
        ADCSGyroZQUAD0Register = 1067,
        ADCSGyroZFAULT1Register = 1068,
        ADCSGyroZFAULT0Register = 1069,
        ADCSGyroscopeXTemperature = 1089,
        ADCSGyroscopeYTemperature = 1090,
        ADCSGyroscopeZTemperature = 1091,
        ADCSBoardTemperature1 = 1092,
        ADCSBoardTemperature2 = 1093,
        ADCSMagnetometerSignX = 1158,
        ADCSMagnetometerSignY = 1159,
        ADCSMagnetometerSignZ = 1160,
        ADCSGyroSignX = 1164,
        ADCSGyroSignY = 1166,
        ADCSGyroSignZ = 1166,
        ADCSGyroBiasX = 1189,
        ADCSGyroBiasY = 1190,
        ADCSGyroBiasZ = 1191,

        /* EPS Parameters */
        EPSSwitch3V1 = 3000,
        EPSSwitch3V2 = 3001,
        EPSSwitch3V3 = 3002,
        EPSSwitch3V4 = 3003,
        EPSSwitch5V1 = 3004,
        EPSSwitch5V2 = 3005,
        EPSSwitch5V3 = 3006,
        EPSSwitch5V4 = 3007,
        EPSSwitch1 = 3008,
        EPSSwitch2 = 3009,
        EPSSwitch3 = 3010,
        EPSSwitch4 = 3011,
        EPSSwitch5 = 3012,
        EPSCurrentForRail3V1 = 3013,
        EPSCurrentForRail3V2 = 3014,
        EPSCurrentForRail3V3 = 3015,
        EPSCurrentForRail3V4 = 3016,
        EPSCurrentForRail5V1 = 3017,
        EPSCurrentForRail5V2 = 3018,
        EPSCurrentForRail5V3 = 3019,
        EPSCurrentForRail5V4 = 3020,
        EPSCurrentForRail1 = 3021,
        EPSCurrentForRail2 = 3022,
        EPSCurrentForRail3 = 3023,
        EPSCurrentForRail4 = 3024,
        EPSCurrentForRail5 = 3025,
        EPSVoltageForEachRail3V1 = 3026,
        EPSVoltageForEachRail3V2 = 3027,
        EPSVoltageForEachRail3V3 = 3028,
        EPSVoltageForEachRail3V4 = 3029,
        EPSVoltageForEachRail5V1 = 3030,
        EPSVoltageForEachRail5V2 = 3031,
        EPSVoltageForEachRail5V3 = 3032,
        EPSVoltageForEachRail5V4 = 3033,
        EPSVoltageForEachRail12V1 = 3034,
        EPSVoltageForEachRail12V2 = 3035,
        EPSVoltageForEachRail12V3 = 3036,
        EPSVoltageForEachRail12V4 = 3037,
        EPSPanelVoltageXPlus = 3038,
        EPSPanelVoltageXMinus = 3039,
        EPSPanelVoltageYPlus = 3040,
        EPSPanelVoltageYMinus = 3041,
        EPSPanelVoltageZ = 3042,
        EPSPanelCurrentXPlus = 3043,
        EPSPanelCurrentXMinus = 3044,
        EPSPanelCurrentYPlus = 3045,
        EPSPanelCurrentYMinus = 3046,
        EPSPanelCurrentZ = 3047,
        EPSBatteryPackVoltage = 3048,
        EPSPanelTemperatureXPlus = 3049,
        EPSPanelTemperatureXMinus = 3050,
        EPSPanelTemperatureYPlus = 3051,
        EPSPanelTemperatureYMinus = 3052,
        EPSPanelTemperatureZ = 3053,
        EPSPCBTemperatureSensor1 = 3054,
        EPSPCBTemperatureSensor2 = 3055,
        EPSBatteryTemperatureSensor1 = 3056,
        EPSBatteryTemperatureSensor2 = 3057,

        /* COMMS Parameters */
        COMMSUHFBandPATemperature = 2000,
        COMMSSBandPATemperature = 2001,
        COMMSPCBTemperature = 2002,
        COMMSAntennaDeploymentStatus = 2003,
        COMMSDataRateUHFTX = 2004,
        COMMSDataRateUHFRX = 2005,
        COMMSSymbolRateSBand = 2006,
        COMMSCWInterval = 2007,
        COMMSGMSKBeaconInterval = 2008,
        COMMSUHFBandTXPower = 2009,
        COMMSSBandTXPower = 2010,
        COMMSChannelNumberUHFBand = 2011,
        COMMSChannelNumberSBand = 2012,
        COMMSLNAGain = 2013,
        COMMSPAGainUHFBand = 2014,
        COMMSPAGainSBand = 2015,
        COMMSVGAGain = 2016,
        COMMSRSSI = 2017,
        COMMSUHFBandTXOnOff = 2018,
        COMMSUHFBandRXOnOff = 2019,
        COMMSSBandTXOnOff = 2020,
        COMMSPacketsRejectedCOMMS = 2021,
        COMMSInvalidHMAC = 2022,
        COMMSInvalidPacketStructure = 2023,
        COMMSInvalidSpacecraftID = 2024,
        COMMSFrameSequenceCounter = 2025,
        COMMSPCBTemperature1 = 2026,
        COMMSPCBTemperature2 = 2027,
        COMMSMCUTemperature = 2028,
        COMMSMCUInputVoltage = 2029,
        COMMSMCUBootCounter = 2030,
        COMMSOnBoardTime = 2031,
        COMMSNANDCurrentlyUsedMemoryPartition = 2032,
        COMMSLastFailedEvent = 2033,
        COMMSMCUSystick = 2034
    };

    // Parameters used for testing
    inline Parameter<uint16_t> onBoardYear(2022);
    inline Parameter<uint8_t> onBoardMonth(1);
    inline Parameter<uint8_t> onBoardDay(1);
    inline Parameter<uint8_t> onBoardHour(0);
    inline Parameter<uint8_t> onBoardMinute(0);
    inline Parameter<uint8_t> onBoardSecond(0);
    inline Parameter<uint16_t> reportParametersUnusedStack(0);
    inline Parameter<uint16_t> availableHeap(0);

    /******************* OBDH PARAMETERS *******************/
    inline Parameter<uint16_t> obcBootCounter(0);
    inline Parameter<uint64_t> obcSysTick(0);
    inline Parameter<bool> obcUseRTT(true);
    inline Parameter<bool> obcUseUART(true);
    inline Parameter<bool> obcUseCAN(false);

    inline Parameter<float> obcPCBTemperature1(0);
    inline Parameter<float> obcPCBTemperature2(0);
    inline Parameter<float> obcMCUTemperature(0);
    inline Parameter<float> obcMCUInputVoltage(0);

    inline Parameter<uint32_t> obcMCUBootCounter(0);
    inline Parameter<uint32_t> obcAFlashInt(0);
    inline Parameter<uint32_t> obcASRAMInt(0);
    inline Parameter<uint32_t> obcOFLASHInt(0);
    inline Parameter<uint32_t> obcOSRAMInt(0);
    inline Parameter<uint32_t> obcMRAM(0);
    inline Parameter<uint32_t> obcNAND(0);

    inline Parameter<uint32_t> obcMCUTime(0);

    inline Parameter<uint16_t> obcSpacecraftTimeRef(0); // enum
    inline Parameter<uint16_t> obcOperationalMode(0); // enum
    inline Parameter<uint16_t> obcMemoryPartition(0); // enum

    inline Parameter<uint32_t> obcReconfigurationTimer(0);
    inline Parameter<uint16_t> obcLastFailedEvent(0);
    inline Parameter<uint32_t> obcMCUSystick(0);

    inline Parameter<float> obcCANBUSLoad1(0);
    inline Parameter<float> obcCANBUSLoad2(0);

    inline Parameter<uint16_t> obcCANBUSActive(0); // enum
    inline Parameter<uint16_t> obcMCUFDIR(0); // enum

    inline Parameter<float> obcMCURestartSafeModeThreshold(0);
    inline Parameter<float> obcNANDFLASHLCLThreshold(0);
    inline Parameter<float> obcMRAMLCLThreshold(0);
    inline Parameter<float> obcNANDFLASHON(0);
    inline Parameter<float> obcNANDFlashScrubbingFrequency(0);
    inline Parameter<float> obcMRAMON(0);
    inline Parameter<float> obcRAMScrubbingFrequency(0);
    inline Parameter<float> obcProgramFlashScrubbingFrequency(0);

    /******************* SU PARAMETERS *******************/
    // MCU
    inline Parameter<uint32_t> suMCUBootCounter(0);
    inline Parameter<uint32_t> suMCUSysTick(0);

    inline Parameter<float> suMCUTemperature(0);
    inline Parameter<float> suMCUInputVoltage(0);

    // Memory
    inline Parameter<uint32_t> suFlashIntUsedPercentage(0);
    inline Parameter<uint32_t> suFlashUsedPercentage(0);
    inline Parameter<uint32_t> suSRAMUsedPercentage(0);

    inline Parameter<uint8_t> suNANDCurrentlyUsedPartition(0); // FIXME: is enum in database
    inline Parameter<float> suNANDFlashLclOn(0);
    inline Parameter<float> suNANDFlashLclThreshold(0);

    inline Parameter<float> suNANDFlashScrubbingFrequency(0);
    inline Parameter<float> suRAMScrubbingFrequency(0);
    inline Parameter<float> suProgramFlashScrubbingFrequency(0);

    // Components
    inline Parameter<float> suControlPumpFlashLclOn(0);
    inline Parameter<float> suControlPumpFlashLclThreshold(0);

    inline Parameter<float> suFlowPumpFlashOn(0);
    inline Parameter<float> suFlowPumpFlashLclThreshold(0);

    inline Parameter<float> suCameraOn(0);
    inline Parameter<float> suCameraLCLThreshold(0);

    // Temperatures
    inline Parameter<float> suPCBTemperature1(0);
    inline Parameter<float> suPCBTemperature2(0);

    inline Parameter<float> suPCBTemperatureControlValves(0);
    inline Parameter<float> suPCBTemperatureFlowValves(0);

    inline Parameter<float> suCameraTemperature(0);
    inline Parameter<float> suPDMSTemperature(0);
    inline Parameter<float> suGrowthMediumTemperature(0);

    // Sensors
    inline Parameter<float> suPressureLevelSensor1(0);
    inline Parameter<float> suPressureLevelSensor2(0);

    inline Parameter<float> suHumidityLevelSensor1(0);
    inline Parameter<float> suHumidityLevelSensor2(0);

    inline Parameter<double> suRadfet(0);

    // Components
    inline Parameter<float> suPumpFlowRate1(0);
    inline Parameter<float> suPumpFlowRate2(0);

    inline Parameter<bool> suCcontrolChamberValve1(0);
    inline Parameter<bool> suControlChamberValve2(0);
    inline Parameter<bool> suControlChamberValve3(0);

    inline Parameter<bool> suControlSandwitchValve1(0);
    inline Parameter<bool> suControlSandwitchValve2(0);
    inline Parameter<bool> suControlSandwitchValve3(0);

    inline Parameter<bool> suFlowValveInlet1(0);
    inline Parameter<bool> suFlowValveInlet2(0);
    inline Parameter<bool> suFlowValveInlet3(0);

    inline Parameter<bool> suFlowValveOutlet1(0);
    inline Parameter<bool> suFlowValveOutlet2(0);
    inline Parameter<bool> suFlowValveOutlet3(0);

    inline Parameter<bool> suFlowValveTest1(0);
    inline Parameter<bool> suFlowValveTest2(0);

    inline Parameter<float> suLEDIntensity1(0);
    inline Parameter<float> suLEDIntensity2(0);
    inline Parameter<float> suLEDIntensity3(0);
    inline Parameter<float> suLEDIntensity4(0);

    // Photos
    inline Parameter<uint16_t> suNumberOfPhotosTaken(0);
    inline Parameter<float> suPhotoExposureTime(0);
    inline Parameter<uint16_t> suPhotoInterval(0);
    inline Parameter<uint64_t> suPhotoCroppedResolution(0); // FIXME: is enum in database
    inline Parameter<uint32_t> suPhotoCompressionRate(0); // FIXME: is enum in database

    // Misc
    inline Parameter<uint8_t> suExperimentNumber(0); // FIXME: is enum in database
    inline Parameter<uint32_t> suOnBoardTime(0);
    inline Parameter<uint16_t> suLastFailedEvent(0);

    /******************* ADCS PARAMETERS *******************/
    inline Parameter<bool> adcsUseRTT(true);
    inline Parameter<bool> adcsUseUART(false);
    inline Parameter<bool> adcsUseCAN(false);

    inline Parameter<float> adcsMCUTemperature(0);
    inline Parameter<uint16_t> adcsBootCounter(0);
    inline Parameter<float> adcsMCUOnBoardTime(0);
    inline Parameter<uint64_t> adcsSystick(0);

    inline Parameter<int32_t> adcsMagnetometerRawX(0);
    inline Parameter<int32_t> adcsMagnetometerRawY(0);
    inline Parameter<int32_t> adcsMagnetometerRawZ(0);
    inline Parameter<uint8_t> adcsMagnetometerFrequency(0);
    inline Parameter<uint16_t> adcsMagnetometerCycleCountX(0); //uint8_t(?)
    inline Parameter<uint16_t> adcsMagnetometerCycleCountY(0); //uint8_t(?)
    inline Parameter<uint16_t> adcsMagnetometerCycleCountZ(0); //uint8_t(?)
    inline Parameter<bool> adcsMagnetometerSelfTest(0);

    inline Parameter<float> adcsGyroscopeX(0);
    inline Parameter<float> adcsGyroscopeY(0);
    inline Parameter<float> adcsGyroscopeZ(0);

    inline Parameter<uint16_t> adcsGyroXLOCST1Register(0);
    inline Parameter<uint16_t> adcsGyroXLOCST0Register(0);
    inline Parameter<uint16_t> adcsGyroXHICST1Register(0);
    inline Parameter<uint16_t> adcsGyroXHICST0Register(0);
    inline Parameter<uint16_t> adcsGyroXQUAD1Register(0);
    inline Parameter<uint16_t> adcsGyroXQUAD0Register(0);
    inline Parameter<uint16_t> adcsGyroXFAULT1Register(0);
    inline Parameter<uint16_t> adcsGyroXFAULT0Register(0);

    inline Parameter<uint16_t> adcsGyroYLOCST1Register(0);
    inline Parameter<uint16_t> adcsGyroYLOCST0Register(0);
    inline Parameter<uint16_t> adcsGyroYHICST1Register(0);
    inline Parameter<uint16_t> adcsGyroYHICST0Register(0);
    inline Parameter<uint16_t> adcsGyroYQUAD1Register(0);
    inline Parameter<uint16_t> adcsGyroYQUAD0Register(0);
    inline Parameter<uint16_t> adcsGyroYFAULT1Register(0);
    inline Parameter<uint16_t> adcsGyroYFAULT0Register(0);

    inline Parameter<uint16_t> adcsGyroZLOCST1Register(0);
    inline Parameter<uint16_t> adcsGyroZLOCST0Register(0);
    inline Parameter<uint16_t> adcsGyroZHICST1Register(0);
    inline Parameter<uint16_t> adcsGyroZHICST0Register(0);
    inline Parameter<uint16_t> adcsGyroZQUAD1Register(0);
    inline Parameter<uint16_t> adcsGyroZQUAD0Register(0);
    inline Parameter<uint16_t> adcsGyroZFAULT1Register(0);
    inline Parameter<uint16_t> adcsGyroZFAULT0Register(0);

    inline Parameter<float> adcsGyroscopeXTemperature(0);
    inline Parameter<float> adcsGyroscopeYTemperature(0);
    inline Parameter<float> adcsGyroscopeZTemperature(0);

    inline Parameter<float> adcsBoardTemperature1(0);
    inline Parameter<float> adcsBoardTemperature2(0);

    inline Parameter<bool> adcsMagnetometerSignX(0);
    inline Parameter<bool> adcsMagnetometerSignY(0);
    inline Parameter<bool> adcsMagnetometerSignZ(0);

    inline Parameter<bool> adcsGyroSignX(0);
    inline Parameter<bool> adcsGyroSignY(0);
    inline Parameter<bool> adcsGyroSignZ(0);

    inline Parameter<float> adcsGyroBiasX(0);
    inline Parameter<float> adcsGyroBiasY(0);
    inline Parameter<float> adcsGyroBiasZ(0);

    /****************** EPS PARAMETERS *******************/
    inline Parameter<bool> epsSwitch3V1(0);
    inline Parameter<bool> epsSwitch3V2(0);
    inline Parameter<bool> epsSwitch3V3(0);
    inline Parameter<bool> epsSwitch3V4(0);
    inline Parameter<bool> epsSwitch5V1(0);
    inline Parameter<bool> epsSwitch5V2(0);
    inline Parameter<bool> epsSwitch5V3(0);
    inline Parameter<bool> epsSwitch5V4(0);
    inline Parameter<bool> epsSwitch1(0);
    inline Parameter<bool> epsSwitch2(0);
    inline Parameter<bool> epsSwitch3(0);
    inline Parameter<bool> epsSwitch4(0);
    inline Parameter<bool> epsSwitch5(0);

    inline Parameter<float> epsCurrentForRail3V1(0);
    inline Parameter<float> epsCurrentForRail3V2(0);
    inline Parameter<float> epsCurrentForRail3V3(0);
    inline Parameter<float> epsCurrentForRail3V4(0);
    inline Parameter<float> epsCurrentForRail5V1(0);
    inline Parameter<float> epsCurrentForRail5V2(0);
    inline Parameter<float> epsCurrentForRail5V3(0);
    inline Parameter<float> epsCurrentForRail5V4(0);
    inline Parameter<float> epsCurrentForRail1(0);
    inline Parameter<float> epsCurrentForRail2(0);
    inline Parameter<float> epsCurrentForRail3(0);
    inline Parameter<float> epsCurrentForRail4(0);
    inline Parameter<float> epsCurrentForRail5(0);

    inline Parameter<float> epsVoltageForEachRail3V1(0);
    inline Parameter<float> epsVoltageForEachRail3V2(0);
    inline Parameter<float> epsVoltageForEachRail3V3(0);
    inline Parameter<float> epsVoltageForEachRail3V4(0);
    inline Parameter<float> epsVoltageForEachRail5V1(0);
    inline Parameter<float> epsVoltageForEachRail5V2(0);
    inline Parameter<float> epsVoltageForEachRail5V3(0);
    inline Parameter<float> epsVoltageForEachRail5V4(0);
    inline Parameter<float> epsVoltageForEachRail12V1(0);
    inline Parameter<float> epsVoltageForEachRail12V2(0);
    inline Parameter<float> epsVoltageForEachRail12V3(0);
    inline Parameter<float> epsVoltageForEachRail12V4(0);

    inline Parameter<float> epsPanelVoltageXPlus(0);
    inline Parameter<float> epsPanelVoltageXMinus(0);
    inline Parameter<float> epsPanelVoltageYPlus(0);
    inline Parameter<float> epsPanelVoltageYMinus(0);
    inline Parameter<float> epsPanelVoltageZ(0);

    inline Parameter<float> epsPanelCurrentXPlus(0);
    inline Parameter<float> epsPanelCurrentXMinus(0);
    inline Parameter<float> epsPanelCurrentYPlus(0);
    inline Parameter<float> epsPanelCurrentYMinus(0);
    inline Parameter<float> epsPanelCurrentZ(0);

    inline Parameter<float> epsBatteryPackVoltage(0);

    inline Parameter<float> epsPanelTemperatureXPlus(0);
    inline Parameter<float> epsPanelTemperatureXMinus(0);
    inline Parameter<float> epsPanelTemperatureYPlus(0);
    inline Parameter<float> epsPanelTemperatureYMinus(0);
    inline Parameter<float> epsPanelTemperatureZ(0);

    inline Parameter<float> epsPCBTemperatureSensor1(0);
    inline Parameter<float> epsPCBTemperatureSensor2(0);

    inline Parameter<float> epsBatteryTemperatureSensor1(0);
    inline Parameter<float> epsBatteryTemperatureSensor2(0);

    /****************** COMMS PARAMETERS *******************/
    inline Parameter<float> commsUHFBandPATemperature(0);
    inline Parameter<float> commsSBandPATemperature(0);
    inline Parameter<float> commsPCBTemperature(0);

    inline Parameter<uint8_t> commsAntennaDeploymentStatus(0); // enum

    inline Parameter<uint16_t> commsDataRateUHFTX(0);
    inline Parameter<uint16_t> commsDataRateUHFRX(0);
    inline Parameter<uint16_t> commsSymbolRateSBand(0);
    inline Parameter<uint16_t> commsCWInterval(0);
    inline Parameter<uint16_t> commsGMSKBeaconInterval(0);
    inline Parameter<uint16_t> commsUHFBandTXPower(0);
    inline Parameter<uint16_t> commsSBandTXPower(0);
    inline Parameter<uint16_t> commsChannelNumberUHFBand(0);
    inline Parameter<uint16_t> commsChannelNumberSBand(0);

    // enums
    inline Parameter<uint8_t> commsLNAGain(0);
    inline Parameter<uint16_t> commsPAGainUHFBand(0);
    inline Parameter<uint16_t> commsPAGainSBand(0);

    inline Parameter<uint16_t> commsVGAGain(0);
    inline Parameter<float> commsRSSI(0);

    inline Parameter<bool> commsUHFBandTXOnOff(0);
    inline Parameter<bool> commsUHFBandRXOnOff(0);
    inline Parameter<bool> commsSBandTXOnOff(0);

    inline Parameter<uint16_t> commsPacketsRejectedCOMMS(0);
    inline Parameter<uint16_t> commsInvalidHMAC(0);
    inline Parameter<uint16_t> commsInvalidPacketStructure(0);
    inline Parameter<uint16_t> commsInvalidSpacecraftID(0);
    inline Parameter<uint16_t> commsFrameSequenceCounter(0);

    inline Parameter<float> commsPCBTemperature1(0);
    inline Parameter<float> commsPCBTemperature2(0);
    inline Parameter<float> commsMCUTemperature(0);
    inline Parameter<float> commsMCUInputVoltage(0);

    inline Parameter<uint16_t> commsMCUBootCounter(0);
    inline Parameter<uint32_t> commsOnBoardTime(0);

    inline Parameter<uint8_t> commsNANDCurrentlyUsedMemoryPartition(0); // enum

    inline Parameter<uint16_t> commsLastFailedEvent(0);
    inline Parameter<uint64_t> commsMCUSystick(0);
}

#endif
