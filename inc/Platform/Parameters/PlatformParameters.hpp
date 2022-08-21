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
        UseRTT = 8,
        UseUART = 9,
        UseCAN = 10,
        OBCBoardTemperature1 = 290,
        OBCMCUTemperature = 293,
        OBCBootCounter = 301,
        OBCSystick = 329,

        /* SU */
        MCUBootCounter = 4040,
        MCUSysTick = 4047,
        MCUTemperature = 4038,
        MCUInputVoltage = 4039,
        FlashIntUsedPercentage = 4041,
        FlashUsedPercentage = 4042,
        SRAMUsedPercentage = 4043,
        NANDCurrentlyUsedPartition = 4045,
        NANDFlashLCLOn = 4052,
        NANDFlashLCLThreshold = 4048,
        NANDFlashScrubbingFrequency = 4056,
        RAMScrubbingFrequency = 4057,
        ProgramFlashScrubbingFrequency = 4058,
        ControlPumpFlashLCLOn = 4054,
        ControlPumpFlashLCLThreshold = 4050,
        FlowPumpFlashOn = 4053,
        FlowPumpFlashLCLThreshold = 4049,
        CameraON = 4055,
        CameraLCLThreshold = 4051,
        PCBTemperature1 = 4000,
        PCBTemperature2 = 4001,
        PCBTemperatureControlValves = 4002,
        PCBTemperatureFlowValves = 4003,
        CameraTemperature = 4037,
        PDMSTemperature = 4004,
        GrowthMediumTemperature = 4005,
        LastFailedEvent = 4046,
        PressureLevelSensor1 = 4010,
        PressureLevelSensor2 = 4011,
        HumidityLevelSensor1 = 4012,
        HumidityLevelSensor2 = 4013,
        RADFET = 4036,
        PumpFlowRate1 = 4015,
        PumpFlowRate2 = 4016,
        ControlChamberValve1 = 4017,
        ControlChamberValve2 = 4018,
        ControlChamberValve3 = 4019,
        ControlSandwitchValve1 = 4020,
        ControlSandwitchValve2 = 4021,
        ControlSandwitchValve3 = 4022,
        FlowValveInlet1 = 4023,
        FlowValveInlet2 = 4024,
        FlowValveInlet3 = 4025,
        FlowValveOutlet1 = 4026,
        FlowValveOutlet2 = 4027,
        FlowValveOutlet3 = 4028,
        FlowValveTest1 = 4029,
        FlowValveTest2 = 4030,
        LEDIntensity1 = 4006,
        LEDIntensity2 = 4007,
        LEDIntensity3 = 4008,
        LEDIntensity4 = 4009,
        NumberOfPhotosTaken = 4014,
        PhotoExposureTime = 4031,
        PhotoInterval = 4032,
        PhotoCroppedResolution = 4033,
        PhotoCompressionRate = 4034,
        ExperimentNumber = 4035,
        OnBoardTime = 4044,

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

    // OBDH parameters
    inline Parameter<uint16_t> obcBootCounter(0);
    inline Parameter<uint64_t> obcSysTick(0);
    inline Parameter<float> mcuTemperature(0);
    inline Parameter<float> obcBoardTemperature1(0);
    inline Parameter<bool> useRTT(true);
    inline Parameter<bool> useUART(true);
    inline Parameter<bool> useCAN(false);

    /******************* SU PARAMETERS *******************/
    // MCU
    inline Parameter<uint32_t> mcuBootCounter(0);
    inline Parameter<uint32_t> mcuSysTick(0);

    inline Parameter<float> mcuInputVoltage(0);

    // Memory
    inline Parameter<uint32_t> flashIntUsedPercentage(0);
    inline Parameter<uint32_t> flashUsedPercentage(0);
    inline Parameter<uint32_t> sramUsedPercentage(0);

    inline Parameter<uint8_t> nandCurrentlyUsedPartition(0); // FIXME: is enum in database
    inline Parameter<float> nandFlashLclOn(0);
    inline Parameter<float> nandFlashLclThreshold(0);

    inline Parameter<float> nandFlashScrubbingFrequency(0);
    inline Parameter<float> ramScrubbingFrequency(0);
    inline Parameter<float> programFlashScrubbingFrequency(0);

    // Components
    inline Parameter<float> controlPumpFlashLclOn(0);
    inline Parameter<float> controlPumpFlashLclThreshold(0);

    inline Parameter<float> flowPumpFlashOn(0);
    inline Parameter<float> flowPumpFlashLclThreshold(0);

    inline Parameter<float> cameraOn(0);
    inline Parameter<float> cameraLclThreshold(0);

    // Temperatures
    inline Parameter<float> pcbTemperature1(0);
    inline Parameter<float> pcbTemperature2(0);

    inline Parameter<float> pcbTemperatureControlValves(0);
    inline Parameter<float> pcbTemperatureFlowValves(0);

    inline Parameter<float> cameraTemperature(0);
    inline Parameter<float> pdmsTemperature(0);
    inline Parameter<float> growthMediumTemperature(0);

    // Misc
    inline Parameter<uint32_t> onBoardTime(0);
    inline Parameter<uint16_t> lastFailedEvent(0);

    // Sensors
    inline Parameter<float> pressureLevelSensor1(0);
    inline Parameter<float> pressureLevelSensor2(0);

    inline Parameter<float> humidityLevelSensor1(0);
    inline Parameter<float> humidityLevelSensor2(0);

    inline Parameter<double> radfet(0);

    // Components
    inline Parameter<float> pumpFlowRate1(0);
    inline Parameter<float> pumpFlowRate2(0);

    inline Parameter<bool> controlChamberValve1(0);
    inline Parameter<bool> controlChamberValve2(0);
    inline Parameter<bool> controlChamberValve3(0);

    inline Parameter<bool> controlSandwitchValve1(0);
    inline Parameter<bool> controlSandwitchValve2(0);
    inline Parameter<bool> controlSandwitchValve3(0);

    inline Parameter<bool> flowValveInlet1(0);
    inline Parameter<bool> flowValveInlet2(0);
    inline Parameter<bool> flowValveInlet3(0);

    inline Parameter<bool> flowValveOutlet1(0);
    inline Parameter<bool> flowValveOutlet2(0);
    inline Parameter<bool> flowValveOutlet3(0);

    inline Parameter<bool> flowValveTest1(0);
    inline Parameter<bool> flowValveTest2(0);

    inline Parameter<float> ledIntensity1(0);
    inline Parameter<float> ledIntensity2(0);
    inline Parameter<float> ledIntensity3(0);
    inline Parameter<float> ledIntensity4(0);

    // Photos
    inline Parameter<uint16_t> numberOfPhotosTaken(0);
    inline Parameter<float> photoExposureTime(0);
    inline Parameter<uint16_t> photoInterval(0);
    inline Parameter<uint64_t> photoCroppedResolution(0); // FIXME: is enum in database
    inline Parameter<uint32_t> photoCompressionRate(0); // FIXME: is enum in database

    // Misc
    inline Parameter<uint8_t> experimentNumber(0); // FIXME: is enum in database

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

}

#endif
