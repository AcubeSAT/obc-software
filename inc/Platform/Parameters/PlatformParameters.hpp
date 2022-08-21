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
        MagnetometerRawX = 1013,
        MagnetometerRawY = 1014,
        MagnetometerRawZ = 1015,
        MagnetometerFrequency = 1016,
        MagnetometerCycleCountX = 1017,
        MagnetometerCycleCountY = 1018,
        MagnetometerCycleCountZ = 1019,
        MagnetometerSelfTest = 1020,
        GyroscopeX = 1043,
        GyroscopeY = 1044,
        GyroscopeZ = 1045,
        GyroXLOCST1Register = 1046,
        GyroXLOCST0Register = 1047,
        GyroXHICST1Register = 1048,
        GyroXHICST0Register = 1049,
        GyroXQUAD1Register = 1050,
        GyroXQUAD0Register = 1051,
        GyroXFAULT1Register = 1052,
        GyroXFAULT0Register = 1053,
        GyroYLOCST1Register = 1054,
        GyroYLOCST0Register = 1055,
        GyroYHICST1Register = 1056,
        GyroYHICST0Register = 1057,
        GyroYQUAD1Register = 1058,
        GyroYQUAD0Register = 1059,
        GyroYFAULT1Register = 1060,
        GyroYFAULT0Register = 1061,
        GyroZLOCST1Register = 1062,
        GyroZLOCST0Register = 1063,
        GyroZHICST1Register = 1064,
        GyroZHICST0Register = 1065,
        GyroZQUAD1Register = 1066,
        GyroZQUAD0Register = 1067,
        GyroZFAULT1Register = 1068,
        GyroZFAULT0Register = 1069,
        GyroscopeXTemperature = 1089,
        GyroscopeYTemperature = 1090,
        GyroscopeZTemperature = 1091,
        ADCSBoardTemperature1 = 1092,
        ADCSBoardTemperature2 = 1093,
        MagnetometerSignX = 1158,
        MagnetometerSignY = 1159,
        MagnetometerSignZ = 1160,
        GyroSignX = 1164,
        GyroSignY = 1166,
        GyroSignZ = 1166,
        GyroBiasX = 1189,
        GyroBiasY = 1190,
        GyroBiasZ = 1191,

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
        CurrentForRail3V1 = 3013,
        CurrentForRail3V2 = 3014,
        CurrentForRail3V3 = 3015,
        CurrentForRail3V4 = 3016,
        CurrentForRail5V1 = 3017,
        CurrentForRail5V2 = 3018,
        CurrentForRail5V3 = 3019,
        CurrentForRail5V4 = 3020,
        CurrentForRail1 = 3021,
        CurrentForRail2 = 3022,
        CurrentForRail3 = 3023,
        CurrentForRail4 = 3024,
        CurrentForRail5 = 3025,
        VoltageForEachRail3V1 = 3026,
        VoltageForEachRail3V2 = 3027,
        VoltageForEachRail3V3 = 3028,
        VoltageForEachRail3V4 = 3029,
        VoltageForEachRail5V1 = 3030,
        VoltageForEachRail5V2 = 3031,
        VoltageForEachRail5V3 = 3032,
        VoltageForEachRail5V4 = 3033,
        VoltageForEachRail12V1 = 3034,
        VoltageForEachRail12V2 = 3035,
        VoltageForEachRail12V3 = 3036,
        VoltageForEachRail12V4 = 3037,
        PanelVoltageXPlus = 3038,
        PanelVoltageXMinus = 3039,
        PanelVoltageYPlus = 3040,
        PanelVoltageYMinus = 3041,
        PanelVoltageZ = 3042,
        PanelCurrentXPlus = 3043,
        PanelCurrentXMinus = 3044,
        PanelCurrentYPlus = 3045,
        PanelCurrentYMinus = 3046,
        PanelCurrentZ = 3047,
        BatteryPackVoltage = 3048,
        PanelTemperatureXPlus = 3049,
        PanelTemperatureXMinus = 3050,
        PanelTemperatureYPlus = 3051,
        PanelTemperatureYMinus = 3052,
        PanelTemperatureZ = 3053,
        EPSPCBTemperatureSensor1 = 3054,
        EPSPCBTemperatureSensor2 = 3055,
        BatteryTemperatureSensor1 = 3056,
        BatteryTemperatureSensor2 = 3057,

        /* COMMS Parameters */
        UHFBandPATemperature = 2000,
        SBandPATemperature = 2001,
        COMMSPCBTemperature = 2002,
        AntennaDeploymentStatus = 2003,
        DataRateUHFTX = 2004,
        DataRateUHFRX = 2005,
        SymbolRateSBand = 2006,
        CWInterval = 2007,
        GMSKBeaconInterval = 2008,
        UHFBandTXPower = 2009,
        SBandTXPower = 2010,
        ChannelNumberUHFBand = 2011,
        ChannelNumberSBand = 2012,
        LNAGain = 2013,
        PAGainUHFBand = 2014,
        PAGainSBand = 2015,
        VGAGain = 2016,
        RSSI = 2017,
        UHFBandTXOnOff = 2018,
        UHFBandRXOnOff = 2019,
        SBandTXOnOff = 2020,
        PacketsRejectedCOMMS = 2021,
        InvalidHMAC = 2022,
        InvalidPacketStructure = 2023,
        InvalidSpacecraftID = 2024,
        FrameSequenceCounter = 2025,
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

    inline Parameter<int32_t> magnetometerRawX(0);
    inline Parameter<int32_t> magnetometerRawY(0);
    inline Parameter<int32_t> magnetometerRawZ(0);
    inline Parameter<uint8_t> magnetometerFrequency(0);
    inline Parameter<uint16_t> magnetometerCycleCountX(0); //uint8_t(?)
    inline Parameter<uint16_t> magnetometerCycleCountY(0); //uint8_t(?)
    inline Parameter<uint16_t> magnetometerCycleCountZ(0); //uint8_t(?)
    inline Parameter<bool> magnetometerSelfTest(0);

    inline Parameter<float> gyroscopeX(0);
    inline Parameter<float> gyroscopeY(0);
    inline Parameter<float> gyroscopeZ(0);

    inline Parameter<uint16_t> gyroXLOCST1Register(0);
    inline Parameter<uint16_t> gyroXLOCST0Register(0);
    inline Parameter<uint16_t> gyroXHICST1Register(0);
    inline Parameter<uint16_t> gyroXHICST0Register(0);
    inline Parameter<uint16_t> gyroXQUAD1Register(0);
    inline Parameter<uint16_t> gyroXQUAD0Register(0);
    inline Parameter<uint16_t> gyroXFAULT1Register(0);
    inline Parameter<uint16_t> gyroXFAULT0Register(0);

    inline Parameter<uint16_t> gyroYLOCST1Register(0);
    inline Parameter<uint16_t> gyroYLOCST0Register(0);
    inline Parameter<uint16_t> gyroYHICST1Register(0);
    inline Parameter<uint16_t> gyroYHICST0Register(0);
    inline Parameter<uint16_t> gyroYQUAD1Register(0);
    inline Parameter<uint16_t> gyroYQUAD0Register(0);
    inline Parameter<uint16_t> gyroYFAULT1Register(0);
    inline Parameter<uint16_t> gyroYFAULT0Register(0);

    inline Parameter<uint16_t> gyroZLOCST1Register(0);
    inline Parameter<uint16_t> gyroZLOCST0Register(0);
    inline Parameter<uint16_t> gyroZHICST1Register(0);
    inline Parameter<uint16_t> gyroZHICST0Register(0);
    inline Parameter<uint16_t> gyroZQUAD1Register(0);
    inline Parameter<uint16_t> gyroZQUAD0Register(0);
    inline Parameter<uint16_t> gyroZFAULT1Register(0);
    inline Parameter<uint16_t> gyroZFAULT0Register(0);

    inline Parameter<float> gyroscopeXTemperature(0);
    inline Parameter<float> gyroscopeYTemperature(0);
    inline Parameter<float> gyroscopeZTemperature(0);

    inline Parameter<float> adcsBoardTemperature1(0);
    inline Parameter<float> adcsBoardTemperature2(0);

    inline Parameter<bool> magnetometerSignX(0);
    inline Parameter<bool> magnetometerSignY(0);
    inline Parameter<bool> magnetometerSignZ(0);

    inline Parameter<bool> gyroSignX(0);
    inline Parameter<bool> gyroSignY(0);
    inline Parameter<bool> gyroSignZ(0);

    inline Parameter<float> gyroBiasX(0);
    inline Parameter<float> gyroBiasY(0);
    inline Parameter<float> gyroBiasZ(0);

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

    inline Parameter<float> currentForRail3V1(0);
    inline Parameter<float> currentForRail3V2(0);
    inline Parameter<float> currentForRail3V3(0);
    inline Parameter<float> currentForRail3V4(0);
    inline Parameter<float> currentForRail5V1(0);
    inline Parameter<float> currentForRail5V2(0);
    inline Parameter<float> currentForRail5V3(0);
    inline Parameter<float> currentForRail5V4(0);
    inline Parameter<float> currentForRail1(0);
    inline Parameter<float> currentForRail2(0);
    inline Parameter<float> currentForRail3(0);
    inline Parameter<float> currentForRail4(0);
    inline Parameter<float> currentForRail5(0);

    inline Parameter<float> voltageForEachRail3V1(0);
    inline Parameter<float> voltageForEachRail3V2(0);
    inline Parameter<float> voltageForEachRail3V3(0);
    inline Parameter<float> voltageForEachRail3V4(0);
    inline Parameter<float> voltageForEachRail5V1(0);
    inline Parameter<float> voltageForEachRail5V2(0);
    inline Parameter<float> voltageForEachRail5V3(0);
    inline Parameter<float> voltageForEachRail5V4(0);
    inline Parameter<float> voltageForEachRail12V1(0);
    inline Parameter<float> voltageForEachRail12V2(0);
    inline Parameter<float> voltageForEachRail12V3(0);
    inline Parameter<float> voltageForEachRail12V4(0);

    inline Parameter<float> panelVoltageXPlus(0);
    inline Parameter<float> panelVoltageXMinus(0);
    inline Parameter<float> panelVoltageYPlus(0);
    inline Parameter<float> panelVoltageYMinus(0);
    inline Parameter<float> panelVoltageZ(0);

    inline Parameter<float> panelCurrentXPlus(0);
    inline Parameter<float> panelCurrentXMinus(0);
    inline Parameter<float> panelCurrentYPlus(0);
    inline Parameter<float> panelCurrentYMinus(0);
    inline Parameter<float> panelCurrentZ(0);

    inline Parameter<float> batteryPackVoltage(0);

    inline Parameter<float> panelTemperatureXPlus(0);
    inline Parameter<float> panelTemperatureXMinus(0);
    inline Parameter<float> panelTemperatureYPlus(0);
    inline Parameter<float> panelTemperatureYMinus(0);
    inline Parameter<float> panelTemperatureZ(0);

    inline Parameter<float> epsPCBTemperatureSensor1(0);
    inline Parameter<float> epsPCBTemperatureSensor2(0);

    inline Parameter<float> batteryTemperatureSensor1(0);
    inline Parameter<float> batteryTemperatureSensor2(0);

    /****************** COMMS PARAMETERS *******************/
    inline Parameter<float> uhfBandPATemperature(0);
    inline Parameter<float> sBandPATemperature(0);
    inline Parameter<float> commsPCBTemperature(0);

    inline Parameter<uint8_t> antennaDeploymentStatus(0); // enum

    inline Parameter<uint16_t> dataRateUHFTX(0);
    inline Parameter<uint16_t> dataRateUHFRX(0);
    inline Parameter<uint16_t> symbolRateSBand(0);
    inline Parameter<uint16_t> cwInterval(0);
    inline Parameter<uint16_t> gmskBeaconInterval(0);
    inline Parameter<uint16_t> uhfBandTXPower(0);
    inline Parameter<uint16_t> sBandTXPower(0);
    inline Parameter<uint16_t> channelNumberUHFBand(0);
    inline Parameter<uint16_t> channelNumberSBand(0);

    // enums
    inline Parameter<uint8_t> lnaGain(0);
    inline Parameter<uint16_t> paGainUHFBand(0);
    inline Parameter<uint16_t> paGainSBand(0);

    inline Parameter<uint16_t> vgaGain(0);
    inline Parameter<float> rssi(0);

    inline Parameter<bool> uhfBandTXOnOff(0);
    inline Parameter<bool> uhfBandRXOnOff(0);
    inline Parameter<bool> sBandTXOnOff(0);

    inline Parameter<uint16_t> packetsRejectedCOMMS(0);
    inline Parameter<uint16_t> invalidHMAC(0);
    inline Parameter<uint16_t> invalidPacketStructure(0);
    inline Parameter<uint16_t> invalidSpacecraftID(0);
    inline Parameter<uint16_t> frameSequenceCounter(0);

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
