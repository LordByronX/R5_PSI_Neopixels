#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "larsonScannerMode.h"
#include "psiMode.h"
#include "customColorMode.h"
#include "rainbowMode.h"
#include "blueMode.h"
#include "redMode.h"
#include "offMode.h"

// Constants
#define LED_PIN D6      // Pin connected to the data input of WS2812B LEDs
#define NUM_LEDS 4      // Number of LEDs in the strip

// Create NeoPixel object
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Web server object
ESP8266WebServer server(80);

// Variables
unsigned long interval = 3000;     // Interval between color changes (in milliseconds)
uint8_t hue = 0;                   // Hue value for rainbow sequence

LarsonScannerMode larsonScannerMode;
PSIMode psiMode;
CustomColorMode customColorMode;
RainbowMode rainbowMode;
BlueMode blueMode;
RedMode redMode;
OffMode offMode;

// Function prototypes
void handleMode();
void handleCustomColor();

void setup() {
  strip.begin();
  strip.show();   // Initialize all pixels to off

  WiFi.begin("lazyfoxfarms_2G", "07312010");   // Replace with your network credentials
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.on("/", []() {
    String html = "<html><body>";
    html += "<h1>LED Strip Control</h1>";
    html += "<form action='/mode'>";
    html += "<input type='radio' name='mode' value='off'>Off<br>";
    html += "<input type='radio' name='mode' value='rainbow'>Rainbow<br>";
    html += "<input type='radio' name='mode' value='larson'>Larson Scanner<br>";
    html += "<input type='radio' name='mode' value='psi'>PSI<br>";
    html += "<input type='radio' name='mode' value='custom'>Custom Color<br>";
    html += "<input type='radio' name='mode' value='blue'>Blue<br>";
    html += "<input type='radio' name='mode' value='red'>Red<br>";
    html += "<br>";
    html += "<input type='submit' value='Set Mode'>";
    html += "</form>";
    html += "<br><br>";
    html += "<form action='/customcolor'>";
    html += "R: <input type='number' name='r' min='0' max='255'><br>";
    html += "G: <input type='number' name='g' min='0' max='255'><br>";
    html += "B: <input type='number' name='b' min='0' max='255'><br>";
    html += "<input type='submit' value='Set Color'>";
    html += "</form>";
    html += "</body></html>";

    server.send(200, "text/html", html);
  });

  server.on("/mode", handleMode);
  server.on("/customcolor", handleCustomColor);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();

  if (rainbowMode.isActive()) {
    rainbowMode.update(strip, hue);
  } else if (larsonScannerMode.isActive()) {
    larsonScannerMode.update(strip);
  } else if (psiMode.isActive()) {
    psiMode.update(strip);
  } else if (customColorMode.isActive()) {
    customColorMode.update(strip);
  } else if (blueMode.isActive()) {
    blueMode.update(strip);
  } else if (redMode.isActive()) {
    redMode.update(strip);
  } else {
    offMode.update(strip);
  }
}

void handleMode() {
  String mode = server.arg("mode");

  rainbowMode.setActive(false);
  larsonScannerMode.setActive(false);
  psiMode.setActive(false);
  customColorMode.setActive(false);
  blueMode.setActive(false);
  redMode.setActive(false);
  offMode.setActive(false);

  if (mode == "off") {
    offMode.setActive(true);
  } else if (mode == "rainbow") {
    rainbowMode.setActive(true);
  } else if (mode == "larson") {
    larsonScannerMode.setActive(true);
  } else if (mode == "psi") {
    psiMode.setActive(true);
  } else if (mode == "custom") {
    customColorMode.setActive(true);
  } else if (mode == "blue") {
    blueMode.setActive(true);
  } else if (mode == "red") {
    redMode.setActive(true);
  }

  server.sendHeader("Location", "/");
  server.send(303);
}

void handleCustomColor() {
  customColorMode.setColor(
    server.arg("r").toInt(),
    server.arg("g").toInt(),
    server.arg("b").toInt()
  );

  server.sendHeader("Location", "/");
  server.send(303);
}
