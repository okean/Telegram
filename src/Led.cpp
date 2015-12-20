#include "Led.h"
#include "OutputDevice.h"
#include <Arduino.h>

using namespace Application::Device;

Led::Led(const int outputPin)
    : OutputDevice(outputPin)
{
}

Led::~Led()
{
}

void Led::outputSymbol(const int len) const
{
    digitalWrite(outputPin(), HIGH);
    delay(len);
    digitalWrite(outputPin(), LOW);
}

