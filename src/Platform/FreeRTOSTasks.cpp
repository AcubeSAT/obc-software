#include "FreeRTOSTasks.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "PlatformParameters.hpp"
#include "ServicePool.hpp"
#include "BootCounter.hpp"
#include "definitions.h"
#include "Logger.hpp"

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

    void Housekeeping(void *pvParameters){
        HousekeepingService &housekeepingService = Services.housekeeping;
        Message createStructure = Message(HousekeepingService::ServiceType,
                                          HousekeepingService::MessageType::CreateHousekeepingReportStructure,
                                          Message::TC, 1);
        uint8_t idToCreate = 1;
        createStructure.appendUint8(idToCreate);
        uint32_t collectionInterval = 500;
        createStructure.appendUint32(collectionInterval);
        uint16_t numOfSimplyCommutatedParams = 0;
        createStructure.appendUint16(numOfSimplyCommutatedParams);
//        createStructure.appendUint16();
//        createStructure.appendUint16();
        LOG_DEBUG << "createStructure";
        MessageParser::execute(createStructure);

        Message enablePeriodicReports = Message(HousekeepingService::ServiceType,
                                                HousekeepingService::EnablePeriodicHousekeepingParametersReport,
                                                Message::TC, 1);
        uint8_t numOfStructIds = 1;
        enablePeriodicReports.appendUint8(numOfStructIds);
        uint8_t structIdToEnable = 1;
        enablePeriodicReports.appendUint8(structIdToEnable);
        housekeepingService.enablePeriodicHousekeepingParametersReport(enablePeriodicReports);
        MessageParser::execute(enablePeriodicReports);

        Message reportStructures = Message(HousekeepingService::ServiceType,
                                           HousekeepingService::GenerateOneShotHousekeepingReport,
                                           Message::TC, 1);
        uint8_t numOfStructsToReport = 1;
        reportStructures.appendUint8(numOfStructsToReport);
        uint8_t structureId = 1;
        reportStructures.appendUint8(structureId);
        LOG_DEBUG << "reportStructures";
        MessageParser::execute(reportStructures);

        while(true){
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
}
