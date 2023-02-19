#ifndef ECSS_SERVICES_PLATFORMPARAMETERS_HPP
#define ECSS_SERVICES_PLATFORMPARAMETERS_HPP

#include "CAN/Driver.hpp"
#include "Helpers/Parameter.hpp"

namespace PlatformParameters {
    /**
     * ID enumeration of OBDH subsystem's specific parameters.
     */
    enum ParameterID : uint16_t {
        AvailableHeap = 7,
        OBCUseRTT = 8,
        OBCUseUART = 9,
        OBCUseCAN = 10,

        /* OBDH Parameters */
        OBCPCBTemperature1 = 5000,
        OBCPCBTemperature2 = 5001,
        OBCMCUTemperature = 5002,
        OBCMCUInputVoltage = 5003,
        OBCMCUBootCounter = 5004,
        OBCFlashInt = 5005,
        OBCSRAMInt = 5006,
        OBCMRAM = 5007,
        OBCNAND = 5008,
        OBCSpacecraftTimeRef = 5009,
        OBCMCUTime = 5010,
        OBCOperationalMode = 5011,
        OBCMemoryPartition = 5012,
        OBCReconfigurationTimer = 5013,
        OBCLastFailedEvent = 5014,
        OBCMCUSystick = 5015,
        OBCCANBUSLoad1 = 5016,
        OBCCANBUSLoad2 = 5017,
        OBCCANBUSActive = 5018,
        OBCMCUFDIR = 5019,
        OBCMCURestartSafeModeThreshold = 5020,
        OBCNANDFLASHLCLThreshold = 5021,
        OBCMRAMLCLThreshold = 5022,
        OBCNANDFLASHON = 5023,
        OBCMRAMON = 5024,
        OBCNANDFLASHScrubbingFrequency = 5025,
        OBCRAMScrubbingFrequency = 5026,
        OBCProgramFlashScrubbingFrequency = 5027,

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
        SUTemperatureFromHumiditySensor1 = 4059,
        SUTemperatureFromHumiditySensor2 = 4060,

        /* ADCS */
        ADCSUseRTT = 11,
        ADCSUseUART = 12,
        ADCSUseCAN = 13,

        ADCSXBodyFrameRegardingOrbitFrame = 1000,
        ADCSYBodyFrameRegardingOrbitFrame = 1001,
        ADCSZBodyFrameRegardingOrbitFrame = 1002,
        ADCSAngularVelocityOnX = 1003,
        ADCSAngularVelocityOnY = 1004,
        ADCSAngularVelocityOnZ = 1005,
        ADCSBDotXAxis = 1006,
        ADCSBDotYAxis = 1007,
        ADCSBDotZAxis = 1008,
        ADCSQuaternionOrbitFrameToBodyScalar = 1009,
        ADCSQuaternionOrbitFrameToBodyVectorElem1 = 1010,
        ADCSQuaternionOrbitFrameToBodyVectorElem2 = 1011,
        ADCSQuaternionOrbitFrameToBodyVectorElem3 = 1012,

        ADCSMagnetometerRawX = 1013,
        ADCSMagnetometerRawY = 1014,
        ADCSMagnetometerRawZ = 1015,
        ADCSMagnetometerFrequency = 1016,
        ADCSMagnetometerCycleCountX = 1017,
        ADCSMagnetometerCycleCountY = 1018,
        ADCSMagnetometerCycleCountZ = 1019,
        ADCSMagnetometerSelfTest = 1020,

