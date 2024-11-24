#pragma once

#include "Task.hpp"
#include "ApplicationLayer.hpp"

class TimeSyncTask : public Task {
private:
    bool timeRequested = false;

public:
    const static inline uint16_t TaskStackDepth = 800;

    const uint32_t TimeSyncPeriod = 3000000;

    const uint16_t TimeRequestDelay = 1000;

    const uint16_t TimeSendDelay = 100;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    TimeSyncTask() : Task("TimeSyncTask") {}

    void setTimeRequested(bool timeRequested) {
        this->timeRequested = timeRequested;
    }

    /**
     * Create freeRTOS Task
     */
    void createTask() {
        this->taskHandle = xTaskCreateStatic(vClassTask<TimeSyncTask>, this->TaskName, TimeSyncTask::TaskStackDepth, this,
                          tskIDLE_PRIORITY, this->taskStack, &(this->taskBuffer));
    }
};

inline std::optional<TimeSyncTask> timeSyncTask;

/* timeSyncTask: As of now, (some features have to change or get added) checks if OBC has requested the on board time
 * from the ADCS. If not, it sets a notifier at the adcsOnBoardTime. Then it request the adcsOnBoardTime from ADCS and
 * puts itself into the blocked state. If the time is requested then it sends a UTCTimeMessage which will get parsed
 * from the other subsystems so they will sync with the OBC.
 *
 *  adcsOnBoardTime Notifier: When adcsOnBoardTime gets updated, OBC sets the on board time through RTC, gives a notify
 *  to the timeSyncTask and unsets itself.
 */