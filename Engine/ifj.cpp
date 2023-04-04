#include "ifj.h"
#include <chrono>

long long ifj::get_nanotime() {
    auto now = std::chrono::high_resolution_clock::now();
    auto nanos = std::chrono::time_point_cast<std::chrono::nanoseconds>(now).time_since_epoch().count();
    return nanos;
}

