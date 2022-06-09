#include "FreeRTOSTasks/AmbientTemperatureTask.hpp"

void AmbientTemperatureTask::execute() {
    while (true) {
        ambientTemperature = sensor.getTemperature();

        LOG_DEBUG << "The ambient temperature is: " << ambientTemperature << " degrees Celsius";
        PlatformParameters::ambientTemperature.setValue(ambientTemperature);
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}
