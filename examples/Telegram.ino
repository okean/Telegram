#include "Telegram.h"

using namespace Application;

const size_t OUTPUT_PIN = 13;
const size_t DIT_LENGHT = 200;
const size_t BAUD_RATE  = 9600;

Telegram telegram(OUTPUT_PIN, DIT_LENGHT);
 
void setup()
{
    Serial.begin(BAUD_RATE);
}

void loop()
{ 
    telegram.sendMessage("Hellow world!");
    delay(5000);
}

