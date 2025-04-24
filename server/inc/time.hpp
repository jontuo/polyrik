
#ifndef __TIME_HPP_INCLUDED__
#define __TIME_HPP_INCLUDED__

#include <chrono>
#include <cstdint>



class Time
{
public:
    static std::uint64_t getMicro();

private:
    Time();
    ~Time();
};

#endif
