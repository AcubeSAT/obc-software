#include "RequestParamADCSTask.hpp"

#include <interrupts.h>

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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));


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
        vTaskDelay(pdMS_TO_TICKS(10));

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

        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{   ADCSSRAMInt}, false);

        vTaskDelay(pdMS_TO_TICKS(DelayMs));
    }

}

