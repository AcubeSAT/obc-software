#pragma once

#include "Services/ParameterStatisticsService.hpp"
#include "PlatformParameters.hpp"

namespace ParameterStatistics {
    using namespace PlatformParameters;
    inline const uint16_t statisticParameterIDs[] = {ParameterID::OnBoardMinute, ParameterID::OnBoardSecond};
    const uint8_t numOfStatistics = 2;
    inline etl::array<Statistic, numOfStatistics> statistics = {
    };
}