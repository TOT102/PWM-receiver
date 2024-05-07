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

void begin(){
  for (int i = 0; i < numChannels; i++){
    pinMode(pins[i], INPUT);
  }
}

void PWMReceiver::readData() {
  for (size_t pin = 0; pin < numChannels; pin++) {
    unsigned long pulseWidthHigh = pulseIn(pin, HIGH);
    unsigned long pulseWidthLow = pulseIn(pin, LOW);
    unsigned long period = pulseWidthHigh + pulseWidthLow;

    if (period == 0) {
       channelData[pin] = 0;
    } else {
      double dutyCycle = (double)pulseWidthHigh / (double)period * 100.0;
       channelData[pin] = dutyCycle;
    }
    /*
    int rawValue = analogRead(pins[i]); 
    channelData[i] = map(rawValue, 0, 1023, 0, 100);*/
  }
}

int PWMReceiver::getChannel(int channel) {
  if (channel >= 0 && channel < numChannels) {
    return channelData[channel];
  } else {
    return 0;
  }
}
