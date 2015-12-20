#include "Telegram.h"
#include "OutputDevice.h"
#include "Led.h"
#include "Speaker.h"

using namespace Application;
using namespace Application::Device;

const size_t outputPin = 13;
const size_t frequency = 131;
const size_t ditLenght = 200;
const size_t baudRate  = 9600;

Led led(outputPin);
Speaker speaker(outputPin, frequency);

OutputDevice *ledDevice = &led;
OutputDevice *speakerDevice = &speaker;

Telegram telegram(*speakerDevice, ditLenght);
 
void setup()
{
    Serial.begin(baudRate);
}

void loop()
{ 
    telegram.sendMessage("Hello world!");
    delay(5000);
}
