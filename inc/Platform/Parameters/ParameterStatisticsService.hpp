#pragma once

#include "Services/ParameterStatisticsService.hpp"

namespace ParameterStatistics {
    static etl::array<Statistic, ECSSMaxStatisticParameters> statistics = {
            Statistic(), Statistic(),
    };
}