        ADCSMagnetometerISISCalibratedXAxis = 1021,
        ADCSMagnetometerISISCalibratedYAxis = 1022,
        ADCSMagnetometerISISCalibratedZAxis = 1023,
        ADCSMagnetometerISISFilteredXAxis = 1024,
        ADCSMagnetometerISISFilteredYAxis = 1025,
        ADCSMagnetometerISISFilteredZAxis = 1026,
        ADCSMagnetometerISISRawXAxis = 1027,
        ADCSMagnetometerISISRawYAxis = 1028,
        ADCSMagnetometerISISRawZAxis = 1029,
        ADCSFineSunSensorRawTopLeft = 1030,
        ADCSFineSunSensorRawTopRight = 1031,
        ADCSFineSunSensorRawBottomLeft = 1032,
        ADCSFineSunSensorRawBottomRight = 1033,
        ADCSFineSunSensorFilteredTopLeft = 1034,
        ADCSFineSunSensorFilteredTopRight = 1035,
        ADCSFineSunSensorFilteredBottomLeft = 1036,
        ADCSFineSunSensorFilteredBottomRight = 1037,
        ADCSFineSunSensorAngularAlphaAngle = 1038,
        ADCSFineSunSensorAngularBetaAngle = 1039,
        ADCSFineSunSensorCalculatedX = 1040,
        ADCSFineSunSensorCalculatedY = 1041,
        ADCSFineSunSensorCalculatedZ = 1042,

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

        ADCSMagnetorquerOnXAxisHBridgePolarity = 1070,
        ADCSMagnetorquerOnYAxisHBridgePolarity = 1071,
        ADCSMagnetorquerOnZAxisHBridgePolarity = 1072,
        ADCSMagnetorquerOnXAxisOnOff = 1073,
        ADCSMagnetorquerOnYAxisOnOff = 1074,
        ADCSMagnetorquerOnZAxisOnOff = 1075,
        ADCSGainBdot1 = 1076,
        ADCSGainBdot2 = 1077,
        ADCSGainBdot3 = 1078,
        ADCSGainProportionalPD1 = 1079,
        ADCSGainProportionalPD2 = 1080,
        ADCSGainProportionalPD3 = 1081,
        ADCSGainDerivativePD1 = 1082,
        ADCSGainDerivativePD2 = 1083,
        ADCSGainDerivativePD3 = 1084,
        ADCSiMQTBoardCoilXTemperatureSensor = 1085,
        ADCSiMQTBoardCoilYTemperatureSensor = 1086,
        ADCSiMQTBoardCoilZTemperatureSensor = 1087,
        ADCSiMQTBoardExtraTemperatureSensor = 1088,

        ADCSGyroscopeXTemperature = 1089,
        ADCSGyroscopeYTemperature = 1090,
        ADCSGyroscopeZTemperature = 1091,
        ADCSBoardTemperature1 = 1092,
        ADCSBoardTemperature2 = 1093,

