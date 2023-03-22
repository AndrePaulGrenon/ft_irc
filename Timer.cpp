#include "Timer.hpp"

Timer::Timer() : _start_time(0) {}

Timer::~Timer() {}

void Timer::Start() 
{
    _start_time = clock();
}

float Timer::Timing() 
{
    return static_cast<float>( ((clock() - _start_time) / CLOCKS_PER_SEC) * 10000);
}