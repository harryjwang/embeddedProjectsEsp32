const byte LEDPINS[] = {12, 27, 14};
const byte CHANNELS[] = {0, 1, 2};
const byte ADC_PINS[] = {4, 0, 15};
int color[] = {0, 0, 0};

void setup() {
  for(int i = 0; i < 3; i++){
    ledcSetup(CHANNELS[i], 1000, 8);
    ledcAttachPin(LEDPINS[i], CHANNELS[i]);
  }
}

void loop() {
  for(int i = 0; i < 3; i++){
    color[i] = map(analogRead(ADC_PINS[i]), 0, 4096, 0, 255);
    ledcWrite(CHANNELS[i], 256 - color[i]);
  }
  delay(10);
}