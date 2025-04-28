#include "NANDTask.hpp"
#include "NANDTestData.hpp"
#include <etl/to_string.h>
#include <etl/String.hpp>
#include "LCLDefinitions.hpp"
#include "mutex_Handler.h"

static uint32_t seed = 123456789;

uint32_t random_address() {
    const uint32_t a = 1664525; // Multiplier
    const uint32_t c = 1013904223; // Increment
    const uint32_t m = 0xFFFFFFFF; // Modulus (2^32 for a 32-bit integer)

    seed = (a * seed + c) & m;
    return seed;
}

void printError(MT29F_Errno error) {
    switch (error) {
        case MT29F_Errno::TIMEOUT:
            LOG_DEBUG << "TIMEOUT";
            break;
        case MT29F_Errno::ADDRESS_OUT_OF_BOUNDS:
            LOG_DEBUG << "ADDRESS OUT OF BOUNDS";
            break;
        case MT29F_Errno::BUSY_IO:
            LOG_DEBUG << "MODULE BUSY (I/O)";
            break;
        case MT29F_Errno::BUSY_ARRAY:
            LOG_DEBUG << "MODULE BUSY (ARRAY)";
            break;
        case MT29F_Errno::FAIL_PREVIOUS:
            LOG_DEBUG << "PREVIOUS OPERATION FAILED";
            break;
        case MT29F_Errno::FAIL_RECENT:
            LOG_DEBUG << "RECENT OPERATION FAILED";
            break;
        case MT29F_Errno::NOT_READY:
            LOG_DEBUG << "MODULE NOT READY";
            break;
        default:
            LOG_DEBUG << "UNKNOWN ERROR";
            break;
    }
}

bool singleByteRWTest(MT29F nand_module) {
//    LOG_DEBUG<<"NAND Single byte R/W test";
    uint8_t data = 0x23;
    uint8_t read_data = 0;
    uint32_t address_pos = random_address();
    LOG_DEBUG << "Writing to: " << address_pos;
    MT29F_Errno error = nand_module.writeNAND(0, address_pos, data);
    if (error != MT29F_Errno::NONE) {
        printError(error);
        return false;
    }
    //LOG_DEBUG<<"Reading from the same address";
    error = nand_module.readNAND(0, address_pos, read_data);
    if (error != MT29F_Errno::NONE) {
        printError(error);
        return false;
    }
    if (data != read_data) {
        //LOG_DEBUG<<"Read unexpected data: "<<data;
        return false;
    }
    return true;
}

void scanNANDmodule(MT29F nand_module, uint32_t start_address) {
    uint32_t end_address = start_address + 200;
    etl::span<uint8_t> data_span(nand_test_data.data(), nand_test_data.size());

    uint errors = 0;
    uint module_errors = 0;

    MT29F_Errno error = nand_module.writeNAND(0, start_address, data_span);
    if (error != MT29F_Errno::NONE) {
        module_errors++;
        //printError(error);
    }

    etl::array<uint8_t, 200> read_data{};
    etl::span<uint8_t> data_span_read(read_data.data(), read_data.size());


    error = nand_module.readNAND(0, start_address, data_span_read);

    if (error != MT29F_Errno::NONE) {
        module_errors++;
        //printError(error);
    }

    for (int i = 0; i < 200; i++) {
        if (data_span_read[i] != data_span[i]) {
            errors++;
        }
    }

    LOG_DEBUG << "Mismatch errors occurred: " << errors;
    LOG_DEBUG << "HW R/W errors occurred: " << module_errors;
}

