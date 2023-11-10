
#include "power_relay.hpp"

PowerRelay::PowerRelay(short pin) : pin(pin)
{
}

void PowerRelay::setup()
{
    pinMode(pin, OUTPUT);
    off();
}

void PowerRelay::loop()
{
}

void PowerRelay::on()
{
    digitalWrite(pin, HIGH);
}

void PowerRelay::off()
{
    digitalWrite(pin, LOW);
}
