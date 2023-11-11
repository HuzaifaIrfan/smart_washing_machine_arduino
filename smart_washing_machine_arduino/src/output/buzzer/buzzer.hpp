#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

#include "GPIO_CONFIG.hpp"

class Buzzer
{
private:
    short pin;

    bool buzz = false;
    short beepCountSet = 0;

    bool buzNow = false;
    short beepCount = 0;

public:
    Buzzer(short pin);
    void setup();
    void loop();

    bool set(short beepCountSetValue);
    void test();
    void off();
};

extern Buzzer buzzer;

#endif