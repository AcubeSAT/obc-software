#include "ECSS_Configuration.hpp"

#ifdef SERVICE_PARAMETER

#include "Services/ParameterService.hpp"
#include "PlatformParameters.hpp"

void ParameterService::initializeParameterMap() {
    parameters = {{PlatformParameters::OnBoardYear,                 PlatformParameters::onBoardYear},
                  {PlatformParameters::OnBoardMonth,                PlatformParameters::onBoardMonth},
                  {PlatformParameters::OnBoardDay,                  PlatformParameters::onBoardDay},
                  {PlatformParameters::OnBoardHour,                 PlatformParameters::onBoardHour},
                  {PlatformParameters::OnBoardMinute,               PlatformParameters::onBoardMinute},
                  {PlatformParameters::OnBoardSecond,               PlatformParameters::onBoardSecond},
                  {PlatformParameters::ReportParametersUnusedStack, PlatformParameters::reportParametersUnusedStack},
                  {PlatformParameters::AvailableHeap,               PlatformParameters::availableHeap},
                  {PlatformParameters::OBCBootCounter,              PlatformParameters::obcBootCounter},
                  {PlatformParameters::OBCSystick,                  PlatformParameters::obcSysTick}};
}

#endif
