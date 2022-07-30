#include "AmbientTemperatureTask.hpp"

void AmbientTemperatureTask::execute() {
    while (true) {
        ambientTemperature = sensor.getTemperature();

        LOG_DEBUG << "The ambient temperature is: " << ambientTemperature << " degrees Celsius";
        PlatformParameters::obcBoardTemperature1.setValue(ambientTemperature);
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}
