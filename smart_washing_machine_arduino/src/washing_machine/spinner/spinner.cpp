
#include "spinner.hpp"

Spinner::Spinner(PowerRelay clockwise_spinner_power_relay, PowerRelay anticlockwise_spinner_power_relay):clockwise_spinner_power_relay(clockwise_spinner_power_relay), anticlockwise_spinner_power_relay(anticlockwise_spinner_power_relay)
{
}

void Spinner::setup()
{
    clockwise_spinner_power_relay.setup();
    anticlockwise_spinner_power_relay.setup();
}

void Spinner::loop()
{
}

void Spinner::stop()
{
    clockwise_spinner_power_relay.off();
    anticlockwise_spinner_power_relay.off();
}


void Spinner::spin_clockwise()
{
    clockwise_spinner_power_relay.on();
    anticlockwise_spinner_power_relay.off();
}

void Spinner::spin_anti_clockwise()
{
    clockwise_spinner_power_relay.off();
    anticlockwise_spinner_power_relay.on();
}

void Spinner::spin_dryer()
{
    spin_clockwise();
}