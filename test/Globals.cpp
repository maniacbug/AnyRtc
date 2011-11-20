// STL includes
// C includes
// Library includes
#include <Dispatcher.h>
#include <Parser.h>
#include <Logger.h>
#include <Pins.h>
#include <Shell.h>
#include <SketchThread.h>
#include <SerialBuffer.h>
#include <Clock.h>
#include <EepromInternal.h>
#include <SpiQueue.h>
#include <Scheduler.h>
#include <Arduino.h>
// Project includes
#include <Globals.h>

Dispatcher theDispatcher;
Clock theClock;
Logger theLogger(theClock);
Pins thePins(theLogger);
SerialBuffer theSerialBuffer(theLogger);
Eeprom theEeprom(theLogger);
SpiQueue theSpiQueue(theLogger);
Scheduler theScheduler(theDispatcher,theLogger);

/****************************************************************************/

// vim:cin:ai:sts=2 sw=2 ft=cpp
