#include "FreeRTOSTasks/TemperatureTask.hpp"

void TemperatureTask::execute() {
    AFEC0_ConversionStart();
    while (true) {
        if (AFEC0_ChannelResultGet(AFEC_CH11)) {
            uint16_t ADCconversion = AFEC0_ChannelResultGet(AFEC_CH11);
            uint16_t DACconversion = ADCconversion * PositiveVoltageReference / MaxNumberOfADC;
            float MCUtemperature =
                    (DACconversion - TypicalVoltageAt25) / TemperatureSensitivity + ReferenceTemperature;
            LOG_DEBUG << "The temperature of the MCU is: " << MCUtemperature;
            PlatformParameters::mcuTemperature.setValue(MCUtemperature);

            AFEC0_ConversionStart();
            vTaskDelay(pdMS_TO_TICKS(delayMs));
        }
    }
}