bool singlePageRWTest(MT29F nand_module) {
    //LOG_DEBUG<<"NAND 200 byte R/W test (single page)";
    uint8_t selected_page = (uint8_t) random_address() % 128;
    uint16_t selected_block = (uint16_t) random_address() %
                              4095; // One block before end to avoid checking if the selected page is the last available
    uint32_t address_pos = (8640 * selected_page) + (1105920 * selected_block) + 10;
    // Address position is 10 bytes after the start of the page so 200 bytes of data
    // will fit in a single page

    LOG_DEBUG << "Testing block: " << selected_block;
    LOG_DEBUG << "Testing page: " << selected_page;
    etl::span<uint8_t> data_span(nand_test_data.data(), nand_test_data.size());
    MT29F_Errno error = nand_module.writeNAND((uint8_t) 0, address_pos, data_span);
    if (error != MT29F_Errno::NONE) {
        printError(error);
        return false;
    }

    etl::array<uint8_t, 200> read_data{};
    etl::span<uint8_t> data_span_read(read_data.data(), read_data.size());
    // LOG_DEBUG<<"Reading from: "<<address_pos;
    error = nand_module.readNAND(0, address_pos, data_span_read);
    if (error != MT29F_Errno::NONE) {
        printError(error);
        return false;
    }
    uint errors = 0;
    for (int i = 0; i < 200; i++) {
        if (data_span_read[i] != data_span[i]) {
            errors++;
        }
    }
    LOG_DEBUG << "Mismatch errors occurred: " << errors;
    if (errors != 0) {
        return false;
    }

    return true;
}

bool crossPageRWTest(MT29F nand_module) {
    //LOG_DEBUG<<"NAND 200 byte R/W test (cross page)";
    // Page = 8640 bytes
    uint8_t selected_page =
            ((uint8_t) random_address() % 127) + 1; // // One page after begin to avoid checking for cross block
    uint16_t selected_block = (uint16_t) random_address() % 4096;
    uint32_t address_pos = (8640 * selected_page) + (1105920 * selected_block) - 50;
    // Address position is 50 bytes before the end of the page so 200 bytes of data
    // won't fit in a single page

    LOG_DEBUG << "Testing block: " << selected_block;
    LOG_DEBUG << "Testing pages: " << selected_page - 1 << ", " << selected_page;
    etl::span<uint8_t> data_span(nand_test_data.data(), nand_test_data.size());
    MT29F_Errno error = nand_module.writeNAND((uint8_t) 0, address_pos, data_span);
    if (error != MT29F_Errno::NONE) {
        printError(error);
        return false;
    }
    uint8_t data_s, data_e;
    error = nand_module.readNAND(0, address_pos, data_s);
    if (error != MT29F_Errno::NONE) {
        printError(error);
        return false;
    }
    error = nand_module.readNAND(0, (address_pos + nand_test_data.size() - 1), data_e);
    if (error != MT29F_Errno::NONE) {
        printError(error);
        return false;
    }
    if ((data_s != nand_test_data[0]) || (data_e != nand_test_data[nand_test_data.size() - 1])) {
        LOG_DEBUG << "Write confirm operation failed";
        LOG_DEBUG << "First read byte: " << data_s;
        LOG_DEBUG << "Last read byte: " << data_e;
        return false;
    }

    etl::array<uint8_t, 200> read_data;
    etl::span<uint8_t> data_span_read(read_data.data(), read_data.size());
    // LOG_DEBUG<<"Reading from: "<<address_pos;
    error = nand_module.readNAND(0, address_pos, data_span_read);
    if (error != MT29F_Errno::NONE) {
        printError(error);
        return false;
    }
    uint errors = 0;
    for (int i = 0; i < 200; i++) {
        if (data_span_read[i] != data_span[i]) {
            errors++;
        }
    }
    LOG_DEBUG << "Mismatch errors occurred: " << errors;
    if (errors != 0) {
        return false;
    }

    return true;
}

