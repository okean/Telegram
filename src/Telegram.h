#ifndef __TELEGRAM_H__
#define __TELEGRAM_H__

namespace Application {

class Telegram
{
 public:
     Telegram(const int outputPin,
              const int ditLength);
     ~Telegram();

 public: // interface
    void sendMessage(const char* message) const;

 private: // internal helpers
    void outputCode(const char* code) const;
    void outputSymbol(const int len) const;
    void dit() const;
    void dah() const;   

 private: // member variables
     int _outputPin;
     int _ditLength;
     int _dahLength;
};
}; // namespace Application

#endif

