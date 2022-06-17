#include "UARTGatekeeper.hpp"

UARTGatekeeper::UARTGatekeeper() : Task("UARTGatekeeper", nullptr, 1000) {
    xUartQueue = xQueueCreate(UARTQueueSize, sizeof(etl::string<LOGGER_MAX_MESSAGE_SIZE>));
}

void UARTGatekeeper::execute() {
    etl::string<LOGGER_MAX_MESSAGE_SIZE> output;
    while (true) {
        xQueueReceive(xUartQueue, &output, portMAX_DELAY);
        const void *txRegisterAddress = const_cast<void *>(reinterpret_cast<volatile void *>(&USART1_REGS->US_THR));
        XDMAC_ChannelTransfer(XDMAC_CHANNEL_0, output.data(), txRegisterAddress, output.size());
    }
}
