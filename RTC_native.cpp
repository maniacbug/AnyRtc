// Code by JeeLabs http://news.jeelabs.org/code/
// Released to the public domain! Enjoy!

#if NATIVE

#include <iostream>
#include <string>
#include <time.h>
#include <WProgram.h>
#include "RTC_native.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////
// RTC_native implementation


uint8_t RTC_native::begin(void)
{
    cerr << "Currenly " << now() << endl;
    return 1;
}


uint8_t RTC_native::isrunning(void)
{
    return true;
}


void RTC_native::adjust(const DateTime& newtime)
{
    cerr << endl;
    cerr << "Currenly " << now() << endl;
    offset += newtime.unixtime() - now();
    cerr << "Adjusted to " << newtime.unixtime() << endl;
}

DateTime RTC_native::nowDateTime() const
{
    //tzset();

    DateTime result(time(NULL)+offset);

    return result; 
}

#endif // if NATIVE

// vim:ai:cin:sw=4 sts=4 ft=cpp
