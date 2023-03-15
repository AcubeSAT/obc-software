#include "NANDEraseBlockTask.hpp"


void NANDEraseBlockTask::execute() {

    MT29F mt29f(SMC::NCS3, PIO_PIN_PA12, PIO_PIN_PA27);

    while (1) {
        while(1) {
            uint8_t success = mt29f.eraseBlock(0, 0);
            if (!success) {
                LOG_DEBUG << "Failed to erase NAND block";
                vTaskDelay(pdMS_TO_TICKS(100));

            }
            else break;
        }

        vTaskDelay(pdMS_TO_TICKS(10));

        /* READ */
        uint8_t data_read[20] = {};

        while (1) {
            bool success = mt29f.readNAND(data_read, 0, 0, 19);
            if (success) {
                LOG_DEBUG << "start";
                vTaskDelay(pdMS_TO_TICKS(100));

                for (uint8_t i = 0; i < 20; i++) {

                    LOG_DEBUG << data_read[i];

                    vTaskDelay(pdMS_TO_TICKS(100));
                }
                break;
            } else {
                LOG_DEBUG << "Failed to read";
                vTaskDelay(pdMS_TO_TICKS(100));
            }
        }
        vTaskDelay(DelayMs);
    }

}



