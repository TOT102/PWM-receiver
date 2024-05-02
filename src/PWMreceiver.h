#ifndef PWMReceiver_h
#define PWMReceiver_h

#include "Arduino.h"

class PWMReceiver {
  private:
    int* channelData;
    int* pins;
    size_t numChannels;

  public:
    PWMReceiver(const int pinNumbers[], size_t numPins);
    ~PWMReceiver();
    void readData();
    int getChannel(int channel);
};

#endif
