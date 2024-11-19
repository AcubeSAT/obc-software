#pragma once

#include "Task.hpp"
#include "ApplicationLayer.hpp"

class TimeSyncTask : public Task {
private:
    bool timeRequested = false;

public:
    const int TimeSyncPeriod = 10000;

    const static inline uint16_t TaskStackDepth = 2300;

    StackType_t taskStack[TaskStackDepth];

    void execute();

    TimeSyncTask() : Task("TimeSyncTask") {
    }

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

inline void updateTimeOnReset(const Time::DefaultCUC& time){
    Time::DefaultCUC time1 = time;
    UTCTimestamp utc = time1.toUTCtimestamp();
    const int MonthOffset = -1;
    tm now{utc.second, utc.minute, utc.hour, utc.day, utc.month + MonthOffset, utc.year, 0, 0, 0};
    RTC_TimeSet(&now);
    timeSyncTask->setTimeRequested(true);
    xTaskNotifyGive(timeSyncTask->taskHandle);
    AcubeSATParameters::adcsOnBoardTime.unsetNotifier();
}