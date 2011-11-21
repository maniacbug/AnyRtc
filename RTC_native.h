// Code by JeeLabs http://news.jeelabs.org/code/
// Released to the public domain! Enjoy!

#ifndef __RTC_NATIVE_H__
#define __RTC_NATIVE_H__

#if NATIVE

#include <AnyRtc.h>

// RTC based on the native chip connected via SPI and the SPI library
class RTC_native: public IRTC
{
private:
    int32_t offset; /**< Offset from real time to the 'RTC' time */
public:
    RTC_native(): offset(0) {}
    uint8_t begin(void);
    void adjust(const DateTime& dt);
    void adjust(uint32_t tv) { adjust(DateTime(tv)); }
    uint8_t isrunning(void);
    DateTime nowDateTime() const;
    uint32_t now(void) const { return nowDateTime().unixtime(); }
};

#endif // NATIVE

#endif // __RTC_NATIVE_H__

// vim:ai:cin:sw=4 sts=4 ft=cpp
