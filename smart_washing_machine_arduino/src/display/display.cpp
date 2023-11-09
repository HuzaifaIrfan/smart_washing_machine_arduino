
#include "display.hpp"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

Display::Display()
{
}

void Display::setup()
{
    lcd.begin(16, 2);
    set_cursor_and_print("Press the button", 0, 0);
}

void Display::loop()
{
}

void Display::set_cursor(uint8_t col, uint8_t row)
{
    lcd.setCursor(col, row);
}

void Display::print(String message)
{
    lcd.print(message);
}

void Display::set_cursor_and_print(String message, uint8_t col, uint8_t row)
{
    set_cursor(col, row);
    print(message);
}