#ifndef RAINBOWMODE_H
#define RAINBOWMODE_H

#include <Adafruit_NeoPixel.h>

class RainbowMode {
public:
  void setActive(bool active);
  bool isActive();
  void update(Adafruit_NeoPixel& strip, uint8_t& hue);

private:
  unsigned long previousMillis = 0;
  unsigned long interval = 3000;

  void rainbowCycle(Adafruit_NeoPixel& strip, uint8_t hue);
};

#endif
