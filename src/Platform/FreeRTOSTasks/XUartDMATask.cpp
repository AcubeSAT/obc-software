#include "FreeRTOSTasks/XUartDMATask.hpp"

void XUartDMATask::execute() {
    etl::string<17> usartData = "\rtesting\n";
    while (true) {
        LOG_DEBUG << usartData.data();
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
}
