#include "Platform/Parameters/ParameterStatisticsService.hpp"
#include "PlatformParameters.hpp"

void ParameterStatisticsService::initializeStatistics() {
    using namespace PlatformParameters;
    uint16_t statisticParameterIDs[] = {ParameterID::AvailableHeap, ParameterID::OBCMCUTemperature};
    uint8_t idIndex = 0;

    for (auto &statistic: ParameterStatistics::statistics) {
        statisticsMap.insert({statisticParameterIDs[idIndex++], statistic});
    }
}