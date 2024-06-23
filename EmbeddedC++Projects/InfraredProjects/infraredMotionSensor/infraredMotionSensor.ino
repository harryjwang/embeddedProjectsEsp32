int sensor_pin = 14;
int led_pin = 13;

void setup() {
  pinMode(sensor_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  digitalWrite(led_pin, digitalRead(sensor_pin));
  delay(1000);
}