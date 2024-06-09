const byte led_pins[] = {4,2,15};
const byte channels[] = {0,1,2};
int red_led, green_led, blue_led;

void setup() {
  for (int i = 0; i < 3; i++){
    ledcSetup(channels[i], 1000, 8);
    ledcAttachPin(led_pins[i], channels[i]);
  }

}

void loop() {
  red_led = random(0, 256);
  green_led = random(0, 256);
  blue_led = random(0, 256);

  displayColor(red_led, green_led, blue_led);
  delay(1000);
}

void displayColor(byte r, byte g, byte b){
  ledcWrite(channels[0], 255 - r);
  ledcWrite(channels[1], 255 - g);
  ledcWrite(channels[2], 255 - b);
}
