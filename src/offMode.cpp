#include "offMode.h"

void OffMode::setActive(bool active) {
  if (active) {
    // Initialize mode-specific variables here
    // No variables to initialize in this mode
  }
  // Handle any cleanup when mode is deactivated
}

bool OffMode::isActive() {
  // Return the active status of the mode
  // Implement this based on your preference or requirements
  return false;
}

void OffMode::update(Adafruit_NeoPixel& strip) {
  turnOffAllPixels(strip);
}

void OffMode::turnOffAllPixels(Adafruit_NeoPixel& strip) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}
