#include "CANTransmitTask.hpp"

void CANTransmitTask::execute() {
    CAN::Driver::txFifo.brs = 1;
    CAN::Driver::txFifo.fdf = 1;
    CAN::Driver::txFifo.xtd = 0;
    CAN::Driver::txFifo.id = 0x473 << 18;
    CAN::Driver::txFifo.dlc = CAN::Driver::convertLengthToDLC(8);

    for (uint8_t idx = 0; idx < 8; idx++) {
        CAN::Driver::txFifo.data[idx] = idx;
    }

    while (true) {
        MCAN1_MessageTransmitFifo(1, &CAN::Driver::txFifo);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}