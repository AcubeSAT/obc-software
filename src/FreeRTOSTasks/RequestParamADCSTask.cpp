#include "RequestParamADCSTask.hpp"
#include "CANGatekeeperTask.hpp"
#include "TimeKeepingTask.hpp"
#include "AcubeSATParameters.hpp"

void RequestParamADCSTask::execute() {
    CAN::Application::switchBus(CAN::Driver::Main);
    CAN::Frame frame = {CAN::NodeID};
    for (auto i = 0; i < CAN::Frame::MaxDataLength; i++) {
        frame.data.at(i) = i;
    }

    while (true) {
        using namespace AcubeSATParameters;

        /* Extra parameters*/
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSUseRTT}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSUseUART}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSUseCAN}, false);


        /* ID000 until ID012 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSXBodyFrameRegardingOrbitFrame}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSYBodyFrameRegardingOrbitFrame}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSZBodyFrameRegardingOrbitFrame}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSAngularVelocityOnX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSAngularVelocityOnY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSAngularVelocityOnZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSBDotXAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSBDotYAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSBDotZAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSQuaternionOrbitFrameToBodyScalar}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSQuaternionOrbitFrameToBodyVectorElem1}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSQuaternionOrbitFrameToBodyVectorElem2}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSQuaternionOrbitFrameToBodyVectorElem3}, false);


        /*  Contains RM3100 Magnetometer Parameters */
        /* ID013 until ID042 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerRawX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerRawY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerRawZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerFrequency}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerCycleCountX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerCycleCountY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerCycleCountZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerSelfTest}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISCalibratedXAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISCalibratedYAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISCalibratedZAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISFilteredXAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISFilteredYAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISFilteredZAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISRawXAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISRawYAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerISISRawZAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorRawTopLeft}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorRawTopRight}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorRawBottomLeft}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorRawBottomRight}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorFilteredTopLeft}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorFilteredTopRight}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorFilteredBottomLeft}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorFilteredBottomRight}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorAngularAlphaAngle}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorAngularBetaAngle}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorCalculatedX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorCalculatedY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFineSunSensorCalculatedZ}, false);


        /*  Contains ADXRS453 Gyroscope Parameters in every axis
         *  Contains ADXRS453 Gyroscope register values */
        /* ID043 until ID057 + 12 ADCS Gyro Registers*/
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroscopeRateX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroscopeRateY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroscopeRateZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroXLOCS1TRegister}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroXLOCS0TRegister}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroXHICST1Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroXHICST0Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroXQUAD1Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroXQUAD0Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroXFAULT1Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroXFAULT0Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroYLOCS1TRegister}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroYLOCS0TRegister}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroYHICST1Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroYHICST0Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroYQUAD1Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroYQUAD0Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroYFAULT1Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroYFAULT0Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroZLOCS1TRegister}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroZLOCS0TRegister}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroZHICST1Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroZHICST0Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroZQUAD1Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroZQUAD0Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroZFAULT1Register}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroZFAULT0Register}, false);


        /*  Contains Magnetorquer Parameters */
        /* ID058 until ID063 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerOnXAxisHBridgePolarity}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerOnYAxisHBridgePolarity}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerOnZAxisHBridgePolarity}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerOnXAxisOnOff}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerOnYAxisOnOff}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerOnZAxisOnOff}, false);


        /* ID064 until ID072 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainBdotXAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainBdotYAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainBdotZAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainProportionalPDXAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainProportionalPDYAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainProportionalPDZAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainDerivativePDXAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainDerivativePDYAxis}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGainDerivativePDZAxis}, false);


        /* ID073 until ID079  +2 ADCS Gyroscope temperature */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSiMQTBoardCoilXTemperatureSensor}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSiMQTBoardCoilYTemperatureSensor}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSiMQTBoardCoilZTemperatureSensor}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSiMQTBoardExtraTemperatureSensor}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroscopeXTemperature}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroscopeYTemperature}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroscopeZTemperature}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSBoardTemperature1}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSBoardTemperature2}, false);


        /* ID080 until ID095 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMode}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTLE}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSInitialKalmanQuaternionECIFrameToBodyScalar}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSInitialKalmanQuaternionECIFrameToBodyVectorElem1}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSInitialKalmanQuaternionECIFrameToBodyVectorElem2}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSInitialKalmanQuaternionECIFrameToBodyVectorElem3}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTLEOrbitalElementsArgumentPerigee}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTLEOrbitalElementsRAAN}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTLEOrbitalElementsInclination}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTLEOrbitalElementsEccentricity}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTLEOrbitalElementsMeanAnomaly}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSGP4OrbitalElementsArgumentPerigee}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSGP4OrbitalElementsRAAN}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSGP4OrbitalElementsInclination}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSGP4OrbitalElementsMeanAnomaly}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTimeGST_JD}, false);


        /* ID096 until ID114 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ1}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ2}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ3}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ4}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ5}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ6}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ7}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ8}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ9}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesQ10}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR1}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR2}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR3}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR4}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR5}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR6}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR7}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR8}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesR9}, false);



        /* ID115 until ID124 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial1}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial2}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial3}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial4}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial5}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial6}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial7}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial8}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial9}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDeterminationInitialMatricesPInitial10}, false);


        /* ID131, ID155, ID156 mistake*/

        /* ID125 until ID173 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSReactionWheelOn}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSReactionWheelAngularVelocity}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerAxisAssignment}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSControlProfileSwitching}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTransformationAxisXAssignment}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTransformationAxisYAssignment}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSTransformationAxisZAssignment}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerAxisAssignment}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSunSensorAxisAssignment}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroscopeAxisAssignment}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignECIToECEF_X}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignECIToECEF_Y}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignECIToECEF_Z}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignECIToOrbit_X}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignECIToOrbit_Y}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignECIToOrbit_Z}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignNEDToECEF_X}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignNEDToECEF_Y}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFrameAxisSignNEDToECEF_Z}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerSignX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerSignY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetometerSignZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSunSensorXAxisSign}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSunSensorYAxisSign}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSunSensorZAxisSign}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroSignX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroSignY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroSignZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDetumblingNominalThresholds}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSNominalDetumblingThresholds}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSStandByDetumblingThresholds}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDetumblingStandByThresholds}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSNominalStandByThresholds}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerMagneticDipoleX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerMagneticDipoleY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerMagneticDipoleZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerDutyCycle}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerCurrentX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerCurrentY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerCurrentZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerBDot}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSReactionWheelTorque}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSReactionWheelAngularAcceleration}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDesiredQuaternionOrbitToBodyScalar}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDesiredQuaternionVectorElem1}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDesiredQuaternionVectorElem2}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDesiredQuaternionVectorElem3}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSAngularVelocityDesiredX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSAngularVelocityDesiredY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSAngularVelocityDesiredZ}, false);



        /* ID174 until ID176 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroBiasX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroBiasY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSGyroBiasZ}, false);


        /* ID177 until ID202 */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatellitePositionLatitude}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatellitePositionLongitude}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatellitePositionHeight}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatellitePositionECIX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatellitePositionECIY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatellitePositionECIZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatelliteLinearVelocityECIX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatelliteLinearVelocityECIY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSatelliteLinearVelocityECIZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagneticFieldNEDX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagneticFieldNEDY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagneticFieldNEDZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagneticFieldECIX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagneticFieldECIY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagneticFieldECIZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSunPositionECIX}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSunPositionECIY}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSunPositionECIZ}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSEclipse}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDesaturationPecentageParameter}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSISISMTQModes}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMagnetorquerActuationMethod}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDutyCycleDetermination}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDutyCycleControl}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDutyCycleOther}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSDesatInitialAngularVelocityParam}, false);


        /* Extra */
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMCUTemperature}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMCUInputVoltage}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSBootCounter}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSOnBoardTime}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSMemoryPartition}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSLastFailedEvent}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSystick}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSRAMScrubbingFrequency}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSProgramFlashScrubbingFrequency}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSFLASHInt}, false);
        CAN::Application::createRequestParametersMessage(CAN::NodeIDs::ADCS, false,{ADCSSRAMInt}, false);




        canGatekeeperTask->send(frame);

        vTaskDelay(pdMS_TO_TICKS(2500));
    }

}