bool blockEraseTest(MT29F nand_module) {
    // LOG_DEBUG<<"NAND Block Erase test";
    // Block = PageSize*128
    uint16_t selected_block = random_address() %
                              4095; // One block before end to avoid checking if the selected page is the last available
    uint32_t block_start_address = 1105920 * selected_block;
    uint32_t next_block_start_address = 1105920 * (selected_block + 1);
    // Write to 10 addresses inside the selected block, then erase the block and check if the data is erased

    LOG_DEBUG << "Testing block: " << selected_block;
    uint32_t addresses[10];
    uint8_t data = 'A';
    for (uint8_t i = 0; i < 10; i++) {
        addresses[i] =
                (block_start_address) + (random_address() % (next_block_start_address - block_start_address + 1));
        if (addresses[i] > 4529848319) {
            addresses[i] = addresses[i] & 0x00000000ffffffff;
        }
        MT29F_Errno error = nand_module.writeNAND(0, addresses[i], data);
        if (error != MT29F_Errno::NONE) {
            printError(error);
            return false;
        }
    }
    MT29F_Errno error = nand_module.eraseBlock(0, selected_block);
    if (error != MT29F_Errno::NONE) {
        printError(error);
        return false;
    }
    for (uint8_t i = 0; i < 10; i++) {
        error = nand_module.readNAND(0, addresses[i], data);
        if (error != MT29F_Errno::NONE) {
            printError(error);
            return false;
        }
        if (data == 'A') {
            LOG_DEBUG << "Error on address: " << addresses[i];
            return false;
        }
    }
    return true;
}

uint32_t start = 100000;
bool flag = false;

void testNANDmodule(MT29F nand_module) {
//    scanNANDmodule(nand_module, start);
//    if(flag){
//        start+=200;
//    }
//    flag=!flag;

    if (!singleByteRWTest(nand_module)) {
        LOG_DEBUG << "NAND Single byte RW test FAILED";
    } else {
        LOG_DEBUG << "NAND Single byte RW test SUCCEDED";
    }

    if (!singlePageRWTest(nand_module)) {
        LOG_DEBUG << "NAND 500 byte RW (single page) test FAILED";
    } else {
        LOG_DEBUG << "NAND 500 byte RW (single page) test SUCCEDED";
    }

    if (!crossPageRWTest(nand_module)) {
        LOG_DEBUG << "NAND 500 byte RW (cross page) test FAILED";
    } else {
        LOG_DEBUG << "NAND 500 byte RW (cross page) test SUCCEDED";
    }

    if (!blockEraseTest(nand_module)) {
        LOG_DEBUG << "NAND Block Erase test FAILED";
    } else {
        LOG_DEBUG << "NAND Block Erase test SUCCEDED";
    }

}

void NANDTask::execute() {

    MT29F mt29f(SMC::NCS3, MEM_NAND_BUSY_1_PIN, MEM_NAND_WR_ENABLE_PIN);
    MT29F mt29f_b(SMC::NCS1, MEM_NAND_BUSY_2_PIN, MEM_NAND_WR_ENABLE_PIN);

    LCL &nandLCL = LCLDefinitions::lclArray[LCLDefinitions::NANDFlash];
    nandLCL.enableLCL();

    if (mt29f.resetNAND() != MT29F_Errno::NONE) {
        LOG_DEBUG << "Error reseting NAND";
        mt29f.errorHandler(mt29f.resetNAND());
    }

    if (mt29f.isNANDAlive()) {
        LOG_DEBUG << "NAND ID correct (Die A)";
    } else {
        LOG_DEBUG << "NAND ID Error (Die A)";
        // Error handler logic
    }
    vTaskDelay(pdMS_TO_TICKS(500));

    if (mt29f_b.resetNAND() != MT29F_Errno::NONE) {
        LOG_DEBUG << "Error reseting NAND";
        mt29f_b.errorHandler(mt29f_b.resetNAND());
    }


    if (mt29f_b.isNANDAlive()) {
        LOG_DEBUG << "NAND ID correct (Die B)";
    } else {
        LOG_DEBUG << "NAND ID Error (Die B)";
        // Error handler logic
    }


    while (true) {
        vTaskDelay(pdMS_TO_TICKS(1000));
        LOG_DEBUG << "Testing NAND Die A on NCS3";
        testNANDmodule(mt29f);
        LOG_DEBUG << "Testing NAND Die B on NCS1";
        testNANDmodule(mt29f_b);
        // LOG_DEBUG << "Runtime is exiting: " << this->TaskName;

        // vTaskResume(MRAMTask::mramTaskHandle);
        // vTaskSuspend(NULL);
        vTaskDelay(pdMS_TO_TICKS(this->DelayMs));
    }
}