        ADCSMode = 1094,
        ADCSTLE = 1095,
        ADCSInitialKalmanQuaternionECIFrameToBodyScalar = 1096,
        ADCSInitialKalmanQuaternionECIFrameToBodyVectorElem1 = 1097,
        ADCSInitialKalmanQuaternionECIFrameToBodyVectorElem2 = 1098,
        ADCSInitialKalmanQuaternionECIFrameToBodyVectorElem3 = 1099,
        ADCSTLEOrbitalElementsArgumentPerigee = 1100,
        ADCSTLEOrbitalElementsRAAN = 1101,
        ADCSTLEOrbitalElementsInclination = 1102,
        ADCSTLEOrbitalElementsEccentricity = 1103,
        ADCSTLEOrbitalElementsMeanAnomaly = 1104,
        ADCSSGP4OrbitalElementsArgumentPerigee = 1105,
        ADCSSGP4OrbitalElementsRAAN = 1106,
        ADCSSGP4OrbitalElementsInclination = 1107,
        ADCSSGP4OrbitalElementsMeanAnomaly = 1108,
        ADCSTimeGST_JD = 1109,
        ADCSDeterminationInitialMatricesQ1 = 1110,
        ADCSDeterminationInitialMatricesQ2 = 1111,
        ADCSDeterminationInitialMatricesQ3 = 1112,
        ADCSDeterminationInitialMatricesQ4 = 1113,
        ADCSDeterminationInitialMatricesQ5 = 1114,
        ADCSDeterminationInitialMatricesQ6 = 1115,
        ADCSDeterminationInitialMatricesQ7 = 1116,
        ADCSDeterminationInitialMatricesQ8 = 1117,
        ADCSDeterminationInitialMatricesQ9 = 1118,
        ADCSDeterminationInitialMatricesQ10 = 1119,
        ADCSDeterminationInitialMatricesR1 = 1120,
        ADCSDeterminationInitialMatricesR2 = 1121,
        ADCSDeterminationInitialMatricesR3 = 1122,
        ADCSDeterminationInitialMatricesR4 = 1123,
        ADCSDeterminationInitialMatricesR5 = 1124,
        ADCSDeterminationInitialMatricesR6 = 1125,
        ADCSDeterminationInitialMatricesR7 = 1126,
        ADCSDeterminationInitialMatricesR8 = 1127,
        ADCSDeterminationInitialMatricesR9 = 1128,
        ADCSDeterminationInitialMatricesPInitial1 = 1129,
        ADCSDeterminationInitialMatricesPInitial2 = 1130,
        ADCSDeterminationInitialMatricesPInitial3 = 1131,
        ADCSDeterminationInitialMatricesPInitial4 = 1132,
        ADCSDeterminationInitialMatricesPInitial5 = 1133,
        ADCSDeterminationInitialMatricesPInitial6 = 1134,
        ADCSDeterminationInitialMatricesPInitial7 = 1135,
        ADCSDeterminationInitialMatricesPInitial8 = 1136,
        ADCSDeterminationInitialMatricesPInitial9 = 1137,
        ADCSDeterminationInitialMatricesPInitial10 = 1138,
        ADCSReactionWheelOnOff = 1139,
        ADCSReactionWheelAngularVelocity = 1140,
        ADCSMagnetorquerAxisAssignment = 1141,
        ADCSControlProfileSwitching = 1142,
        ADCSTransformationAxisXAssignment = 1143,
        ADCSTransformationAxisYAssignment = 1144,
        ADCSTransformationAxisZAssignment = 1145,
        ADCSMagnetometerAxisAssignment = 1146,
        ADCSSunSensorAxisAssignment = 1147,
        ADCSGyroscopeAxisAssignment = 1148,
        ADCSFrameAxisSignECIToECEF_X = 1149,
        ADCSFrameAxisSignECIToECEF_Y = 1150,
        ADCSFrameAxisSignECIToECEF_Z = 1151,
        ADCSFrameAxisSignECIToOrbit_X = 1152,
        ADCSFrameAxisSignECIToOrbit_Y = 1153,
        ADCSFrameAxisSignECIToOrbit_Z = 1154,
        ADCSFrameAxisSignNEDToECEF_X = 1155,
        ADCSFrameAxisSignNEDToECEF_Y = 1156,
        ADCSFrameAxisSignNEDToECEF_Z = 1157,

        ADCSMagnetometerSignX = 1158,
        ADCSMagnetometerSignY = 1159,
        ADCSMagnetometerSignZ = 1160,

        ADCSSunSensorXAxisSign = 1161,
        ADCSSunSensorYAxisSign = 1162,
        ADCSSunSensorZAxisSign = 1163,

        ADCSGyroSignX = 1164,
        ADCSGyroSignY = 1165,
        ADCSGyroSignZ = 1166,

        ADCSDetumblingNominalThresholds = 1167,
        ADCSNominalDetumblingThresholds = 1168,
        ADCSStandByDetumblingThresholds = 1169,
        ADCSDetumblingStandByThresholds = 1170,
        ADCSNominalStandByThresholds = 1171,
        ADCSMagnetorquerMagneticDipoleX = 1172,
        ADCSMagnetorquerMagneticDipoleY = 1173,
        ADCSMagnetorquerMagneticDipoleZ = 1174,
        ADCSMagnetorquerDutyCycle = 1175,
        ADCSMagnetorquerCurrentX = 1176,
        ADCSMagnetorquerCurrentY = 1177,
        ADCSMagnetorquerCurrentZ = 1178,
        ADCSMagnetorquerBDot = 1179,
        ADCSReactionWheelTorque = 1180,
        ADCSReactionWheelAngularAcceleration = 1181,
        ADCSDesiredQuaternionOrbitToBodyScalar = 1182,
        ADCSDesiredQuaternionVectorElem1 = 1183,
        ADCSDesiredQuaternionVectorElem2 = 1184,
        ADCSDesiredQuaternionVectorElem3 = 1185,
        ADCSAngularVelocityDesiredX = 1186,
        ADCSAngularVelocityDesiredY = 1187,
        ADCSAngularVelocityDesiredZ = 1188,

