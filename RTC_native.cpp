// Code by JeeLabs http://news.jeelabs.org/code/
// Released to the public domain! Enjoy!

#if NATIVE

#include <iostream>
#include <string>
#include <time.h>
#include <avr/pgmspace.h>
#include <WProgram.h>
#include "RTC_native.h"

////////////////////////////////////////////////////////////////////////////////
// RTC_native implementation


uint8_t RTC_native::begin(void)
{
    return 1;
}


uint8_t RTC_native::isrunning(void)
{
    return true;
}

void RTC_native::adjust(const DateTime& newtime)
{
    offset += newtime.unixtime() - now();
}

DateTime RTC_native::nowDateTime() const
{
    tzset();

    return DateTime(time(NULL)+offset-timezone); //+(daylight?3600:0));
}

#endif // if NATIVE

// vim:ai:cin:sw=4 sts=4 ft=cpp
