#include "CANTransmitTask.hpp"

void CANTransmitTask::execute() {
    CANDriver::txFifo.brs = 1;
    CANDriver::txFifo.fdf = 1;
    CANDriver::txFifo.xtd = 0;
    CANDriver::txFifo.id = 0x473 << 18;
    CANDriver::txFifo.dlc = CANDriver::convertLengthToDlc(8);

    for (uint8_t idx = 0; idx < 8; idx++) {
        CANDriver::txFifo.data[idx] = idx;
    }

    while (true) {
        MCAN1_MessageTransmitFifo(1, &CANDriver::txFifo);
        vTaskDelay(pdMS_TO_TICKS(1000));

    }
}