
#include "watch_dog.hpp"

WatchDog::WatchDog()
{
}

void WatchDog::setup()
{
    wdt_disable();       // Disable WDT
    wdt_enable(WDTO_4S); // Enable WDT with a timeout of 8 seconds
    Serial.println("WDT Enabled");
}

void WatchDog::reset()
{
    wdt_reset();
}

WatchDog watch_dog;