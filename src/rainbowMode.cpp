#include "rainbowMode.h"

void RainbowMode::setActive(bool active) {
  if (active) {
    // Initialize mode-specific variables here
    previousMillis = 0;
  }
  // Handle any cleanup when mode is deactivated
}

bool RainbowMode::isActive() {
  // Return the active status of the mode
  // Implement this based on your preference or requirements
  return false;
}

void RainbowMode::update(Adafruit_NeoPixel& strip, uint8_t& hue) {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    hue++;  // Increment the hue value for rainbow sequence
    rainbowCycle(strip, hue);
  }
}

void RainbowMode::rainbowCycle(Adafruit_NeoPixel& strip, uint8_t hue) {
  for (int i = 0; i < strip.numPixels(); i++) {
    // Offset pixel hue by an index to create a moving rainbow pattern
    uint16_t pixelHue = (hue + i) % 256;
    strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
  }
  strip.show();
}
