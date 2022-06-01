#include "FreeRTOSTasks/RM3100Task.hpp"

void RM3100TASK::execute() {

    RM3100 rm3100(RM3100Mode, RM3100CMM, RM3100CycleCount, PIO_PIN_PB2, PIO_PIN_PB3);
    rm3100.checkREVID();

    while (true) {
        rm3100.readMeasurements();

        SYSTICK_DelayMs(100);
    }
}

void RM3100TASK::printData(RM3100 rm3100) {
    etl::string<80> Data = "";
    Data += "x=";
    etl::to_string(rm3100.getX() / rm3100.getGain(), Data, etl::format_spec().precision(6), true);
    Data += " y=";
    etl::to_string(rm3100.getY() / rm3100.getGain(), Data, etl::format_spec().precision(6), true);
    Data += " z=";
    etl::to_string(rm3100.getZ() / rm3100.getGain(), Data, etl::format_spec().precision(6), true);
    Data += " magneticField=";
    etl::to_string(rm3100.getMagneticFieldNorm(), Data, etl::format_spec().precision(9), true);
    Data += "\r\n";

    LOG_DEBUG << Data.data();
}