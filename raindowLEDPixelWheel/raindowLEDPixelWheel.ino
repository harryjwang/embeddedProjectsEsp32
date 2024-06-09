#include "Freenove_WS2812_Lib_for_ESP32.h"
#define LEDS_COUNT 8 // The number of led
#define LEDS_PIN 4 // define the pin connected to the Freenove 8 led strip
#define CHANNEL 0 // RMT channel

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
  strip.begin();
  strip.setBrightness(5);
}

void loop() {
  for (int j = 0; j < 255; j += 1) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));
    }
    strip.show(); // Send color data to LED, and display.
    delay(5);
  }
}