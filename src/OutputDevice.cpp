#include "OutputDevice.h"
#include <Arduino.h>

using namespace Application::Device;

OutputDevice::OutputDevice(const int outputPin)
    : _outputPin(outputPin)
{
    pinMode(outputPin, OUTPUT);
}

OutputDevice::~OutputDevice()
{
}

// interface

int OutputDevice::outputPin() const
{
    return _outputPin;  
}

