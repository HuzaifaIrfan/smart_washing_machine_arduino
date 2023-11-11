
#include "buzzer.hpp"

Buzzer::Buzzer(short pin) : pin(pin)
{
}

void Buzzer::setup()
{
    pinMode(pin, OUTPUT);
}

void Buzzer::loop()
{
    if (buzz)
    {
        if (buzNow)
        {
            digitalWrite(pin, HIGH);
            beepCount = beepCount + 1;
            if (beepCount >= beepCountSet)
            {
                buzz = false;
            }
        }
        else
        {
            digitalWrite(pin, LOW);
        }
        buzNow = not buzNow;
    }
    else
    {
        digitalWrite(pin, LOW);
    }
}

bool Buzzer::set(short beepCountSetValue)
{
    if (not buzz)
    {
        buzz = true;
        beepCountSet = beepCountSetValue;
        beepCount = 0;
        return true;
    }
    return false;
}

void Buzzer::test()
{
    buzz = true;
}

void Buzzer::off()
{
    buzz = false;
}

Buzzer buzzer(BUZZER_OUTPUT_PIN);