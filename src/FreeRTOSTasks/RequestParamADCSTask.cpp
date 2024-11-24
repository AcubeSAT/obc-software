#include "RequestParamADCSTask.hpp"
#include "CANGatekeeperTask.hpp"
#include "TimeKeepingTask.hpp"
#include "AcubeSATParameters.hpp"

void RequestParamADCSTask::execute() {

    while (true) {

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSUseRTT,
            ADCSUseUART,
            ADCSUseCAN,
            ADCSXBodyFrameRegardingOrbitFrame,
            ADCSYBodyFrameRegardingOrbitFrame,
            ADCSZBodyFrameRegardingOrbitFrame,
            ADCSAngularVelocityOnX,
            ADCSAngularVelocityOnY,
            ADCSAngularVelocityOnZ,
            ADCSBDotXAxis}, false);

        CAN::TPMessage message = {};
        CAN::Application::parseSendParametersMessage(message);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSBDotYAxis,
                ADCSBDotZAxis,
                ADCSQuaternionOrbitFrameToBodyScalar,
                ADCSQuaternionOrbitFrameToBodyVectorElem1,
                ADCSQuaternionOrbitFrameToBodyVectorElem2,
                ADCSQuaternionOrbitFrameToBodyVectorElem3,
                ADCSMagnetometerRawX,
                ADCSMagnetometerRawY,
                ADCSMagnetometerRawZ,
                ADCSMagnetometerFrequency}, false);

        CAN::TPMessage message1 = {};
        CAN::Application::parseSendParametersMessage(message1);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerCycleCountX,
            ADCSMagnetometerCycleCountY,
            ADCSMagnetometerCycleCountZ,
            ADCSMagnetometerSelfTest,
            ADCSMagnetometerISISCalibratedXAxis,
            ADCSMagnetometerISISCalibratedYAxis,
            ADCSMagnetometerISISCalibratedZAxis,
            ADCSMagnetometerISISFilteredXAxis,
            ADCSMagnetometerISISFilteredYAxis,
            ADCSMagnetometerISISFilteredZAxis}, false);

        CAN::TPMessage message2 = {};
        CAN::Application::parseSendParametersMessage(message2);


        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISRawXAxis,
            ADCSMagnetometerISISRawYAxis,
            ADCSMagnetometerISISRawZAxis,
            ADCSFineSunSensorRawTopLeft,
            ADCSFineSunSensorRawTopRight,
            ADCSFineSunSensorRawBottomLeft,
            ADCSFineSunSensorRawBottomRight,
            ADCSFineSunSensorFilteredTopLeft,
            ADCSFineSunSensorFilteredTopRight,
            ADCSFineSunSensorFilteredBottomLeft}, false);

        CAN::TPMessage message3 = {};
        CAN::Application::parseSendParametersMessage(message3);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorFilteredBottomRight,
            ADCSFineSunSensorAngularAlphaAngle,
            ADCSFineSunSensorAngularBetaAngle,
            ADCSFineSunSensorCalculatedX,
            ADCSFineSunSensorCalculatedY,
            ADCSFineSunSensorCalculatedZ,
            ADCSGyroscopeRateX,
            ADCSGyroscopeRateY,
            ADCSGyroscopeRateZ,
            ADCSGyroXLOCS1TRegister}, false);

        CAN::TPMessage message25 = {};
        CAN::Application::parseSendParametersMessage(message25);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroXLOCS0TRegister,
            ADCSGyroXHICST1Register,
            ADCSGyroXHICST0Register,
            ADCSGyroXQUAD1Register,
            ADCSGyroXQUAD0Register,
            ADCSGyroXFAULT1Register,
            ADCSGyroXFAULT0Register,
            ADCSGyroYLOCS1TRegister,
            ADCSGyroYLOCS0TRegister,
            ADCSGyroYHICST1Register}, false);

        CAN::TPMessage message4 = {};
        CAN::Application::parseSendParametersMessage(message4);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroYHICST0Register,
            ADCSGyroYQUAD1Register,
            ADCSGyroYQUAD0Register,
            ADCSGyroYFAULT1Register,
            ADCSGyroYFAULT0Register,
            ADCSGyroZLOCS1TRegister,
            ADCSGyroZLOCS0TRegister,
            ADCSGyroZHICST1Register,
            ADCSGyroZHICST0Register,
            ADCSGyroZQUAD1Register}, false);

        CAN::TPMessage message5 = {};
        CAN::Application::parseSendParametersMessage(message5);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroZQUAD0Register,
            ADCSGyroZFAULT1Register,
            ADCSGyroZFAULT0Register,
            ADCSMagnetorquerOnXAxisHBridgePolarity,
            ADCSMagnetorquerOnYAxisHBridgePolarity,
            ADCSMagnetorquerOnZAxisHBridgePolarity,
            ADCSMagnetorquerOnXAxisOnOff,
            ADCSMagnetorquerOnYAxisOnOff,
            ADCSMagnetorquerOnZAxisOnOff,
            ADCSGainBdotXAxis}, false);

        CAN::TPMessage message6 = {};
        CAN::Application::parseSendParametersMessage(message6);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainBdotYAxis,
            ADCSGainBdotZAxis,
            ADCSGainProportionalPDXAxis,
            ADCSGainProportionalPDYAxis,
            ADCSGainProportionalPDZAxis,
            ADCSGainDerivativePDXAxis,
            ADCSGainDerivativePDYAxis,
            ADCSGainDerivativePDZAxis,
            ADCSiMQTBoardCoilXTemperatureSensor,
            ADCSiMQTBoardCoilYTemperatureSensor}, false);

        CAN::TPMessage message7 = {};
        CAN::Application::parseSendParametersMessage(message7);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSiMQTBoardCoilZTemperatureSensor,
            ADCSiMQTBoardExtraTemperatureSensor,
            ADCSGyroscopeXTemperature,
            ADCSGyroscopeYTemperature,
            ADCSGyroscopeZTemperature,
            ADCSBoardTemperature1,
            ADCSBoardTemperature2,
            ADCSMode,
            ADCSTLE,
            ADCSInitialKalmanQuaternionECIFrameToBodyScalar}, false);

        CAN::TPMessage message8 = {};
        CAN::Application::parseSendParametersMessage(message8);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSInitialKalmanQuaternionECIFrameToBodyVectorElem1,
            ADCSInitialKalmanQuaternionECIFrameToBodyVectorElem2,
            ADCSInitialKalmanQuaternionECIFrameToBodyVectorElem3,
            ADCSTLEOrbitalElementsArgumentPerigee,
            ADCSTLEOrbitalElementsRAAN,
            ADCSTLEOrbitalElementsInclination,
            ADCSTLEOrbitalElementsEccentricity,
            ADCSTLEOrbitalElementsMeanAnomaly,
            ADCSSGP4OrbitalElementsArgumentPerigee,
            ADCSSGP4OrbitalElementsRAAN}, false);

        CAN::TPMessage message9 = {};
        CAN::Application::parseSendParametersMessage(message9);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSGP4OrbitalElementsInclination,
            ADCSSGP4OrbitalElementsMeanAnomaly,
            ADCSTimeGST_JD,
            ADCSDeterminationInitialMatricesQ1,
            ADCSDeterminationInitialMatricesQ2,
            ADCSDeterminationInitialMatricesQ3,
            ADCSDeterminationInitialMatricesQ4,
            ADCSDeterminationInitialMatricesQ5,
            ADCSDeterminationInitialMatricesQ6,
            ADCSDeterminationInitialMatricesQ7}, false);

        CAN::TPMessage message10 = {};
        CAN::Application::parseSendParametersMessage(message10);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ8,
            ADCSDeterminationInitialMatricesQ9,
            ADCSDeterminationInitialMatricesQ10,
            ADCSDeterminationInitialMatricesR1,
            ADCSDeterminationInitialMatricesR2,
            ADCSDeterminationInitialMatricesR3,
            ADCSDeterminationInitialMatricesR4,
            ADCSDeterminationInitialMatricesR5,
            ADCSDeterminationInitialMatricesR6,
            ADCSDeterminationInitialMatricesR7}, false);

        CAN::TPMessage message11 = {};
        CAN::Application::parseSendParametersMessage(message11);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR8,
            ADCSDeterminationInitialMatricesR9,
            ADCSDeterminationInitialMatricesPInitial1,
            ADCSDeterminationInitialMatricesPInitial2,
            ADCSDeterminationInitialMatricesPInitial3,
            ADCSDeterminationInitialMatricesPInitial4,
            ADCSDeterminationInitialMatricesPInitial5,
            ADCSDeterminationInitialMatricesPInitial6,
            ADCSDeterminationInitialMatricesPInitial7,
            ADCSDeterminationInitialMatricesPInitial8}, false);

        CAN::TPMessage message12 = {};
        CAN::Application::parseSendParametersMessage(message12);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial9,
            ADCSDeterminationInitialMatricesPInitial10,
            ADCSReactionWheelOn,
            ADCSReactionWheelAngularVelocity,
            ADCSMagnetorquerAxisAssignment,
            ADCSControlProfileSwitching,
            ADCSTransformationAxisXAssignment,
            ADCSTransformationAxisYAssignment,
            ADCSTransformationAxisZAssignment,
            ADCSMagnetometerAxisAssignment}, false);

        CAN::TPMessage message13 = {};
        CAN::Application::parseSendParametersMessage(message13);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSunSensorAxisAssignment,
            ADCSGyroscopeAxisAssignment,
            ADCSFrameAxisSignECIToECEF_X,
            ADCSFrameAxisSignECIToECEF_Y,
            ADCSFrameAxisSignECIToECEF_Z,
            ADCSFrameAxisSignECIToOrbit_X,
            ADCSFrameAxisSignECIToOrbit_Y,
            ADCSFrameAxisSignECIToOrbit_Z,
            ADCSFrameAxisSignNEDToECEF_X,
            ADCSFrameAxisSignNEDToECEF_Y}, false);

        CAN::TPMessage message14 = {};
        CAN::Application::parseSendParametersMessage(message14);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignNEDToECEF_Z,
            ADCSMagnetometerSignX,
            ADCSMagnetometerSignY,
            ADCSMagnetometerSignZ,
            ADCSSunSensorXAxisSign,
            ADCSSunSensorYAxisSign,
            ADCSSunSensorZAxisSign,
            ADCSGyroSignX,
            ADCSGyroSignY,
            ADCSGyroSignZ}, false);

        CAN::TPMessage message15 = {};
        CAN::Application::parseSendParametersMessage(message15);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDetumblingNominalThresholds,
            ADCSNominalDetumblingThresholds,
            ADCSStandByDetumblingThresholds,
            ADCSDetumblingStandByThresholds,
            ADCSNominalStandByThresholds,
            ADCSMagnetorquerMagneticDipoleX,
            ADCSMagnetorquerMagneticDipoleY,
            ADCSMagnetorquerMagneticDipoleZ ,
            ADCSMagnetorquerDutyCycle,
            ADCSMagnetorquerCurrentX}, false);

        CAN::TPMessage message16 = {};
        CAN::Application::parseSendParametersMessage(message16);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerCurrentY,
            ADCSMagnetorquerCurrentZ,
            ADCSMagnetorquerBDot,
            ADCSReactionWheelTorque,
            ADCSReactionWheelAngularAcceleration,
            ADCSDesiredQuaternionOrbitToBodyScalar,
            ADCSDesiredQuaternionVectorElem1,
            ADCSDesiredQuaternionVectorElem2,
            ADCSDesiredQuaternionVectorElem3,
            ADCSAngularVelocityDesiredX}, false);

        CAN::TPMessage message17 = {};
        CAN::Application::parseSendParametersMessage(message17);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSAngularVelocityDesiredY,
            ADCSAngularVelocityDesiredZ,
            ADCSGyroBiasX,
            ADCSGyroBiasY,
            ADCSGyroBiasZ,
            ADCSSatellitePositionLatitude,
            ADCSSatellitePositionLongitude,
            ADCSSatellitePositionHeight,
            ADCSSatellitePositionECIX,
            ADCSSatellitePositionECIY}, false);

        CAN::TPMessage message18 = {};
        CAN::Application::parseSendParametersMessage(message18);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatellitePositionECIZ,
            ADCSSatelliteLinearVelocityECIX,
            ADCSSatelliteLinearVelocityECIY,
            ADCSSatelliteLinearVelocityECIZ,
            ADCSMagneticFieldNEDX,
            ADCSMagneticFieldNEDY,
            ADCSMagneticFieldNEDZ,
            ADCSMagneticFieldECIX,
            ADCSMagneticFieldECIY,
            ADCSMagneticFieldECIZ}, false);

        CAN::TPMessage message19 = {};
        CAN::Application::parseSendParametersMessage(message19);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSunPositionECIX,
            ADCSSunPositionECIY,
            ADCSSunPositionECIZ,
            ADCSEclipse,
            ADCSDesaturationPecentageParameter,
            ADCSISISMTQModes,
            ADCSMagnetorquerActuationMethod,
            ADCSDutyCycleDetermination,
            ADCSDutyCycleControl,
            ADCSDutyCycleOther}, false);

        CAN::TPMessage message20 = {};
        CAN::Application::parseSendParametersMessage(message20);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDesatInitialAngularVelocityParam,
            ADCSMCUTemperature,
            ADCSMCUInputVoltage,
            ADCSBootCounter,
            ADCSMemoryPartition,
            ADCSLastFailedEvent,
            ADCSSystick,
            ADCSRAMScrubbingFrequency,
            ADCSProgramFlashScrubbingFrequency,
            ADCSFLASHInt}, false);

        CAN::TPMessage message21 = {};
        CAN::Application::parseSendParametersMessage(message21);

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSRAMInt}, false);

        CAN::TPMessage message22 = {};
        CAN::Application::parseSendParametersMessage(message22);

        vTaskDelay(pdMS_TO_TICKS(DelayMs));
    }

}

