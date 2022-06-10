#include "UARTGatekeeper.hpp"

void UARTGatekeeper::execute() {
    etl::string<LOGGER_MAX_MESSAGE_SIZE> output;
    while (true) {
        xQueueReceive(xPrintQueue, &output, portMAX_DELAY);
        const void *txRegisterAddress = const_cast<void *>(reinterpret_cast<volatile void *>(&USART1_REGS->US_THR));
        XDMAC_ChannelTransfer(XDMAC_CHANNEL_0, output.data(), txRegisterAddress, output.size());
    }
}