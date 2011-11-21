// Code by JeeLabs http://news.jeelabs.org/code/
// Released to the public domain! Enjoy!

#ifndef __RTC_DS3234_H__
#define __RTC_DS3234_H__

#include <AnyRtc.h>

// RTC based on the DS3234 chip connected via SPI and the SPI library
class RTC_DS3234: public IRTC
{
public:
    RTC_DS3234(int _cs_pin): cs_pin(_cs_pin) {}
    uint8_t begin(void);
    void adjust(const DateTime& dt);
    void adjust(uint32_t tv) { adjust(DateTime(tv)); }
    uint8_t isrunning(void);
    DateTime nowDateTime() const;
    uint32_t now(void) const { return nowDateTime().unixtime(); }

protected:
    void cs(int _value) const;

private:
    int cs_pin;
};

#endif // __RTC_DS3234_H__

// vim:ai:cin:sw=4 sts=4 ft=cpp
