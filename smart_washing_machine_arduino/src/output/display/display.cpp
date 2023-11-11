
#include "display.hpp"

LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D0_PIN, LCD_D1_PIN, LCD_D2_PIN, LCD_D3_PIN);

Display::Display()
{
}

void Display::setup()
{
    init();
    set_cursor_and_print("Smart Washer", 0, 0);
    set_cursor_and_print("Huzaifa Irfan", 0, 1);
}

void Display::init()
{
    lcd.begin(16, 2);
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

Display display;