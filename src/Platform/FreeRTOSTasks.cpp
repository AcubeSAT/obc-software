#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"
#include "Parameters/HousekeepingService.hpp"

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
        TaskHandle_t reportParametersHandle = xTaskGetHandle(*static_cast<const char **>(taskName));

        while (true) {
            PlatformParameters::reportParametersUnusedStack.setValue(
                    uxTaskGetStackHighWaterMark(reportParametersHandle));
            PlatformParameters::availableHeap.setValue(
                    static_cast<uint16_t>(xPortGetFreeHeapSize()));
            PlatformParameters::obcBootCounter.setValue(
                    static_cast<uint16_t>(BootCounter::GPBRRead(BootCounter::BootCounterRegister)));
            PlatformParameters::obcSysTick.setValue(static_cast<uint64_t>(xTaskGetTickCount()));
            PlatformParameters::onBoardSecond.setValue(static_cast<uint64_t>(xTaskGetTickCount() / 1000));
            vTaskDelay(pdMS_TO_TICKS(300));
        }
    }

    void xUartDMA(void *pvParameters) {
        etl::string<17> usartData = "testing";
        while (true) {
            LOG_DEBUG << usartData.data();
            vTaskDelay(pdMS_TO_TICKS(3000));
        }
    }

    void housekeeping(void *pvParameters) {
        auto &housekeeping = Services.housekeeping;
        uint32_t nextCollection = 0xFFFFFFFF;
        uint32_t timePassed = 0;
        TickType_t xLastWakeTime = xTaskGetTickCount();

        while (true) {
            timePassed = nextCollection;
            nextCollection = 0xFFFFFFFF;
            for(auto& housekeepingStructure : housekeeping.housekeepingStructures){
                if(housekeepingStructure.second.timeToNextReport <= timePassed){
                    housekeeping.housekeepingParametersReport(housekeepingStructure.second.structureId);
                    housekeepingStructure.second.timeToNextReport = housekeepingStructure.second.collectionInterval;
                }
                else{
                    housekeepingStructure.second.timeToNextReport = housekeepingStructure.second.timeToNextReport - timePassed;
                }
                if(housekeepingStructure.second.timeToNextReport < nextCollection){
                    nextCollection = housekeepingStructure.second.timeToNextReport;
                }
            }
            vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(nextCollection));
        }
    }
}
