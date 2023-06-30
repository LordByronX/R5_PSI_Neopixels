#ifndef CUSTOMCOLORMODE_H
#define CUSTOMCOLORMODE_H

#include <Adafruit_NeoPixel.h>

class CustomColorMode {
public:
  void setActive(bool active);
  bool isActive();
  void setColor(uint8_t r, uint8_t g, uint8_t b);
  void update(Adafruit_NeoPixel& strip);

private:
  uint8_t customR = 0;
  uint8_t customG = 0;
  uint8_t customB = 0;
};

#endif
