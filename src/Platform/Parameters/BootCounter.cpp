#include "BootCounter.hpp"
#include "OBC_Definitions.hpp"

namespace BootCounter {
    void clearRegisters() {
        GPBRWrite(UnexpectedResetRegister, clearRegisterValue);
        GPBRWrite(BootCounterRegister, clearRegisterValue);
    }

    void setRegisters() {
        if (GPBRRead(UnexpectedResetRegister) == softwareResetValue) {
            return;
        }

        GPBRWrite(UnexpectedResetRegister, softwareResetValue);
        GPBRWrite(BootCounterRegister, clearRegisterValue);
    }

    void incrementBootCounter() {
        if (GPBRRead(BootCounterRegister) > bootCounterLimit) {
            clearRegisters();
        }
        setRegisters();
        GPBRWrite(BootCounterRegister, GPBRRead(BootCounterRegister) + 1);
    }
}
