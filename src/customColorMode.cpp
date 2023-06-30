#include "customColorMode.h"

void CustomColorMode::setActive(bool active) {
  if (active) {
    // Initialize mode-specific variables here
    // No variables to initialize in this mode
  }
  // Handle any cleanup when mode is deactivated
}

bool CustomColorMode::isActive() {
  // Return the active status of the mode
  // Implement this based on your preference or requirements
  return false;
}

void CustomColorMode::setColor(uint8_t r, uint8_t g, uint8_t b) {
  customR = r;
  customG = g;
  customB = b;
}

void CustomColorMode::update(Adafruit_NeoPixel& strip) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, customR, customG, customB);
  }
  strip.show();
}
