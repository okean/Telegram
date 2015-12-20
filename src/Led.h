#ifndef __LED_H__
#define __LED_H__

#include "OutputDevice.h"

namespace Application {
namespace Device {

class Led : public OutputDevice
{
public:
    Led(const int outputPin);
    virtual ~Led();
  
public: // interface
    void outputSymbol(const int len) const;
};
}  // namespace Device
}; // namespace Application

#endif
