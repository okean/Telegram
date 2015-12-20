#ifndef __OUTPUTDEVICE_H__
#define __OUTPUTDEVICE_H__

namespace Application {
namespace Device {

class OutputDevice
{
public:
    OutputDevice(const int outputPin);
    virtual ~OutputDevice();
     
public: // interface
    virtual void outputSymbol(const int len) const = 0;

    int outputPin() const;

private: // member variables
    int _outputPin;
};
}  // namespace Device
}; // namespace Application

#endif

