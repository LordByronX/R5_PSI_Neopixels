#ifndef REDMODE_H
#define REDMODE_H

#include <Adafruit_NeoPixel.h>

class RedMode {
public:
  void setActive(bool active);
  bool isActive();
  void update(Adafruit_NeoPixel& strip);

private:
  void turnOnAllPixels(Adafruit_NeoPixel& strip, uint8_t r, uint8_t g, uint8_t b);
};

#endif
