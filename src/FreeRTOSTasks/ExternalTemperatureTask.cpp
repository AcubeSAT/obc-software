#include "FreeRTOSTasks/ExternalTemperatureTask.hpp"

void ExternalTemperatureTask::execute() {
    while (true) {
        externalTemperature = sensor.getTemperature();

        LOG_DEBUG << "The ambient temperature is: " << externalTemperature << " degrees Celsius";
        PlatformParameters::externalTemperature.setValue(externalTemperature);
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}