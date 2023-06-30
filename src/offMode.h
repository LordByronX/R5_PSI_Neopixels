#ifndef OFFMODE_H
#define OFFMODE_H

#include <Adafruit_NeoPixel.h>

class OffMode {
public:
  void setActive(bool active);
  bool isActive();
  void update(Adafruit_NeoPixel& strip);

private:
  void turnOffAllPixels(Adafruit_NeoPixel& strip);
};

#endif
