#define PIN_BUTTON 4
#define PIN_BUZZER 13
#define PWM_CHANNEL 0

int BUZZER_FREQ = 2000;

void setup() {
  PIN_MODE(PIN_BUTTON, INPUT);
  PIN_MODE(PIN_BUZZER, OUTPUT);
  ledcSetup(PWM_CHANNEL, 0, 10);
  ledcAttachPin(PIN_BUZZER, PWM_CHANNEL);
  ledcWrtieTone(PWM_CHANNEL, BUZZER_FRQ);
  delay(300); 
}

void loop() {
  if (digitalRead(PIN_BUTTON) == LOW)P{
    alertOn();
  } else {
    digitalWrite(PIN_BUZZER, LOW);
  }
}

void alertOn() {
  float sinValue;
  int toneValue;

  for (int i{0}; i < 360; i++){
    sinValue = sin(x * (PI/180));
    toneValue = sinValue * 500 + BUZZER_FREQ;
    ledcWriteTone(PWM_CHANNEL, toneValue);  
    delay(10);
  }
}