#ifndef OBC_SOFTWARE_BOOTCOUNTER_HPP
#define OBC_SOFTWARE_BOOTCOUNTER_HPP

/***********************************************************************************************************
 * BootCounter files contain the functionality for the Boot Counter using ATSAMV71Q21's General Purpose
 * Backup Registers (GPBR). GPBR were chosen because the contents are saved after a software MCU reset
 * which is needed for testing purposes. However, these registers reset at first power-up and on each
 * power loss. As a result, a different non-volatile memory will be used in the satellite's final software.
 **********************************************************************************************************/

#include "device.h"

/**
 * Namespace containing functionality for the \ref bootCounter parameter.
 */
namespace BootCounter {
    /**
     * This function is used to read from a GPBR.
     * @param registerIndex : which one of the eight registers to read from. Values can be 0-7.
     * @return the 32-bit data inside the register.
     */
    inline uint32_t GPBRRead(uint8_t registerIndex) {
        return GPBR_REGS->SYS_GPBR[registerIndex];
    }

    /**
     * This function is used to write inside a GPBR.
     * @param registerIndex : which one of the eight registers to write to. Values can be 0-7.
     * @param data : the 32-bit data to store inside the register.
     */
    inline void GPBRWrite(uint8_t registerIndex, uint32_t data) {
        GPBR_REGS->SYS_GPBR[registerIndex] = data;
    }

    /**
     * Clears both the \ref UnexpectedResetRegister and \ref BootCounterRegister.
     */
    void clearRegisters();

    /**
     * Checks the value of the UnexpectedResetRegister. If the \ref softwareResetValue value is stored, a
     * software reset is detected and the function returns. Otherwise, a hardware reset is detected
     * so both the \ref UnexpectedResetRegister and \ref BootCounterRegister are set to their initial values.
     */
    void setRegisters();

    /**
     * Increments the boot counter.
     * If the counter limit is reached, the registers are cleared.
     */
    void incrementBootCounter();
}

#endif //OBC_SOFTWARE_BOOTCOUNTER_HPP
