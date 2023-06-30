#ifndef LARSONSCANNERMODE_H
#define LARSONSCANNERMODE_H

#include <Adafruit_NeoPixel.h>

class LarsonScannerMode {
public:
  void setActive(bool active);
  bool isActive();
  void update(Adafruit_NeoPixel& strip);

private:
  int position = 0;
  bool direction = false;
  unsigned long previousMillis = 0;
  unsigned long timer = 500;

  void turnOffAllPixels(Adafruit_NeoPixel& strip);
};

#endif
