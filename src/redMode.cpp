#include "redMode.h"

void RedMode::setActive(bool active) {
  if (active) {
    // Initialize mode-specific variables here
    // No variables to initialize in this mode
  }
  // Handle any cleanup when mode is deactivated
}

bool RedMode::isActive() {
  // Return the active status of the mode
  // Implement this based on your preference or requirements
  return false;
}

void RedMode::update(Adafruit_NeoPixel& strip) {
  turnOnAllPixels(strip, 255, 0, 0);
}

void RedMode::turnOnAllPixels(Adafruit_NeoPixel& strip, uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, r, g, b);
  }
  strip.show();
}
