#include "AmbientTemperatureTask.hpp"

void AmbientTemperatureTask::execute() {
    if (not sensor.isDeviceConnected()) {
        LOG_ERROR << "For some reason I could not find a temperature sensor connected?";
        vTaskSuspend(taskHandle);
    }

    while (true) {
        ambientTemperature = sensor.getTemperature();

        LOG_DEBUG << "The ambient temperature is: " << ambientTemperature << " degrees Celsius";
        CommonParameters::boardTemperature1.setValue(ambientTemperature);
        vTaskDelay(pdMS_TO_TICKS(DelayMs));
    }
}
