#ifndef CONFIG_H_
#define CONFIG_H_

// Move settings to cmake to make git happy :)

// #define WITH_SCALE
// #define WITH_CUDA
// #define WITH_TBB
// #define WITH_OPENGL

const int GRAIN_SIZE = 1024;

#define LOG_OUTPUT

#ifdef LOG_OUTPUT

#define lprintf(...) printf(__VA_ARGS__)
#define lputs(...) puts(__VA_ARGS__)

#else

#define lprintf(...) void(0)
#define lputs(...) void(0)

#endif

#include <chrono>

// simulation of Windows GetTickCount()
unsigned long long inline GetCurrentTime64() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}
#endif
