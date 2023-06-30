#include "larsonScannerMode.h"

void LarsonScannerMode::setActive(bool active) {
  if (active) {
    // Initialize mode-specific variables here
    position = 0;
    direction = false;
    previousMillis = 0;
  }
  // Handle any cleanup when mode is deactivated
}

bool LarsonScannerMode::isActive() {
  // Return the active status of the mode
  // Implement this based on your preference or requirements
  return false;
}

void LarsonScannerMode::update(Adafruit_NeoPixel& strip) {
  unsigned long currentMillis = millis();

  // Check if it's time to update the position
  if (currentMillis - previousMillis >= timer) {
    previousMillis = currentMillis;

    // Turn off all LEDs
    turnOffAllPixels(strip);

    // Set the current position LED to red
    strip.setPixelColor(position, 255, 0, 0);
    strip.show();

    // Update the position based on the direction
    if (direction) {
      position--;
      if (position < 0) {
        direction = false;
        position = 1;  // Set position to 1 to ensure only red is displayed
      }
    } else {
      position++;
      if (position >= strip.numPixels()) {
        direction = true;
        position = strip.numPixels() - 2;  // Set position to numPixels - 2 to ensure only red is displayed
      }
    }
  }
}

void LarsonScannerMode::turnOffAllPixels(Adafruit_NeoPixel& strip) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}
