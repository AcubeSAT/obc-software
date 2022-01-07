#ifndef OBC_SOFTWARE_FREERTOSTASKS_HPP
#define OBC_SOFTWARE_FREERTOSTASKS_HPP

namespace FreeRTOSTasks {
    /**
     * FreeRTOS task for periodically reporting specific parameters
     * using \ref ParameterService's functionality
     * @param (void *) used for passing parameters inside FreeRTOS tasks,
     *        not currently in use
     */
    void parameterReporting(void *);

     /**
      * FreeRTOS task for updating specific parameters
      * using \ref ParameterService's functionality
      * @param taskName : pointer to a const char pointer necessary
      *        to create a FreeRTOS TaskHandle_t variable to keep track
      *        of \fn parameterReporting's minimum available stack
      */
    void parameterUpdating(void *taskName);
}

#endif //OBC_SOFTWARE_FREERTOSTASKS_HPP