        ADCSGyroBiasX = 1189,
        ADCSGyroBiasY = 1190,
        ADCSGyroBiasZ = 1191,

        ADCSSatellitePositionLatitude = 1192,
        ADCSSatellitePositionLongitude = 1193,
        ADCSSatellitePositionHeight = 1194,
        ADCSSatellitePositionECIX = 1195,
        ADCSSatellitePositionECIY = 1196,
        ADCSSatellitePositionECIZ = 1197,
        ADCSSatelliteLinearVelocityECIX = 1198,
        ADCSSatelliteLinearVelocityECIY = 1199,
        ADCSSatelliteLinearVelocityECIZ = 1200,
        ADCSMagneticFieldNEDX = 1201,
        ADCSMagneticFieldNEDY = 1202,
        ADCSMagneticFieldNEDZ = 1203,
        ADCSMagneticFieldECIX = 1204,
        ADCSMagneticFieldECIY = 1205,
        ADCSMagneticFieldECIZ = 1206,
        ADCSSunPositionECIX = 1207,
        ADCSSunPositionECIY = 1208,
        ADCSSunPositionECIZ = 1209,
        ADCSEclipse = 1210,
        ADCSDesaturationPecentageParameter = 1211,
        ADCSISISMTQModes = 1212,
        ADCSMagnetorquerActuationMethod = 1213,
        ADCSDutyCycleDetermination = 1214,
        ADCSDutyCycleControl = 1215,
        ADCSDutyCycleOther = 1216,
        ADCSDesatInitialAngularVelocityParam = 1217,

        ADCSMCUTemperature = 1218,

        ADCSMCUInputVoltage = 1219,

        ADCSBootCounter = 1220,
        ADCSMCUOnBoardTime = 1221,

        ADCSMemoryPartition = 1222,
        ADCSLastFailedEvent = 1223,

        ADCSSystick = 1224,

        ADCSRAMScrubbingFrequency = 1225,
        ADCSProgramFlashScrubbingFrequency = 1226,
        ADCSFLASHInt = 1227,
        ADCSSRAMInt = 1228,

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
        COMMSMCUSystick = 2034,
        COMMSFlashInt = 2035,
        COMMSSRAMInt = 2036
    };

    // Parameters used for testing
    inline Parameter<uint16_t> availableHeap(0);

    /******************* OBDH PARAMETERS *******************/
    inline Parameter<bool> obcUseRTT(true);
    inline Parameter<bool> obcUseUART(true);
    inline Parameter<bool> obcUseCAN(false);

    inline Parameter<float> obcPCBTemperature1(0);
    inline Parameter<float> obcPCBTemperature2(0);
    inline Parameter<float> obcMCUTemperature(0);
    inline Parameter<float> obcMCUInputVoltage(0);

    inline Parameter<uint16_t> obcMCUBootCounter(0);
    inline Parameter<uint32_t> obcFlashInt(0);
    inline Parameter<uint32_t> obcSRAMInt(0);
    inline Parameter<uint32_t> obcMRAM(0);
    inline Parameter<uint32_t> obcNAND(0);

    inline Parameter<Time::DefaultCUC> obcMCUTime(Time::DefaultCUC(0));

    inline Parameter<uint16_t> obcSpacecraftTimeRef(0); // enum
    inline Parameter<uint8_t> obcOperationalMode(0); // enum
    inline Parameter<bool> obcMemoryPartition(0); // enum

    inline Parameter<uint32_t> obcReconfigurationTimer(0);
    inline Parameter<uint16_t> obcLastFailedEvent(0);
    inline Parameter<uint32_t> obcMCUSystick(0);

