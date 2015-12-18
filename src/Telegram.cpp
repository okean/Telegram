#include "Telegram.h"
#include <Arduino.h>
#include <ctype.h>

using namespace Application;

namespace
{
    const char* letters[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    // A-E
    "..-.", "--.",  "....", "..",   ".---", // F-J
    "-.-",  ".-..", "--",   "-.",   "---",  // K-O
    ".--.", "--.-", ".-.",  "...",  "-",    // P-T
    "..-",  "...-", ".--",  "-..-", "-.--", // U-Y
    "--.."                                  // Z
    };

    const char* digits[] = {
    "-----", ".----", "..---", "...--", // 0-3
    "....-", ".....", "-....", "--...", // 4-7
    "---..", "----."                    // 8-9
    };
}

Telegram::Telegram(const int outputPin, const int ditLength)
    : _outputPin(outputPin)
    , _ditLength(ditLength)
    , _dahLength(ditLength * 3)
{
    pinMode(outputPin, OUTPUT);
}

Telegram::~Telegram()
{
}

// interface

void Telegram::sendMessage(const char* message) const
{
    for(size_t i = 0; i < strlen(message); i++)
    {
        const char ch = toupper(message[i]);

         if(isalpha(ch))
         {
             outputCode(letters[ch - 'A']);
             delay(_dahLength);
         }
         else if(isdigit(ch))
         {
             outputCode(digits[ch - '0']);
             delay(_dahLength);
         }
         else if(ch == ' ')
         {
             Serial.print(" ");
             delay(_ditLength * 7);
         }
    }
    Serial.println();
}

// internal helpers

void Telegram::outputCode(const char* code) const
{
    for(size_t i = 0; i < strlen(code); i++)
    {
        if(code[i] == '.')
        {
            dit();
        }
        else
        {
            dah();
        }
    }
}

void Telegram::outputSymbol(const int len) const
{
    digitalWrite(_outputPin, HIGH);
    delay(len);
    digitalWrite(_outputPin, LOW);
}

void Telegram::dit() const
{
    Serial.print('.');
    outputSymbol(_ditLength);  
}

void Telegram::dah() const
{
    Serial.print('-');
    outputSymbol(_dahLength);  
}

