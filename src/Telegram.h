#ifndef __TELEGRAM_H__
#define __TELEGRAM_H__

#include "OutputDevice.h"

namespace Application {

typedef Device::OutputDevice OutDevice;

class Telegram
{
 public:
     Telegram(OutDevice &device,
              const int ditLength);
     ~Telegram();

 public: // interface
    void sendMessage(const char* message) const;

 private: // internal helpers
    void outputCode(const char* code) const;
    void dit() const;
    void dah() const;   

 private: // member variables
     OutDevice &_device;
     int     _ditLength;
     int     _dahLength;
};
}; // namespace Application

#endif

