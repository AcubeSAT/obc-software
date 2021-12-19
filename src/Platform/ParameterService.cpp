#include "Services/ParameterService.hpp"
#include "Platform/SubSystemParameters.hpp"

etl::array <std::reference_wrapper<ParameterBase>, ECSS_PARAMETER_COUNT> ParameterService::initializeParametersArray() {

    return etl::array < std::reference_wrapper < ParameterBase > , ECSS_PARAMETER_COUNT > ({
                SubSystemParameters::parameter1,
                SubSystemParameters::parameter2,
                SubSystemParameters::parameter3,
                SubSystemParameters::parameter4
    });
}