    inline Parameter<float> obcCANBUSLoad1(0);
    inline Parameter<float> obcCANBUSLoad2(0);

    inline Parameter<CAN::Driver::ActiveBus> obcCANBUSActive(CAN::Driver::Main); // enum
    inline Parameter<bool> obcMCUFDIR(0); // enum

    inline Parameter<uint8_t> obcMCURestartSafeModeThreshold(0);
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

    inline Parameter<float> suTemperatureFromHumiditySensor1(0);
    inline Parameter<float> suTemperatureFromHumiditySensor2(0);

    /******************* ADCS PARAMETERS *******************/
    inline Parameter<bool> adcsUseRTT(true);
    inline Parameter<bool> adcsUseUART(false);
    inline Parameter<bool> adcsUseCAN(false);

    inline Parameter<float> adcsXBodyFrameRegardingOrbitFrame(0);
    inline Parameter<float> adcsYBodyFrameRegardingOrbitFrame(0);
    inline Parameter<float> adcsZBodyFrameRegardingOrbitFrame(0);
    inline Parameter<float> adcsAngularVelocityOnX(0);
    inline Parameter<float> adcsAngularVelocityOnY(0);
    inline Parameter<float> adcsAngularVelocityOnZ(0);
    inline Parameter<float> adcsBDotXAxis(0);
    inline Parameter<float> adcsBDotYAxis(0);
    inline Parameter<float> adcsBDotZAxis(0);
    inline Parameter<float> adcsQuaternionOrbitFrameToBodyScalar(0);
    inline Parameter<float> adcsQuaternionOrbitFrameToBodyVectorElem1(0);
    inline Parameter<float> adcsQuaternionOrbitFrameToBodyVectorElem2(0);
    inline Parameter<float> adcsQuaternionOrbitFrameToBodyVectorElem3(0);

    inline Parameter<int32_t> adcsMagnetometerRawX(0);
    inline Parameter<int32_t> adcsMagnetometerRawY(0);
    inline Parameter<int32_t> adcsMagnetometerRawZ(0);
    inline Parameter<uint8_t> adcsMagnetometerFrequency(0);
    inline Parameter<uint16_t> adcsMagnetometerCycleCountX(0); //uint8_t(?)
    inline Parameter<uint16_t> adcsMagnetometerCycleCountY(0); //uint8_t(?)
    inline Parameter<uint16_t> adcsMagnetometerCycleCountZ(0); //uint8_t(?)
    inline Parameter<bool> adcsMagnetometerSelfTest(0);

    inline Parameter<int32_t> adcsMagnetometerISISCalibratedXAxis(0);
    inline Parameter<int32_t> adcsMagnetometerISISCalibratedYAxis(0);
    inline Parameter<int32_t> adcsMagnetometerISISCalibratedZAxis(0);
    inline Parameter<int32_t> adcsMagnetometerISISFilteredXAxis(0);
    inline Parameter<int32_t> adcsMagnetometerISISFilteredYAxis(0);
    inline Parameter<int32_t> adcsMagnetometerISISFilteredZAxis(0);
    inline Parameter<int32_t> adcsMagnetometerISISRawXAxis(0);
    inline Parameter<int32_t> adcsMagnetometerISISRawYAxis(0);
    inline Parameter<int32_t> adcsMagnetometerISISRawZAxis(0);

    inline Parameter<float> adcsFineSunSensorRawTopLeft(0);
    inline Parameter<float> adcsFineSunSensorRawTopRight(0);
    inline Parameter<float> adcsFineSunSensorRawBottomLeft(0);
    inline Parameter<float> adcsFineSunSensorRawBottomRight(0);
    inline Parameter<float> adcsFineSunSensorFilteredTopLeft(0);
    inline Parameter<float> adcsFineSunSensorFilteredTopRight(0);
    inline Parameter<float> adcsFineSunSensorFilteredBottomLeft(0);
    inline Parameter<float> adcsFineSunSensorFilteredBottomRight(0);
    inline Parameter<float> adcsFineSunSensorAngularAlphaAngle(0);
    inline Parameter<float> adcsFineSunSensorAngularBetaAngle(0);
    inline Parameter<float> adcsFineSunSensorCalculatedX(0);
    inline Parameter<float> adcsFineSunSensorCalculatedY(0);
    inline Parameter<float> adcsFineSunSensorCalculatedZ(0);

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

