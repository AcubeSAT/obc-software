#include "ECSS_Configuration.hpp"
#ifdef SERVICE_PARAMETER

#include "Services/ParameterService.hpp"
#include "PlatformParameters.hpp"

void ParameterService::initializeParameterMap() {
    parameters = {{PlatformParameters::OnBoardYear,    PlatformParameters::currentYear},
                  {PlatformParameters::OnBoardMonth,   PlatformParameters::currentMonth},
                  {PlatformParameters::OnBoardDay,     PlatformParameters::currentDay},
                  {PlatformParameters::OnBoardHour,    PlatformParameters::currentHour},
                  {PlatformParameters::OnBoardMinute,  PlatformParameters::currentMinute},
                  {PlatformParameters::OnBoardSecond,  PlatformParameters::currentSecond},
                  {PlatformParameters::AvailableStack, PlatformParameters::parameterReportingAvailableStack},
                  {PlatformParameters::AvailableHeap,  PlatformParameters::availableHeap},
                  {PlatformParameters::OBCBootCounter, PlatformParameters::O_OBOOTCOUNT},
                  {PlatformParameters::OBCSystick,  PlatformParameters::O_OSYST}};
}

#endif
