#define _CRT_SECURE_NO_WARNINGS
#include "system/actualTime.hpp"

void PrintTime()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << (now->tm_year + 1900) << '-'
        << (now->tm_mon + 1) << '-'
        << now->tm_mday     << '/'
        << now->tm_hour     << ':'
        << now->tm_min      << ':'
        << now->tm_sec
        << "\n";
}

int GetYear()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    return (now->tm_year % 100);
}

int GetMonth()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    return (now->tm_mon + 1);
}

int GetDay()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    return (now->tm_mday);
}

int GetHour()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    return (now->tm_hour);
}

int GetMin()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    return (now->tm_min);
}

int GetSec()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    return (now->tm_sec);
}