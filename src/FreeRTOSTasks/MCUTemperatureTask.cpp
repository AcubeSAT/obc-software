#include "MCUTemperatureTask.hpp"

void MCUTemperatureTask::execute() {
    AFEC0_ConversionStart();
    while (true) {
        AFEC0_ConversionStart();
        vTaskDelay(pdMS_TO_TICKS(1));
        uint16_t ADCconversion = AFEC0_ChannelResultGet(AFEC_CH11);
        float voltageConversion = static_cast<float>(ADCconversion) * PositiveVoltageReference / MaxADCValue;
        const float MCUtemperature =
                (voltageConversion - TypicalVoltageAt25) / TemperatureSensitivity + ReferenceTemperature;
        LOG_DEBUG << "The temperature of the MCU is: " << MCUtemperature << " degrees Celsius";
        CommonParameters::mcuTemperature.setValue(MCUtemperature);
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}
