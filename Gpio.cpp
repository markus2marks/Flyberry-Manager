#include "Gpio.h"

GPIO::GPIO(int pin, int type, void (*isrInput)(void), QObject *parent) : QObject(parent)
{
    wiringPiSetupGpio();
    m_pin = pin;
    wiringPiISR(m_pin, INT_EDGE_BOTH, isrInput);
}

void GPIO::isrCallback()
{
    emit inputChanged(digitalRead(m_pin));
}
