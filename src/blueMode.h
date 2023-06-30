#ifndef BLUEMODE_H
#define BLUEMODE_H

#include <Adafruit_NeoPixel.h>

class BlueMode {
public:
  void setActive(bool active);
  bool isActive();
  void update(Adafruit_NeoPixel& strip);

private:
  void turnOnAllPixels(Adafruit_NeoPixel& strip, uint8_t r, uint8_t g, uint8_t b);
};

#endif
