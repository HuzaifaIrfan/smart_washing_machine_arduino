#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
#include "ezButton.h"

#include "GPIO_CONFIG.hpp"

class Buttons
{
public:
    Buttons();
    void setup();
    void loop();
};

extern Buttons buttons;

#endif