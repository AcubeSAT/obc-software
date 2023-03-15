#include "NANDEraseBlockTask.hpp"


void NANDEraseBlockTask::execute() {

    MT29F mt29f(SMC::NCS3, PIO_PIN_PA12, PIO_PIN_PA27);

    while (1) {

        mt29f.eraseBlock(0,0);
        vTaskDelay(pdMS_TO_TICKS(DelayMs));

    }

}



