#include "NANDTask.hpp"


void NANDTask::execute() {

    MT29F mt29f(SMC::NCS3, PIO_PIN_PA12, PIO_PIN_PA27);

    // TODO: add LCL initialization

    uint8_t failed_tries = 0;

    /* INITIALIZE & STATUS */
    while (1) {
        uint8_t status = 1;
        status = mt29f.resetNAND();
        if (status != 0) {
            LOG_DEBUG << "The status of the 1st LUN (die) is:" << status;
            vTaskDelay(DelayMs);
            break;
        } else {
            LOG_DEBUG << "Failed to reset NAND";
            vTaskDelay(DelayMs);
            failed_tries++;
            if (failed_tries > 4) {
                failed_tries = 0;
                break;
            }
        }
    }
    while (1) {
        while (1) {
            /* ID */
            while (1) {
                if (mt29f.isNANDAlive()) {
                    uint8_t id[8] = {};
                    mt29f.readNANDID(id);
                    LOG_DEBUG << "The ID of the NAND Flash is:";
                    vTaskDelay(pdMS_TO_TICKS(150));
                    for (int i = 0; i < 8; i++) {
                        LOG_DEBUG << id[i];
                        vTaskDelay(pdMS_TO_TICKS(100));
                    }
                    vTaskDelay(DelayMs);
                    break;
                } else {
                    LOG_DEBUG << "Wrong ID";
                    mt29f.resetNAND();
                    vTaskDelay(DelayMs);
                    failed_tries++;
                    if (failed_tries > 4) {
                        failed_tries = 0;
                        break;
                    }
                }
            }


            /* WRITE */
            uint8_t data_write[20] = {};
            for (uint8_t i = 0; i < 20; i++) {
                data_write[i] = i + 1;
            }

            while (1) {
                bool success = mt29f.writeNAND(0, 0, 20, data_write);
                if (success == 0) {
                    LOG_DEBUG << "Failed to write";
                    vTaskDelay(pdMS_TO_TICKS(100));
                    if (mt29f.errorHandler()) {
                        LOG_DEBUG << "NAND is alive";
                    } else {
                        LOG_DEBUG << "NAND is not responding";
                    }
                    vTaskDelay(DelayMs);
                    failed_tries++;
                    if (failed_tries > 4) {
                        failed_tries = 0;
                        break;
                    }
                } else {
                    vTaskDelay(pdMS_TO_TICKS(DelayMs));
                    break;
                }
            }


            /* READ */
            uint8_t data_read[20] = {};

            while (1) {
                bool success = mt29f.readNAND(data_read, 0, 0, 19);
                if (success) {
                    LOG_DEBUG << "Start reading after writing:";
                    vTaskDelay(pdMS_TO_TICKS(100));

                    for (uint8_t i = 0; i < 20; i++) {

                        LOG_DEBUG << data_read[i];

                        vTaskDelay(pdMS_TO_TICKS(100));
                    }
                    break;
                } else {
                    LOG_DEBUG << "Failed to read";
                    vTaskDelay(pdMS_TO_TICKS(100));
                    if (mt29f.errorHandler()) {
                        LOG_DEBUG << "NAND is alive";
                    } else {
                        LOG_DEBUG << "NAND is not responding";
                    }
                    vTaskDelay(DelayMs);
                    failed_tries++;
                    if (failed_tries > 4) {
                        failed_tries = 0;
                        break;
                    }
                }
            }

            /* ERASE */
            while (1) {
                uint8_t success = mt29f.eraseBlock(0, 0);
                if (!success) {
                    LOG_DEBUG << "Failed to erase NAND block";
                    vTaskDelay(pdMS_TO_TICKS(100));
                    failed_tries++;
                    if (failed_tries > 4) {
                        failed_tries = 0;
                        break;
                    }
                } else {
                    vTaskDelay(pdMS_TO_TICKS(DelayMs));
                    break;
                }
            }

            /* READ */
            while (1) {
                bool success = mt29f.readNAND(data_read, 0, 0, 19);
                if (success) {
                    LOG_DEBUG << "Start reading after erasing:";
                    vTaskDelay(pdMS_TO_TICKS(200));

                    for (uint8_t i = 0; i < 20; i++) {

                        LOG_DEBUG << data_read[i];

                        vTaskDelay(pdMS_TO_TICKS(100));
                    }
                    break;
                } else {
                    LOG_DEBUG << "Failed to read";
                    vTaskDelay(pdMS_TO_TICKS(100));
                    failed_tries++;
                    if (failed_tries > 4) {
                        failed_tries = 0;
                        break;
                    }
                }
            }

            vTaskDelay(DelayMs);
        }
    }
}