#ifndef _WatchDog_H_
#define _WatchDog_H_

#include "Arduino.h"
#include <avr/wdt.h>

class WatchDog
{
private:
public:
    WatchDog();
    void disable();
    void setup();
    void reset();
};

extern WatchDog watch_dog;

#endif