#ifndef __SPEAKER_H__
#define __SPEAKER_H__

#include "OutputDevice.h"

namespace Application {
namespace Device {

class Speaker : public OutputDevice
{
public:
    Speaker(const int outputPin,
            const int frequency);
    virtual ~Speaker();
  
public: // interface
    void outputSymbol(const int len) const;

private: // member variables
    int _frequency;
};
}  // namespace Device
}; // namespace Application

#endif

