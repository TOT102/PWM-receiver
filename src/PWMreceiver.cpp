#include "PWMreceiver.h"

PWMReceiver::PWMReceiver(const int pinNumbers[], size_t numPins) : numChannels(numPins) {
  pins = new int[numChannels];
  channelData = new int[numChannels];
  for (size_t i = 0; i < numChannels; i++) {
    pins[i] = pinNumbers[i];
    channelData[i] = 0;
  }
}

PWMReceiver::~PWMReceiver() {
  delete[] pins;
  delete[] channelData;
}

void PWMReceiver::readData() {
  for (size_t i = 0; i < numChannels; i++) {
    int rawValue = analogRead(pins[i]); 
    channelData[i] = map(rawValue, 0, 1023, 0, 100);
  }
}

int PWMReceiver::getChannel(int channel) {
  if (channel >= 0 && channel < numChannels) {
    return channelData[channel];
  } else {
    return 0;
  }
}
