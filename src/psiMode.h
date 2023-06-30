#ifndef PSIMODE_H
#define PSIMODE_H

#include <Adafruit_NeoPixel.h>

class PSIMode {
public:
  void setActive(bool active);
  bool isActive();
  void update(Adafruit_NeoPixel& strip);

private:
  unsigned long previousTime = 0;
  int step = 0;
  bool isRed = true;

  void switchLEDsColor(Adafruit_NeoPixel& strip, uint8_t r, uint8_t g, uint8_t b);
  void flashLED0(Adafruit_NeoPixel& strip);
};

#endif
