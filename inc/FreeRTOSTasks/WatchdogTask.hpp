#ifndef OBC_SOFTWARE_WATCHDOGTASK_H
#define OBC_SOFTWARE_WATCHDOGTASK_H


#include "Task.hpp"

class WatchdogTask : public Task{
private:
    const uint16_t delayMs = 3000;
public:
    void execute();

    WatchdogTask() : Task("Watchdog", nullptr, 2000) {}
};


#endif //OBC_SOFTWARE_WATCHDOGTASK_H
