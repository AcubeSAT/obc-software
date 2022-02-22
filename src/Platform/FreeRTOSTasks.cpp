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

    void Housekeeping(void *pvParameters) {
        auto &housekeeping = Services.housekeeping;
        uint8_t structureParameterStart = 0;

        uint32_t collectionIntervals[] = {500, 500};
        uint16_t numsOfSimplyCommutatedParams[] = {2, 3};
        uint16_t structureParameters[] = {PlatformParameters::OnBoardSecond, PlatformParameters::AvailableHeap,
                                          PlatformParameters::OnBoardDay, PlatformParameters::OnBoardHour,
                                          PlatformParameters::OnBoardMinute};
        uint8_t numOfStructs = 2;

        for (uint8_t structId = 0; structId < numOfStructs; structId++) {
            Message createStructure = Message(HousekeepingService::ServiceType,
                                              HousekeepingService::MessageType::CreateHousekeepingReportStructure,
                                              Message::TC, 1);
            createStructure.appendUint8(structId);
            createStructure.appendUint32(collectionIntervals[structId]);
            createStructure.appendUint16(numsOfSimplyCommutatedParams[structId]);
            for (int i = 0; i < numsOfSimplyCommutatedParams[structId]; i++) {
                createStructure.appendUint16(structureParameters[structureParameterStart + i]);
            }
            structureParameterStart += numsOfSimplyCommutatedParams[structId];
            MessageParser::execute(createStructure);
            createStructure.resetRead();

        }

        Message enablePeriodicReports = Message(HousekeepingService::ServiceType,
                                                HousekeepingService::EnablePeriodicHousekeepingParametersReport,
                                                Message::TC, 1);
        enablePeriodicReports.appendUint8(numOfStructs);
        for (uint8_t structId = 0; structId < numOfStructs; structId++) {
            enablePeriodicReports.appendUint8(structId);
        }
        MessageParser::execute(enablePeriodicReports);
        enablePeriodicReports.resetRead();


        while (true) {
            for (int structId = 0; structId < numOfStructs; structId++) {
                housekeeping.housekeepingParametersReport(structId);
            }
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
}
