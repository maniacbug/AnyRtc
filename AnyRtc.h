/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

#ifndef __ANYRTC_H__
#define __ANYRTC_H__

// STL headers
// C headers
// Framework headers
#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif
// Library headers
// Project headers

struct IRTC;
class DateTime;

/**
 * Publically explosed singleton class for managing current RTC.
 */

class AnyRtc
{
private:
  IRTC* implementation;
protected:
public:
  AnyRtc(IRTC* = NULL);
  uint8_t begin(IRTC* = NULL);
  void adjust(const DateTime& dt);
  void adjust(uint32_t);
  uint32_t now(void) const;
  DateTime nowDateTime(void) const;
};

/**
 * Singleton instance for general use
 */
extern AnyRtc RTC;

/**
 * Simple general-purpose date/time class (no TZ / DST / leap second handling!)
 *
 * @author Jee Labs http://news.jeelabs.org/code/
 * @copyright Released to the public domain! Enjoy!
 */

class DateTime
{
public:
    DateTime (uint32_t t =0);
    DateTime (uint16_t year, uint8_t month, uint8_t day,
              uint8_t hour =0, uint8_t min =0, uint8_t sec =0);
    DateTime (const char* date, const char* time);
    uint16_t year() const
    {
        return 2000 + yOff;
    }
    uint8_t month() const
    {
        return m;
    }
    uint8_t day() const
    {
        return d;
    }
    uint8_t hour() const
    {
        return hh;
    }
    uint8_t minute() const
    {
        return mm;
    }
    uint8_t second() const
    {
        return ss;
    }
    uint8_t dayOfWeek() const;

    // 32-bit times as seconds since 1/1/2000
    long secondstime() const;
    // 32-bit times as seconds since 1/1/1970
    uint32_t unixtime(void) const;
    // as a string
    char* toString(char* buf, int maxlen) const;
    // add additional time
    void operator+=(uint32_t);

protected:
    uint8_t yOff, m, d, hh, mm, ss;
};

/**
 * Public interface which all RTC's must implement
 */

struct IRTC
{
  virtual uint8_t begin(void) =0;
  virtual void adjust(const DateTime& dt)
  {
    adjust(dt.unixtime());
  }
  virtual void adjust(uint32_t) =0;
  virtual uint32_t now(void) const =0;
  virtual DateTime nowDateTime(void) const
  {
    return DateTime(now());
  }
};

/**
 * RTC based on the millis() timer
 */

class RTC_millis: public IRTC
{
private:
  uint32_t time_at_zero; 
public:
  RTC_millis(void): time_at_zero(0) 
  {
  }
  virtual uint8_t begin(void)
  {
    time_at_zero = 0;
    return true;
  }
  virtual void adjust(uint32_t tv)
  {
    time_at_zero = tv - millis() / 1000;
  }
  virtual uint32_t now(void) const
  {
    return time_at_zero + millis() / 1000;
  }
};

#endif // __ANYRTC_H__
// vim:cin:ai:sts=2 sw=2 ft=cpp
