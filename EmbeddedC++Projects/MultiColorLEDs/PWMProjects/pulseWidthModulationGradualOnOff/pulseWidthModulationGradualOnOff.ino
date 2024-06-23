#include <Arduino.h>
#include <esp32-hal-ledc.h>

#define PIN_LED   2    // Define the LED pin
#define CHN       0    // Define the PWM channel
#define FRQ       1000 // Define the PWM frequency
#define PWM_BIT   8    // Define the PWM resolution (8-bit)

void setup() {
  // Setup the PWM channel
  ledcSetup(CHN, FRQ, PWM_BIT);
  // Attach the LED pin to the PWM channel
  ledcAttachPin(PIN_LED, CHN);
}

void loop() {
  // Fade in the LED
  for (int i = 0; i < 255; i++) {
    ledcWrite(CHN, i);
    delay(10);
  }
  // Fade out the LED
  for (int i = 255; i > -1; i--) {
    ledcWrite(CHN, i);
    delay(10);
  }
}