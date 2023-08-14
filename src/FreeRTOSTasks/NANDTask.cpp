#include "NANDTask.hpp"
#include "etl/to_string.h"
#include "etl/String.hpp"
#include "etl/array.h"
//#include "LCLDefinitions.hpp"
//#include "MRAMTask.hpp"


void NANDTask::execute() {

    MT29F mt29f(SMC::NCS3, MEM_NAND_BUSY_1_PIN, MEM_NAND_WR_ENABLE_PIN);

//    LCL &nandLCL = LCLDefinitions::lclArray[LCLDefinitions::NANDFlash];

//    nandLCL.enableLCL();

    uint8_t failedTries = 0;

    /* INITIALIZE & STATUS */
    for (failedTries = 0; failedTries < 3;) {
        uint8_t status = 1;
        status = mt29f.resetNAND();
        if (status != 0) {
            LOG_DEBUG << "The status of the 1st LUN (die) is: " << status;
            break;
        } else {
            LOG_DEBUG << "Failed to reset NAND";
//            nandLCL.enableLCL();
            failedTries++;
        }
    }
    while (true) {
        /* ID */
        for (failedTries = 0; failedTries < 3;) {
            if (mt29f.isNANDAlive()) {
                etl::array<uint8_t,8> id = {};
                mt29f.readNANDID(id);
                etl::string<32> stringID = "";
                for (uint8_t i = 0; i < 8; i++) {
                    etl::to_string(id[i], stringID, true);
                    stringID.append(" ");
                }
                LOG_DEBUG << "The ID of the NAND Flash is: " << stringID.c_str();
                break;
            } else {
                LOG_DEBUG << "Wrong NAND ID";
                mt29f.resetNAND();
                failedTries++;
            }
        }


        /* WRITE */
        etl::array<uint8_t,20> dataWrite = {};
        for (uint8_t i = 0; i < 20; i++) {
            dataWrite[i] = i + 1;
        }

        uint32_t writePosition = rand() % (1105920 * 10);
        LOG_DEBUG << "Write address is: " << writePosition;
        constexpr MT29F::Structure pos{};

        for (failedTries = 0; failedTries < 3;) {
            bool success = mt29f.abstractWriteNAND<20,pos,MT29F::POS>(dataWrite);
            if (!success) {
                LOG_DEBUG << "Failed to write NAND";
                if (mt29f.errorHandler()) {
                    LOG_DEBUG << "NAND is alive";
                } else {
                    LOG_DEBUG << "NAND is not responding";
//                    nandLCL.enableLCL();
                }
                failedTries++;
            } else {
                vTaskDelay(pdMS_TO_TICKS(10));
                break;
            }
        }

//
//        /* READ */
//        etl::array<uint8_t, 20> dataRead = {};
//
//        for (failedTries = 0; failedTries < 3;) {
//            bool success = mt29f.readNAND(dataRead, 0, writePosition, 20);
//            if (success) {
//            etl::string<100> stringReadWrite = "";
//            for (uint8_t i = 0; i < 20; i++) {
//                etl::to_string(dataRead[i], stringReadWrite, true);
//                stringReadWrite.append(" ");
//            }
//
//            // check if write-read was correct
//            if (etl::equal(dataRead.begin(), dataRead.end(), dataWrite.begin())) {
//                LOG_INFO << "NAND read and write test succeeded";
//            } else {
//                LOG_INFO << "NAND read and write test failed";
//                LOG_DEBUG << "NAND read: " << stringReadWrite.c_str();
//            }
//
//            break;
//            } else {
//                LOG_ERROR << "Failed to read NAND";
//                if (mt29f.errorHandler()) {
//                    LOG_INFO << "NAND is alive";
//                } else {
//                    LOG_INFO << "NAND is not responding";
////                    nandLCL.enableLCL();
//                }
//                failedTries++;
//            }
//        }
//        /* ERASE */
//        uint8_t block = writePosition / 1105920;
//        for (failedTries = 0; failedTries < 3;) {
//            uint8_t success = mt29f.eraseBlock(0, block);
//            if (!success) {
//                LOG_ERROR << "Failed to erase NAND block";
//                failedTries++;
//            } else {
//                vTaskDelay(pdMS_TO_TICKS(10));
//                break;
//            }
//        }
//
//        etl::array<uint8_t,20> dataErase = {};
//        for (uint8_t i = 0; i < 20; i++) {
//            dataErase[i] = 255;
//        }
//
//        /* READ */
//        for (failedTries = 0; failedTries < 3;) {
//            bool success = mt29f.readNAND(dataRead, 0, writePosition, 20u);
//            if (success) {
//                etl::string<100> stringReadErase = "";
//                for (uint8_t i = 0; i < 20; i++) {
//                    etl::to_string(dataRead[i], stringReadErase, true);
//                    stringReadErase.append(" ");
//                }
//                if (etl::equal(dataRead.begin(), dataRead.end(), dataWrite.begin())) {
//                    LOG_INFO << "NAND erase test failed";
//                } else if (!etl::equal(dataRead.begin(), dataRead.end(), dataErase.begin())) {
//                    LOG_INFO << "NAND erase test failed";
//                    LOG_DEBUG << "Read NAND after erasing: " << stringReadErase.c_str();
//                } else {
//                    LOG_INFO << "NAND erase test succeeded";
//                }
//                break;
//            } else {
//                LOG_ERROR << "Failed to read NAND";
//                failedTries++;
//            }
//        }

//        vTaskResume(MRAMTask::mramTaskHandle);
//        vTaskSuspend(NULL);

        vTaskDelay(DelayMs);
    }
}
