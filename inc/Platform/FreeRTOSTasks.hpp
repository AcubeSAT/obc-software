#ifndef OBC_SOFTWARE_FREERTOSTASKS_HPP
#define OBC_SOFTWARE_FREERTOSTASKS_HPP

namespace FreeRTOSTasks {
    /**
     * FreeRTOS task for periodically reporting specific parameters using ParameterService functionality.
     * @param pvParameters : used for passing parameters inside FreeRTOS tasks.
     * @see ParameterService
     */
    void reportParameters(void *pvParameters);

    /**
     * FreeRTOS task for updating specific parameters using ParameterService functionality.
     * @param taskName : pointer to a const char pointer necessary to create a FreeRTOS TaskHandle_t variable
     *        to keep track of \ref reportParameters' minimum available stack.
     */
    void updateParameters(void *taskName);
}

#endif //OBC_SOFTWARE_FREERTOSTASKS_HPP