    inline Parameter<bool> adcsMagnetorquerOnXAxisHBridgePolarity(0);
    inline Parameter<bool> adcsMagnetorquerOnYAxisHBridgePolarity(0);
    inline Parameter<bool> adcsMagnetorquerOnZAxisHBridgePolarity(0);
    inline Parameter<bool> adcsMagnetorquerOnXAxisOnOff(0);
    inline Parameter<bool> adcsMagnetorquerOnYAxisOnOff(0);
    inline Parameter<bool> adcsMagnetorquerOnZAxisOnOff(0);

    inline Parameter<float> adcsGainBdot1(0);
    inline Parameter<float> adcsGainBdot2(0);
    inline Parameter<float> adcsGainBdot3(0);
    inline Parameter<float> adcsGainProportionalPD1(0);
    inline Parameter<float> adcsGainProportionalPD2(0);
    inline Parameter<float> adcsGainProportionalPD3(0);
    inline Parameter<float> adcsGainDerivativePD1(0);
    inline Parameter<float> adcsGainDerivativePD2(0);
    inline Parameter<float> adcsGainDerivativePD3(0);

    inline Parameter<int16_t> adcsiMQTBoardCoilXTemperatureSensor(0);
    inline Parameter<int16_t> adcsiMQTBoardCoilYTemperatureSensor(0);
    inline Parameter<int16_t> adcsiMQTBoardCoilZTemperatureSensor(0);
    inline Parameter<int16_t> adcsiMQTBoardExtraTemperatureSensor(0);

    inline Parameter<float> adcsGyroscopeXTemperature(0);
    inline Parameter<float> adcsGyroscopeYTemperature(0);
    inline Parameter<float> adcsGyroscopeZTemperature(0);

    inline Parameter<float> adcsBoardTemperature1(0);
    inline Parameter<float> adcsBoardTemperature2(0);

    inline Parameter<int16_t> adcsMode(0); // enum
    inline Parameter<int8_t> adcsTLE(0); // string

    inline Parameter<float> adcsInitialKalmanQuaternionECIFrameToBodyScalar(0);
    inline Parameter<float> adcsInitialKalmanQuaternionECIFrameToBodyVectorElem1(0);
    inline Parameter<float> adcsInitialKalmanQuaternionECIFrameToBodyVectorElem2(0);
    inline Parameter<float> adcsInitialKalmanQuaternionECIFrameToBodyVectorElem3(0);
    inline Parameter<float> adcsTLEOrbitalElementsArgumentPerigee(0);
    inline Parameter<float> adcsTLEOrbitalElementsRAAN(0);
    inline Parameter<float> adcsTLEOrbitalElementsInclination(0);
    inline Parameter<float> adcsTLEOrbitalElementsEccentricity(0);
    inline Parameter<float> adcsTLEOrbitalElementsMeanAnomaly(0);

    inline Parameter<double> adcsSGP4OrbitalElementsArgumentPerigee(0);
    inline Parameter<double> adcsSGP4OrbitalElementsRAAN(0);
    inline Parameter<double> adcsSGP4OrbitalElementsInclination(0);
    inline Parameter<double> adcsSGP4OrbitalElementsMeanAnomaly(0);
    inline Parameter<double> adcsTimeGST_JD(0);

