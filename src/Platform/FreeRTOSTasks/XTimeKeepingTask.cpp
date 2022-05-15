#include "FreeRTOSTasks/XTimeKeepingTask.hpp"

void XTimeKeepingTask::execute() {
    static tm dateTime;
    setEpoch(dateTime);
    RTC_TimeSet(&dateTime);

    while (true) {
        RTC_TimeGet(&dateTime);
        setTimePlatformParameters(dateTime);

        printOnBoardTime();
        vTaskDelay(pdMS_TO_TICKS(delayMs));
    }
};