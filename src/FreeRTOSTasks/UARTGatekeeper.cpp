#include "UARTGatekeeperTask.hpp"

UARTGatekeeperTask::UARTGatekeeperTask() : Task("UARTGatekeeperTask", nullptr, 1000) {
    static StaticQueue_t xStaticQueue;
    uint8_t ucQueueStorageArea[ UARTQueueSize * sizeof(etl::string<LOGGER_MAX_MESSAGE_SIZE>) ];
    xUartQueue = xQueueCreateStatic(UARTQueueSize, sizeof(etl::string<LOGGER_MAX_MESSAGE_SIZE>), ucQueueStorageArea, &xStaticQueue);
}

void UARTGatekeeperTask::execute() {
    etl::string<LOGGER_MAX_MESSAGE_SIZE> output;
    while (true) {
        xQueueReceive(xUartQueue, &output, portMAX_DELAY);
        const void *txRegisterAddress = const_cast<void *>(reinterpret_cast<volatile void *>(&USART1_REGS->US_THR));
        XDMAC_ChannelTransfer(XDMAC_CHANNEL_0, output.data(), txRegisterAddress, output.size());
    }
}
