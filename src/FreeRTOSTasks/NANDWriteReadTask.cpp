#include "NANDWriteReadTask.hpp"


void NANDWriteReadTask::execute() {

    MT29F mt29f(SMC::NCS3, PIO_PIN_PA12, PIO_PIN_PA27);
    while (1) {

        /* WRITE */
        uint8_t *data_write = {};
        for (int i = 0; i < 20; i++) {
            data_write[i] = i + 1;
        }

        while (1) {
            bool success = mt29f.writeNAND(0, 0, data_write);
            if (success == 0) {
                mt29f.resetNAND();
                vTaskDelay(pdMS_TO_TICKS(10));
            } else break;
        }


        /* READ */
        uint8_t *data_read = 0;

        while (1) {
            bool success = mt29f.readNAND(data_read, 0, 0, 19);
            if (success) {
                LOG_DEBUG << "start";
                vTaskDelay(pdMS_TO_TICKS(100));

                for (int i = 0; i < 20; i++) {

                    LOG_DEBUG << data_read[i];

                    vTaskDelay(pdMS_TO_TICKS(100));
                }
                break;
            } else {
                mt29f.resetNAND();
                vTaskDelay(pdMS_TO_TICKS(10));
            }
        }
    }

}



