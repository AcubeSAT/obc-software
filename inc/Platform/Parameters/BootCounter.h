/*************************************************************************
 * GPBROps files contain the functionality for the Boot Counter parameter
 * using ATSAMV71Q21's General Purpose Backup Registers (GPBR).
 * GPBR were chosen because the contents are saved after a software MCU
 * reset which is needed for testing purposes.
 * However, these registers reset at first power-up and on each power
 * loss.
 * As a result, a different non-volatile memory will be used in the
 * satellite's final software.
 ************************************************************************/

#ifndef OBC_SOFTWARE_BOOTCOUNTER_H
#define OBC_SOFTWARE_BOOTCOUNTER_H

/**
 * Defines which one of the eight registers
 * will be used to save the flag value.
 * The purpose of the flag is to distinguish
 * software from hardware resets.
 * The flag is saved inside the second GPBR.
 */
#define flagRegister 0

/**
 * This is the flag value to be stored inside the
 * boot counter Flag Register.
 * @see bootCounterFlagRegister.
 */
#define flagValue 1

/**
 * Defines which one of the eight registers will be
 * used to save the boot counter.
 * The counter is saved inside the second GPBR.
 */
#define bootCounterRegister 1

/**
 * Defines the register's value after it is cleared.
 */
#define registerClearValue 0

/**
 * A counter limit for hardware reset simulation.
 * @see bootCounterIncrement
 */
#define bootCounterLimit 1000

#ifdef __cplusplus
extern "C" {
#endif

#include "device.h"

/**
 * This function is used to read from a GPBR.
 * @param registerIndex : which one of the eight registers to read from.
 *        Values can be 0-7, but only 0-1 are used.
 * @return the 32-bit data inside the register.
 */
static inline uint32_t GPBRRead(uint8_t registerIndex) {
    return GPBR_REGS->SYS_GPBR[registerIndex];
}

/**
 * This function is used to write inside a GPBR.
 * @param registerIndex : which one of the eight registers to write to.
 *        Values can be 0-7, but only 0-1 are used.
 * @param data : the 32-bit data to store inside the register.
 */
static inline void GPBRWrite(uint8_t registerIndex, uint32_t data) {
    GPBR_REGS->SYS_GPBR[registerIndex] = data;
}

/**
 * Clears both the flag and counter registers.
 * @see flagRegister and bootCounterRegister.
 */
void registersClear(void);

/**
 * Checks the value of the flagRegister.
 * If the flag value is stored, a software reset is detected
 * and the function returns.
 * Otherwise, a hardware reset is detected so the flag and counter
 * registers are set to their initial values.
 */
void registersSet(void);

/**
 * Increments the boot counter.
 * If the counter limit is reached, the registers are cleared.
 */
void bootCounterIncrement(void);

#ifdef __cplusplus
}
#endif

#endif //OBC_SOFTWARE_BOOTCOUNTER_H
