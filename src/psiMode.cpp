#include "psiMode.h"

void PSIMode::setActive(bool active) {
  if (active) {
    // Initialize mode-specific variables here
    previousTime = 0;
    step = 0;
    isRed = true;
  }
  // Handle any cleanup when mode is deactivated
}

bool PSIMode::isActive() {
  // Return the active status of the mode
  // Implement this based on your preference or requirements
  return false;
}

void PSIMode::update(Adafruit_NeoPixel& strip) {
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - previousTime;

  if (elapsedTime >= 1000) {
    previousTime = currentTime;

    if (step == 0) {
      if (isRed) {
        switchLEDsColor(strip, 255, 0, 0);    // LED #2, #3, #4: Red
        isRed = false;
      } else {
        switchLEDsColor(strip, 0, 0, 255);    // LED #2, #3, #4: Blue
        isRed = true;
      }
      step++;
    } else if (step == 1) {
      flashLED0(strip);
      step = 0;
    }
  }
}

void PSIMode::switchLEDsColor(Adafruit_NeoPixel& strip, uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 2; i <= 4; i++) {
    strip.setPixelColor(i, r, g, b);
  }
  strip.show();
}

void PSIMode::flashLED0(Adafruit_NeoPixel& strip) {
  strip.setPixelColor(0, random(256), random(256), random(256));
  strip.show();
  delay(10);  // Flash LED 0 for 10 milliseconds
  strip.setPixelColor(0, 0, 0, 0);
  strip.show();
}
