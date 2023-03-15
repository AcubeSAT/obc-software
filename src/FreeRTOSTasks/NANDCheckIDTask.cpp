#include "NANDCheckIDTask.hpp"


void NANDCheckIDTask::execute() {

    MT29F mt29f(SMC::NCS3, PIO_PIN_PA12, PIO_PIN_PA27);

    while (1) {
        if(mt29f.isNANDAlive()) {
            uint8_t id[8] = {};
            mt29f.readNANDID(id);
            LOG_DEBUG << "The ID of the NAND Flash is: ";
            vTaskDelay(pdMS_TO_TICKS(500));
            for (int i = 0; i < 8; i++) {
                LOG_DEBUG << id[i];
                vTaskDelay(pdMS_TO_TICKS(300));
            }
        }
        else{
            LOG_DEBUG << "Wrong ID";
            mt29f.resetNAND();
        }
        vTaskDelay(DelayMs);
    }
}