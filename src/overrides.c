#include <stdio.h>
#include <sys/time.h>

#include "definitions.h"

#include <sys/types.h>

/**
 * _gettimeofday() is used by gettimeofday() of newlib, which is used by the
 * system_clock() of C++'s <chrono> library, which is used by Catch2's
 * timekeeping mechanism.
 *
 * This function overrides the default time getting and uses HAL ticks instead.
 *
 * @return 0 since we are always successful
 */
int _gettimeofday (struct timeval *tp, void * tzp)
{
    if (tp) {
        uint64_t tick = SYS_TIME_Counter64Get();

        tp->tv_sec = tick / 1000;
        tp->tv_usec = (tick % 1000) * 1000;
    }

    return 0;
}

time_t time (time_t * t)
{
    struct timeval now;

    if (_gettimeofday(&now, NULL) < 0) now.tv_sec = (time_t) -1;

    if (t) *t = now.tv_sec;
    return now.tv_sec;
}

/**
 * This function overwrites the default printf() and std::cout/cerr outputs,
 * redirecting them to a UART port.
 */
int _write(int file, char *ptr, int len)
{
    if (file == 1 || file == 2) { // stdout, stderr
        while (1) {
            // Wait until buffer is free
//            while (USART1_WriteFreeBufferCountGet() < len) {
//                SYSTICK_DelayMs(1);
//            }
            size_t bytesWritten = USART1_Write((uint8_t *) ptr, len);
            if (bytesWritten < len) {
                // Could not write the entire data to the queue (probably because the queue is full).
                // Take the remaining part and then try again
                ptr += bytesWritten;
                len -= bytesWritten;
            } else {
                break;
            }
        }
    }
    return len;
}