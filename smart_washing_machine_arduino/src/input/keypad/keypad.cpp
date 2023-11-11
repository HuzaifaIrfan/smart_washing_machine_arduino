
#include "keypad.hpp"

Keypad::Keypad(Display *display, WashingMachineController *washing_machine_controller) : display(display), washing_machine_controller(washing_machine_controller)
{
}

void Keypad::setup()
{
}

// define some values used by the panel and buttons
int lcd_key = 0;
int adc_key_in = 0;
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5

// read the buttons
int read_LCD_buttons()
{
  adc_key_in = analogRead(KEYPAD_SHIELD_INPUT_PIN); // read the value from the sensor
  // Serial.println(adc_key_in);
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1500)
    return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  if (adc_key_in < 50)
    return btnRIGHT;
  if (adc_key_in < 195)
    return btnUP;
  if (adc_key_in < 380)
    return btnDOWN;
  if (adc_key_in < 500)
    return btnLEFT;
  if (adc_key_in < 800)
    return btnSELECT;

  return btnNONE; // when all others fail, return this...
}

void Keypad::loop()
{
  //     display->set_cursor(9, 1);        // move cursor to second line "1" and 9 spaces over
  // display->print(String(millis() / 1000)); // display seconds elapsed since power-up

  display->set_cursor(9, 1);    // move to the begining of the second line
  lcd_key = read_LCD_buttons(); // read the buttons

  switch (lcd_key) // depending on which button was pushed, we perform an action
  {
  case btnSELECT:
  {
    // display->print("SELECT");
    Serial.println("Run");
    washing_machine_controller->run();
    break;
  }
  case btnLEFT:
  {
    // display->print("LEFT   ");
    Serial.println("Pause");
    washing_machine_controller->pause();
    break;
  }

  case btnUP:
  {
    // display->print("UP    ");
    Serial.println("UP");

    break;
  }
  case btnDOWN:
  {
    // display->print("DOWN  ");
    Serial.println("DOWN");

    break;
  }
  case btnRIGHT:
  {
    // display->print("RIGHT ");
    Serial.println("Reset");
    washing_machine_controller->reset();
    break;
  }

    // case btnNONE:
    // {
    //   display->print("NONE  ");
    //   break;
    // }
  }
}

Keypad keypad(&display, &washing_machine_controller);