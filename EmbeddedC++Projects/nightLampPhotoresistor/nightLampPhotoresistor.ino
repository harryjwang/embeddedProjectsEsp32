#define ADC_PIN 2
#define LED_PIN 13
#define PWM_CHANNEL 0
#define MAX_LIGHT 2048
#define MIN_LIGHT 372

void setup() {
  ledcSetup(PWM_CHANNEL, 1000, 12);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);
}

void loop() {
  int adcVal = analogRead(ADC_PIN);
  int pwmVal = map(constrain(adcVal, MIN_LIGHT, MAX_LIGHT), MIN_LIGHT, MAX_LIGHT, 0, 4095);
  ledcWrite(PWM_CHANNEL, pwmVal);
  delay(10);
}