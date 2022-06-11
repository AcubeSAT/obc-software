#ifndef OBC_SOFTWARE_WATCHDOGTASK_H
#define OBC_SOFTWARE_WATCHDOGTASK_H


#include "Task.hpp"

class WatchdogTask : public Task{
private:
    /**
     * The delay in milliseconds between each watchdog reset.
     */
    const uint16_t delayMs = 14000;
public:
    void execute();

    WatchdogTask() : Task("Watchdog", nullptr, 500) {}
};


#endif //OBC_SOFTWARE_WATCHDOGTASK_H
