#ifndef OBC_SOFTWARE_FREERTOSTASKS_HPP
#define OBC_SOFTWARE_FREERTOSTASKS_HPP

namespace FreeRTOSTasks {
    /**
     * FreeRTOS task for periodically reporting specific parameters using ParameterService functionality.
     * @param pvParameters used for passing parameters inside FreeRTOS tasks.
     * @see ParameterService
     */
    void reportParameters(void *pvParameters);

    /**
     * FreeRTOS task for periodically updating specific parameters using ParameterService functionality.
     * @param taskName pointer to a const char pointer necessary to create a FreeRTOS TaskHandle_t variable
     *        to keep track of the minimum available stack of \ref reportParameters.
     */
    void updateParameters(void *taskName);

    /**
     * FreeRTOS task for periodically printing "testing" using Direct Memory Access in tandem with USART1.
     * Intended for demonstration purposes
     * @param pvParameters used for passing parameters inside FreeRTOS tasks.
     */
     void xUartDMA(void *pvParameters);

    /**
    * FreeRTOS task for periodically printing the value of the internal temperature sensor.
    * @param pvParameters used for passing parameters inside FreeRTOS tasks.
    */
     void temperatureTask(void *pvParameters);
}

#endif //OBC_SOFTWARE_FREERTOSTASKS_HPP