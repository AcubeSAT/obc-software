#include "CANTransmitTask.hpp"
#include "CANGatekeeperTask.hpp"

void CANTransmitTask::execute() {
    CAN::Frame message = {};

    message.id = 0x45A;
    for (uint8_t idx = 0; idx < CAN::Frame::MaxDataLength; idx++) {
        message.data[idx] = idx;
    }

    while (true) {
        canGatekeeperTask->send(message);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}