#ifndef NAIBENCH_H
#define NAIBENCH_H

#if _WIN32
#include <windows.h>
#else
#include <time.h>
#endif

#include <stdio.h>

typedef struct
{
    const char* m_func_name;

#ifdef _WIN32
    LARGE_INTEGER m_start;
    LARGE_INTEGER m_frequency;
#else
    struct timespec m_start;
#endif

} NaiBench;

static inline NaiBench start(const char* func_name)
{
    NaiBench naibench;

#ifdef _WIN32
    QueryPerformanceFrequency(&mybench->frequency);
    QueryPerformanceCounter(&mybench->start);
#else
    naibench.m_func_name = func_name;
    clock_gettime(CLOCK_MONOTONIC, &naibench.m_start);
#endif

    return naibench;
}

static inline void stop(NaiBench* naibench)
{
#ifdef _WIN32
    LARGE_INTEGER end;
    QueryPerformanceCounter(&end);
    double elapsed = (double)(end.QuartPart - naibench->m_start.QuartPart) / naibench->m_frequency.QuartPart;
#else
    struct timespec end;

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed =
        (end.tv_sec - naibench->m_start.tv_sec)
    +   (end.tv_nsec - naibench->m_start.tv_nsec) / 1e9;

#endif

    printf("%s: %.9f time elapsed.\n", naibench->m_func_name, elapsed);
}

#define NAIBENCH_START_() NaiBench naibench = start(__func__)
#define NAIBENCH_STOP() stop(&naibench)

#endif