    inline Parameter<float> adcsDeterminationInitialMatricesQ1(0);
    inline Parameter<float> adcsDeterminationInitialMatricesQ2(0);
    inline Parameter<float> adcsDeterminationInitialMatricesQ3(0);
    inline Parameter<float> adcsDeterminationInitialMatricesQ4(0);
    inline Parameter<float> adcsDeterminationInitialMatricesQ5(0);
    inline Parameter<float> adcsDeterminationInitialMatricesQ6(0);
    inline Parameter<float> adcsDeterminationInitialMatricesQ7(0);
    inline Parameter<float> adcsDeterminationInitialMatricesQ8(0);
    inline Parameter<float> adcsDeterminationInitialMatricesQ9(0);
    inline Parameter<float> adcsDeterminationInitialMatricesQ10(0);
    inline Parameter<float> adcsDeterminationInitialMatricesR1(0);
    inline Parameter<float> adcsDeterminationInitialMatricesR2(0);
    inline Parameter<float> adcsDeterminationInitialMatricesR3(0);
    inline Parameter<float> adcsDeterminationInitialMatricesR4(0);
    inline Parameter<float> adcsDeterminationInitialMatricesR5(0);
    inline Parameter<float> adcsDeterminationInitialMatricesR6(0);
    inline Parameter<float> adcsDeterminationInitialMatricesR7(0);
    inline Parameter<float> adcsDeterminationInitialMatricesR8(0);
    inline Parameter<float> adcsDeterminationInitialMatricesR9(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial1(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial2(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial3(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial4(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial5(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial6(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial7(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial8(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial9(0);
    inline Parameter<float> adcsDeterminationInitialMatricesPInitial10(0);

    inline Parameter<bool> adcsReactionWheelOnOff(0);
    inline Parameter<float> adcsReactionWheelAngularVelocity(0);
    inline Parameter<bool> adcsControlProfileSwitching(0);

    inline Parameter<uint16_t> adcsMagnetorquerAxisAssignment(0); // enum
    inline Parameter<uint16_t> adcsTransformationAxisXAssignment(0); // enum
    inline Parameter<uint16_t> adcsTransformationAxisYAssignment(0); // enum
    inline Parameter<uint16_t> adcsTransformationAxisZAssignment(0); // enum
    inline Parameter<uint16_t> adcsMagnetometerAxisAssignment(0); // enum
    inline Parameter<uint16_t> adcsSunSensorAxisAssignment(0); // enum
    inline Parameter<uint16_t> adcsGyroscopeAxisAssignment(0); // enum

    inline Parameter<bool> adcsFrameAxisSignECIToECEF_X(0);
    inline Parameter<bool> adcsFrameAxisSignECIToECEF_Y(0);
    inline Parameter<bool> adcsFrameAxisSignECIToECEF_Z(0);
    inline Parameter<bool> adcsFrameAxisSignECIToOrbit_X(0);
    inline Parameter<bool> adcsFrameAxisSignECIToOrbit_Y(0);
    inline Parameter<bool> adcsFrameAxisSignECIToOrbit_Z(0);
    inline Parameter<bool> adcsFrameAxisSignNEDToECEF_X(0);
    inline Parameter<bool> adcsFrameAxisSignNEDToECEF_Y(0);
    inline Parameter<bool> adcsFrameAxisSignNEDToECEF_Z(0);

    inline Parameter<bool> adcsMagnetometerSignX(0);
    inline Parameter<bool> adcsMagnetometerSignY(0);
    inline Parameter<bool> adcsMagnetometerSignZ(0);

    inline Parameter<bool> adcsSunSensorXAxisSign(0);
    inline Parameter<bool> adcsSunSensorYAxisSign(0);
    inline Parameter<bool> adcsSunSensorZAxisSign(0);

    inline Parameter<bool> adcsGyroSignX(0);
    inline Parameter<bool> adcsGyroSignY(0);
    inline Parameter<bool> adcsGyroSignZ(0);

    inline Parameter<float> adcsDetumblingNominalThresholds(0);
    inline Parameter<float> adcsNominalDetumblingThresholds(0);
    inline Parameter<float> adcsStandByDetumblingThresholds(0);
    inline Parameter<float> adcsDetumblingStandByThresholds(0);
    inline Parameter<float> adcsNominalStandByThresholds(0);
    inline Parameter<float> adcsMagnetorquerMagneticDipoleX(0);
    inline Parameter<float> adcsMagnetorquerMagneticDipoleY(0);
    inline Parameter<float> adcsMagnetorquerMagneticDipoleZ(0);

    inline Parameter<uint16_t> adcsMagnetorquerDutyCycle(0); // enum

    inline Parameter<uint16_t> adcsMagnetorquerCurrentX(0);
    inline Parameter<uint16_t> adcsMagnetorquerCurrentY(0);
    inline Parameter<uint16_t> adcsMagnetorquerCurrentZ(0);

    inline Parameter<float> adcsMagnetorquerBDot(0);
    inline Parameter<float> adcsReactionWheelTorque(0);
    inline Parameter<float> adcsReactionWheelAngularAcceleration(0);
    inline Parameter<float> adcsDesiredQuaternionOrbitToBodyScalar(0);
    inline Parameter<float> adcsDesiredQuaternionVectorElem1(0);
    inline Parameter<float> adcsDesiredQuaternionVectorElem2(0);
    inline Parameter<float> adcsDesiredQuaternionVectorElem3(0);
    inline Parameter<float> adcsAngularVelocityDesiredX(0);
    inline Parameter<float> adcsAngularVelocityDesiredY(0);
    inline Parameter<float> adcsAngularVelocityDesiredZ(0);

    inline Parameter<float> adcsGyroBiasX(0);
    inline Parameter<float> adcsGyroBiasY(0);
    inline Parameter<float> adcsGyroBiasZ(0);

    inline Parameter<double> adcsSatellitePositionLatitude(0);
    inline Parameter<double> adcsSatellitePositionLongitude(0);
    inline Parameter<double> adcsSatellitePositionHeight(0);

    inline Parameter<float> adcsSatellitePositionECIX(0);
    inline Parameter<float> adcsSatellitePositionECIY(0);
    inline Parameter<float> adcsSatellitePositionECIZ(0);
    inline Parameter<float> adcsSatelliteLinearVelocityECIX(0);
    inline Parameter<float> adcsSatelliteLinearVelocityECIY(0);
    inline Parameter<float> adcsSatelliteLinearVelocityECIZ(0);
    inline Parameter<float> adcsMagneticFieldNEDX(0);
    inline Parameter<float> adcsMagneticFieldNEDY(0);
    inline Parameter<float> adcsMagneticFieldNEDZ(0);
    inline Parameter<float> adcsMagneticFieldECIX(0);
    inline Parameter<float> adcsMagneticFieldECIY(0);
    inline Parameter<float> adcsMagneticFieldECIZ(0);
    inline Parameter<float> adcsSunPositionECIX(0);
    inline Parameter<float> adcsSunPositionECIY(0);
    inline Parameter<float> adcsSunPositionECIZ(0);

    inline Parameter<bool> adcsEclipse(0);

    inline Parameter<float> adcsDesaturationPecentageParameter(0);

    inline Parameter<uint16_t> adcsISISMTQModes(0); // enum
    inline Parameter<uint16_t> adcsMagnetorquerActuationMethod(0); // enum

    inline Parameter<float> adcsDutyCycleDetermination(0);
    inline Parameter<float> adcsDutyCycleControl(0);
    inline Parameter<float> adcsDutyCycleOther(0);
    inline Parameter<float> adcsDesatInitialAngularVelocityParam(0);

    inline Parameter<float> adcsMCUTemperature(0);
    inline Parameter<float> adcsMCUInputVoltage(0);
    inline Parameter<uint16_t> adcsBootCounter(0);
    inline Parameter<float> adcsMCUOnBoardTime(0);
    inline Parameter<uint16_t> adcsMemoryPartition(0); // enum
    inline Parameter<int32_t> adcsLastFailedEvent(0);
    inline Parameter<uint64_t> adcsSystick(0);
    inline Parameter<float> adcsRAMScrubbingFrequency(0);
    inline Parameter<float> adcsProgramFlashScrubbingFrequency(0);
    inline Parameter<uint32_t> adcsSRAMInt(0);
    inline Parameter<uint32_t> adcsFlashInt(0);

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
    inline Parameter<uint32_t> commsFlashInt(0);
    inline Parameter<uint32_t> commsSRAMInt(0);
}

#endif
