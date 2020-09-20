#ifndef __TIMER_H_
#define __TIMER_H_

/* Includes for the timer function */
#if defined(_WIN32)
    #include <Windows.h>
#elif defined(__unix__)
    #include <time.h>

    #define HAVE_POSIX_TIMER
    #ifdef CLOCK_MONOTONIC
        #define CLOCKID CLOCK_MONOTONIC
    #endif

#elif defined(__MACH__) && defined(__APPLE__)
    #define HAVE_MACH_TIMER
    #include <mach/mach.h>
    #include <mach/mach_time.h>
#else
    #include <time.h>
#endif

/**
 * @func: _get_timer
 * @desc: A cross platform timer function for profiling
 * @return The time in nanoseconds
 **/
static size_t _get_timer(void) {
    static size_t is_init = 0;

    /* Cross platform definition */
    #if defined(_WIN32)
        static LARGE_INTEGER win_frequency;
        if(0 == is_init) {
            QueryPerformanceFrequency(&win_frequency);
            is_init = 1;
        }
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (1e9 * now.QuadPart) / win_frequency.QuadPart;
    #elif defined(__APPLE__)
        static mach_timebase_info_data_t info;
        if(0 == is_init) {
            mach_timebase_info(&info);
            is_init = 1;
        }
        size_t now;
        now = mach_absolute_time();
        now *= info.numer;
        now /= info.denom;
        return now;
    #elif defined(__linux)
        static struct timespec linux_rate;
        if(0 == is_init) {
            clock_getres(CLOCKID, &linux_rate);
            is_init = 1;
        }
        size_t now;
        struct timespec spec;
        clock_gettime(CLOCKID, &spec);
        now = spec.tv_sec * 1.0e9 + spec.tv_nsec;
        return now;
    #endif
}

void display_total_time(size_t total_time) {
    if(total_time > 100000000)
        printf("total time: %.5f seconds\n", total_time / 1000000000.0);
    else
        printf("total time: %.5f ms\n", total_time / 1000000.0);
}

#define time_block(...) \
    size_t start_timer = _get_timer(); \
    do {\
        __VA_ARGS__ \
    while(0); \
    size_t total_time = _get_timer() - start_timer; \
    display_total_time(total_time); \
} while(0);

#endif
