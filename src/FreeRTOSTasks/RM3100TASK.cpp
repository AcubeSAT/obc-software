#include "FreeRTOSTasks/RM3100Task.hpp"

void RM3100Task::execute() {
    RM3100 rm3100(ContinuousMeasurementMode, RM3100CycleCount, PIO_PIN_PB2, PIO_PIN_PB3);
    rm3100.getREVID();

    while (true) {
        rm3100.readMeasurements();
        printData(rm3100);
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}

void RM3100Task::printData(RM3100 rm3100) {
    etl::string<80> log = "";
    log += "x=";
    etl::to_string(rm3100.getX() / rm3100.getGain(), log, etl::format_spec().precision(6), true);
    log += " y=";
    etl::to_string(rm3100.getY() / rm3100.getGain(), log, etl::format_spec().precision(6), true);
    log += " z=";
    etl::to_string(rm3100.getZ() / rm3100.getGain(), log, etl::format_spec().precision(6), true);
    log += " magneticField=";
    etl::to_string(rm3100.getMagneticFieldNorm(), log, etl::format_spec().precision(9), true);

    LOG_DEBUG << log.data();
}