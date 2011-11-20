/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

// STL headers
// C headers
// Framework headers
// Library headers
// Project headers
// This component's header
#include <AnyRtc.h>

static RTC_millis RTC_millis_internal;

/****************************************************************************/

AnyRtc::AnyRtc(IRTC* _which): implementation(_which)
{
  if ( _which == NULL )
    implementation = &RTC_millis_internal;
}

/****************************************************************************/

uint8_t AnyRtc::begin(IRTC* _which)
{
  if ( _which )
    implementation = _which;

  return implementation->begin();
}

/****************************************************************************/

void AnyRtc::adjust(const DateTime& dt)
{
  implementation->adjust(dt);
}

/****************************************************************************/

void AnyRtc::adjust(uint32_t tv)
{
  implementation->adjust(tv);
}

/****************************************************************************/

uint32_t AnyRtc::now(void) const
{
  return implementation->now();
}

/****************************************************************************/

DateTime AnyRtc::nowDateTime(void) const
{
  return implementation->nowDateTime();
}

/****************************************************************************/

// vim:cin:ai:sts=2 sw=2 ft=cpp
