
#include "buttons.hpp"

Buttons::Buttons(ezButton hold_skip_input_button) : hold_skip_input_button(hold_skip_input_button)
{
}

void Buttons::setup()
{
    hold_skip_input_button.setDebounceTime(100);
}

void Buttons::loop()
{
    hold_skip_input_button.loop();
    check();
}

void Buttons::check()
{

    if (hold_skip_input_button.isPressed())
    {

    }
    if (hold_skip_input_button.isReleased())
    {
        
    }
}

ezButton hold_skip_input_button(HOLD_SKIP_INPUT_PIN);

Buttons buttons(hold_skip_input_button);