#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"

namespace FreeRTOSTasks {
    void reportParameters(void *) {
        Message request = Message(ParameterService::ServiceType,
                                  ParameterService::MessageType::ReportParameterValues,
                                  Message::TC, 1);
        const uint16_t numberOfIDs = 10;
        request.appendUint16(numberOfIDs);
        request.appendUint16(PlatformParameters::OnBoardYear);
        request.appendUint16(PlatformParameters::OnBoardMonth);
        request.appendUint16(PlatformParameters::OnBoardDay);
        request.appendUint16(PlatformParameters::OnBoardHour);
        request.appendUint16(PlatformParameters::OnBoardMinute);
        request.appendUint16(PlatformParameters::OnBoardSecond);
        request.appendUint16(PlatformParameters::ReportParametersUnusedStack);
        request.appendUint16(PlatformParameters::AvailableHeap);
        request.appendUint16(PlatformParameters::OBCBootCounter);
        request.appendUint16(PlatformParameters::OBCSystick);

        while (true) {
            MessageParser::execute(request);
            request.resetRead();
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }

    void updateParameters(void *taskName) {
        TaskHandle_t reportParametersHandle = xTaskGetHandle(
                *static_cast<const char **>(taskName));

        while (true) {
            PlatformParameters::reportParametersUnusedStack.setValue(
                    uxTaskGetStackHighWaterMark(reportParametersHandle));
            PlatformParameters::availableHeap.setValue(
                    static_cast<uint16_t>(xPortGetFreeHeapSize()));
            PlatformParameters::obcBootCounter.setValue(
                    BootCounter::GPBRRead(BootCounter::BootCounterRegister));
            PlatformParameters::obcSysTick.setValue(static_cast<uint64_t>(xTaskGetTickCount()));
            vTaskDelay(pdMS_TO_TICKS(300));
        }
    }
}
