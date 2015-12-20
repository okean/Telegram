#include "Speaker.h"
#include "OutputDevice.h"
#include <Arduino.h>

using namespace Application::Device;

Speaker::Speaker(const int outputPin, const int frequency)
    : OutputDevice(outputPin)
    , _frequency(frequency)
{
}

Speaker::~Speaker()
{
}

void Speaker::outputSymbol(const int len) const
{
    tone(outputPin(), _frequency, len);
}

