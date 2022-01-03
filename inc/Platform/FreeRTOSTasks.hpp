#ifndef OBC_SOFTWARE_FREERTOSTASKS_HPP
#define OBC_SOFTWARE_FREERTOSTASKS_HPP

#include "Parameters/PlatformParameters.hpp"

namespace FreeRTOSTasks {
    /**
     * FreeRTOS task for periodically reporting specific parameters
     * using \ref ParameterService's functionality
     * @param (void *) used for passing parameters inside FreeRTOS tasks,
     * @note @param is not used for now
     */
    void ParameterReporting(void *);

    /**
     * FreeRTOS task for updating specific parameters
     * using \ref ParameterService's functionality
     * @param (void *) used for passing parameters inside FreeRTOS tasks,
     * @note @param is not used for now
     */
    void ParameterUpdating(void *);
}

#endif //OBC_SOFTWARE_FREERTOSTASKS_HPP