#pragma once

#include "Services/ParameterStatisticsService.hpp"
#include "PlatformParameters.hpp"

namespace ParameterStatistics {
    using namespace PlatformParameters;
    const uint8_t NumOfStatistics = 2;
    inline const etl::array<uint16_t, NumOfStatistics> statisticParameterIDs = {ParameterID::OnBoardMinute,
                                                                                ParameterID::OnBoardSecond};
    inline etl::array<Statistic, NumOfStatistics> statistics = {
    };
}