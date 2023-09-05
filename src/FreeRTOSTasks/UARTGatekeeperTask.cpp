#include "UARTGatekeeperTask.hpp"
#include "Peripheral_Definitions.hpp"

UARTGatekeeperTask::UARTGatekeeperTask() : Task("UARTGatekeeperTask") {
    xUartQueue = xQueueCreateStatic(UARTQueueSize, sizeof(etl::string<LOGGER_MAX_MESSAGE_SIZE>), ucQueueStorageArea,
                                    &xStaticQueue);
    XDMAC_ChannelCallbackRegister(XDMAC_CHANNEL_0,
                                  [](const XDMAC_TRANSFER_EVENT status, uintptr_t contextHandle) -> void {
                                      dmaTransactionStatus = status;
                                      BaseType_t xHigherPriorityTaskWoken = pdFALSE;
                                      configASSERT(uartGatekeeperTaskHandle != nullptr);
                                      vTaskNotifyGiveFromISR(uartGatekeeperTaskHandle, &xHigherPriorityTaskWoken);
                                      portYIELD_FROM_ISR(xHigherPriorityTaskWoken)
                                  }, reinterpret_cast<uintptr_t>(nullptr));
}

void UARTGatekeeperTask::execute() {
    etl::string<LoggerMaxMessageSize> output;
    const void *txRegisterAddress = const_cast<void *>(reinterpret_cast<volatile void *>(&UART_PERIPHERAL_REGISTER));
    while (true) {
        xQueueReceive(xUartQueue, &output, portMAX_DELAY);
        output.repair();
        if constexpr (LogsAreCOBSEncoded) {
            auto cobsEncoded = COBSencode<LoggerMaxMessageSize>(output);
            XDMAC_ChannelTransfer(XDMAC_CHANNEL_0, cobsEncoded.data(), txRegisterAddress, cobsEncoded.size());
        } else {
            XDMAC_ChannelTransfer(XDMAC_CHANNEL_0, output.data(), txRegisterAddress, output.size());
        }
        if (ulTaskNotifyTake(pdTRUE, maxDelay) != pdTRUE || (dmaTransactionStatus == XDMAC_TRANSFER_ERROR)) {
            LOG_DEBUG << "XDMAC transfer error, restarting...";
            XDMAC_Initialize();
            UART_Initialize();
        }
    }
}
