#include <UltrasonicSensor.h>

UltrasonicSensor ultrasonic(13,14);

void setup() {
  Serial.begin(115200);
  int temperature = 22;
  ultrasonic.setTemperature(temperature);
}

void loop() {
  float distance = ultrasonic.distanceInCentimeters();
  Serial.printf("Distance: %dcm\n", distance);
  delay(300);
}