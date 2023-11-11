#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
#include "ezButton.h"

#include "GPIO_CONFIG.hpp"

class Buttons
{
private:
    ezButton hold_skip_input_button;

public:
    Buttons(ezButton hold_skip_input_button);
    void setup();
    void loop();
    void check();
};

extern Buttons buttons;

#endif