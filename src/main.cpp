#include "main.h"
#include "SEGGER_RTT.h"

extern "C" void main_cpp() {
    SEGGER_RTT_Init();
    SEGGER_RTT_printf(0, "test");
}
