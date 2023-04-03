#include "ImportFromJava.h"

static int64_t hpms_nano() {
    static LARGE_INTEGER ticksPerSecond;
    if (ticksPerSecond.QuadPart == 0) {
        QueryPerformanceFrequency(&ticksPerSecond);
    }
    LARGE_INTEGER ticks;
    QueryPerformanceCounter(&ticks);
    uint64_t nano = (1000 * 1000 * 10UL * ticks.QuadPart) / ticksPerSecond.QuadPart;
    nano *= 100UL;
    return nano;
}