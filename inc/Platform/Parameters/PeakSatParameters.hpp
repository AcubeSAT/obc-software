#pragma once

#include "Helpers/Parameter.hpp"
#include "CAN/Driver.hpp"

namespace PeakSatParameters {
    /**
     * ID enumeration of OBDH subsystem's specific parameters.
     */
    enum ParameterID : uint16_t {
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
        OBCAvailableMRAM = 5007,
        OBCAvailableNAND = 5008,
        OBCSpacecraftTimeRef = 5009, ///< which subsystem holds the correct time
        OBCOnBoardTime = 5010,
        OBCOperationalMode = 5011,
        OBCMemoryPartition = 5012,
        OBCReconfigurationTimer = 5013, ///< timer responsible to reset the spacecraft to a known working state unless it has been
        ///< reset by a ground station pass.
        OBCLastFailedEvent = 5014,
        OBCMCUSystick = 5015,
        OBCCANBUSLoad1 = 5016,  ///< the CAN bus load is based on the used capacity (bandwidth) divided by maximum capacity
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

    /******************* OBDH ENUMS *******************/
    enum SpacecraftTimeRef : uint8_t {
        Spacecraft = 0,
        GroundStation = 1
    };

    enum OperationalMode : uint8_t {
        CommissioningMode = 0,
        NominalMode = 1,
        ScienceMode = 2,
        SafeMode = 3
    };

    enum MemoryPartition : uint8_t {
        First = 0,
        Second = 1
    };

    enum CANBUSActive : uint8_t {
        Main = 0,
        Reductant = 1
    };

    enum MCUFDIR : uint8_t {
        OBC = 0,
        ADCS = 1
    };

    /******************* COMMS ENUMS *******************/
    enum AntennaDeploymentStatus : uint8_t {
        Closed = 0,
        OneDoorOpen = 1,
        TwoDoorOpen = 2,
        ThreeDoorOpen = 3,
        FullyDeployed = 4
    };

    enum SampleRateUHFTX : uint8_t {
        Rate = 0
    };

    enum AntennaGains : uint8_t {
        Gain = 0
    };

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
    inline Parameter<uint32_t> obcAvailableMRAM(0);
    inline Parameter<uint32_t> obcAvailableNAND(0);

    inline Parameter<Time::DefaultCUC> obcOnBoardTime(Time::DefaultCUC(0));

    inline Parameter<SpacecraftTimeRef> obcSpacecraftTimeRef(Spacecraft); // enum
    inline Parameter<OperationalMode> obcOperationalMode(NominalMode); // enum
    inline Parameter<MemoryPartition> obcMemoryPartition(First); // enum

    inline Parameter<uint32_t> obcReconfigurationTimer(0);
    inline Parameter<uint16_t> obcLastFailedEvent(0);
    inline Parameter<uint32_t> obcMCUSystick(0);

    inline Parameter<float> obcCANBUSLoad1(0);
    inline Parameter<float> obcCANBUSLoad2(0);

    inline Parameter<CAN::Driver::ActiveBus> obcCANBUSActive(CAN::Driver::Main); // enum
    inline Parameter<MCUFDIR> obcMCUFDIR(OBC); // enum

    inline Parameter<uint8_t> obcMCURestartSafeModeThreshold(0);
    inline Parameter<float> obcNANDFLASHLCLThreshold(0);
    inline Parameter<float> obcMRAMLCLThreshold(0);
    inline Parameter<float> obcNANDFLASHON(0);
    inline Parameter<float> obcNANDFlashScrubbingFrequency(0);
    inline Parameter<float> obcMRAMON(0);
    inline Parameter<float> obcRAMScrubbingFrequency(0);
    inline Parameter<float> obcProgramFlashScrubbingFrequency(0);

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

    inline Parameter<AntennaDeploymentStatus> commsAntennaDeploymentStatus(Closed); // enum

    inline Parameter<SampleRateUHFTX> commsDataRateUHFTX(Rate); // enum
    inline Parameter<uint32_t> commsDataRateUHFRX(0);
    inline Parameter<uint32_t> commsSymbolRateSBand(0);
    inline Parameter<uint16_t> commsCWInterval(0);
    inline Parameter<uint16_t> commsGMSKBeaconInterval(0);
    inline Parameter<uint32_t> commsUHFBandTXPower(0);
    inline Parameter<uint32_t> commsSBandTXPower(0);
    inline Parameter<uint32_t> commsChannelNumberUHFBand(0);
    inline Parameter<uint32_t> commsChannelNumberSBand(0);

    inline Parameter<AntennaGains> commsLNAGain(Gain); // enum
    inline Parameter<AntennaGains> commsPAGainUHFBand(Gain); // enum
    inline Parameter<AntennaGains> commsPAGainSBand(Gain); // enum

    inline Parameter<uint8_t> commsVGAGain(0);
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

    inline Parameter<uint32_t> commsMCUBootCounter(0);
    inline Parameter<Time::DefaultCUC> commsOnBoardTime(Time::DefaultCUC(0));

    inline Parameter<MemoryPartition> commsNANDCurrentlyUsedMemoryPartition(First); // enum

    inline Parameter<uint16_t> commsLastFailedEvent(0);
    inline Parameter<uint32_t> commsMCUSystick(0);
    inline Parameter<uint32_t> commsFlashInt(0);
    inline Parameter<uint32_t> commsSRAMInt(0);
}