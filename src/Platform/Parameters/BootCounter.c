#include "BootCounter.h"

void registersClear(void) {
    GPBRWrite(flagRegister, registerClearValue);
    GPBRWrite(bootCounterRegister, registerClearValue);
}

void registersSet(void) {
    if (GPBRRead(flagRegister) == flagValue)
        return;

    GPBRWrite(flagRegister, flagValue);
    GPBRWrite(bootCounterRegister, registerClearValue);
}

void bootCounterIncrement(void) {
    registersSet();
    GPBRWrite(bootCounterRegister, GPBRRead(bootCounterRegister) + 1);
    if (GPBRRead(bootCounterRegister) > bootCounterLimit)
        registersClear();
}
