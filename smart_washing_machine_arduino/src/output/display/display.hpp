#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

#include "GPIO_CONFIG.hpp"


class Display {
  public:
    Display();
    void setup();
    void loop();
    void init();
    void set_cursor( uint8_t col, uint8_t row);
    void print(String message);
    void set_cursor_and_print(String message, uint8_t col, uint8_t row);
    void display_current_routine(short machine_routine[], short machine_routine_size, short current_routine_state_pointer);
};

extern Display display;

#endif