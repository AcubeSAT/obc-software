#pragma once

#include "Services/ParameterStatisticsService.hpp"
#include "PlatformParameters.hpp"

namespace ParameterStatistics {
    using namespace PlatformParameters;
    inline const uint16_t statisticParameterIDs[] = {ParameterID::OnBoardMinute, ParameterID::OnBoardSecond};
    inline etl::array<Statistic, 2> statistics = {
    };
}