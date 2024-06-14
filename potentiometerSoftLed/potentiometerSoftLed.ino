#define LED_PIN 27
#define CHANNEL 0
#define ADC_PIN 4

void setup() {
  ledcSetup(CHANNEL, 1000, 12);
  ledcAttachPin(LED_PIN, CHANNEL);
}

void loop() {
  int adcValue = analogRead(ADC_PIN);
  int PWMValue = adcValue;
  ledcWrite(CHANNEL, PWMValue);
  delay(10);
}