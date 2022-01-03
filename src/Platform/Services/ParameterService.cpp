#include "ECSS_Configuration.hpp"
#ifdef SERVICE_PARAMETER

#include "Services/ParameterService.hpp"
#include "Parameters/PlatformParameters.hpp"

void ParameterService::initializeParameterMap() {
    parameters = {{PlatformParameters::OnBoardYear,    PlatformParameters::currentYear},
                  {PlatformParameters::OnBoardMonth,   PlatformParameters::currentMonth},
                  {PlatformParameters::OnBoardDay,     PlatformParameters::currentDay},
                  {PlatformParameters::OnBoardHour,    PlatformParameters::currentHour},
                  {PlatformParameters::OnBoardMinute,  PlatformParameters::currentMinute},
                  {PlatformParameters::OnBoardSecond,  PlatformParameters::currentSecond},
                  {PlatformParameters::AvailableStack, PlatformParameters::parameterReportingAvailableStackInWords},
                  {PlatformParameters::AvailableHeap,  PlatformParameters::availableHeapInWords}};
}

#endif