#pragma once

#include "Task.hpp"
#include "ApplicationLayer.hpp"

/* This task serves a dual purpose. The first objective is to request the onboard time from the ADCS subsystem if a
 * reset has occured, enabling the OBC to synchronize and operate with the correct system time.
 * The second objective is to periodically (at intervals defined by TimeSyncPeriod) invoke the sendUTCTimeMessage
 * function to broadcast the onboard time to all subsystems.
 * This ensures that subsystems remain synchronized, addressing any drift or desynchronization that may have occurred.
 *
 * timeSyncTask: As of now, (some features have to change or get added) checks if OBC has requested the onboard time
 * from the ADCS. If not, it sets a notifier at the adcsOnBoardTime. Then it request the adcsOnBoardTime from ADCS and
 * puts itself into the blocked state. If the time is requested then it sends a UTCTimeMessage which will get parsed
 * from the other subsystems so they will sync with the OBC.
 *
 *  adcsOnBoardTime Notifier: When adcsOnBoardTime gets updated, OBC sets the onboard time through RTC, gives a notify
 * adcsOnBoardTime Notifier: When adcsOnBoardTime gets updated, OBC sets the onboard time through RTC, gives a notify
 * to the timeSyncTask and unsets itself.
 */
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
