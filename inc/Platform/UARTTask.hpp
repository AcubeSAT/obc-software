#ifndef FDIR_DEMO_UARTTASK_HPP
#define FDIR_DEMO_UARTTASK_HPP

#include <optional>
#include <Logger.hpp>
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <etl/queue_spsc_locked.h>
#include <definitions.h>

class QueueLock {
    SemaphoreHandle_t semaphore;
public:
    QueueLock() {
        semaphore = xSemaphoreCreateBinary();
    }

    void lock()
    {
        xSemaphoreTake(semaphore, 100);
    }

    void unlock()
    {
        xSemaphoreGive(semaphore);
    }
};



class UARTTask {
public:
    static constexpr int StringSize = 255;

    using StringType = etl::string<StringSize>;

    void operator()();

    UARTTask() : lock(uartQueueLock), unlock(uartQueueLock), queue(lock, unlock) {}

    void sendUARTMessage(const StringType& string) {
        queue.push(string);
    }
private:
    static constexpr int Capacity = 40;

    QueueLock uartQueueLock;
    etl::function_mv<QueueLock, &QueueLock::lock>   lock;
    etl::function_mv<QueueLock, &QueueLock::unlock> unlock;
    etl::queue_spsc_locked<etl::string<StringSize>, Capacity, etl::memory_model::MEMORY_MODEL_SMALL> queue;

    StringType buffer;
};

extern std::optional<UARTTask> uartTask;

#endif //FDIR_DEMO_UARTTASK_HPP
