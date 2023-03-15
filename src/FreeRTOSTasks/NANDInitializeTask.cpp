#include "NANDInitializeTask.hpp"


void NANDInitializeTask::execute() {

    MT29F mt29f(SMC::NCS3, PIO_PIN_PA12, PIO_PIN_PA27);

    // TODO: add LCL initialization

    while(1) {
        status = mt29f.resetNAND();
        if (status != 0) {
            LOG_DEBUG << "The status of the 1st LUN (die) is: " << status;
            vTaskSuspend(NULL);
        }
        else vTaskDelay(DelayMs);
    }

}



