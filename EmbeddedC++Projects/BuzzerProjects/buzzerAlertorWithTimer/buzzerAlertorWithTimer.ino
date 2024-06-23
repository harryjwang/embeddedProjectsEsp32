#define BUZZER_PIN 13
#define PIN_BUTTON 4
hw_timer_t * timer = NULL;  // initializing timer
bool isAlerting = false;    // initialize that the imter isn't alerting to start

void IRAM_ATTR onTimer() {
  digitalWrite(BUZZER_PIN, !digitalRead(BUZZER_PIN));    // write to the buzzer pin the opposite of the value from the buzzer pin
}

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  // Use 1st timer of 4 (counted from zero).
  // Set 80 divider for prescaler (see ESP32 Technical Reference Manual for more info).
  timer = timerBegin(0, 80, true);
  // Attach onTimer function to our timer.
  timerAttachInterrupt(timer, &onTimer, true);
}

void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {     // if button is pressed
    if (!isAlerting) {                      // if the button isn't alerting, set the button to start alerting
      isAlerting = true;
      timerAlarmWrite(timer, 1000, true);   // Set alarm, 1ms, repeat
      timerAlarmEnable(timer);              // Start an alarm
    }
    alert();                                // sound the button with sin wave path
  } else {
    if (isAlerting) {                       // if the button is already alerting
      isAlerting = false;                   // turn the alerting of the button off
      timerAlarmDisable(timer);             // turn the alarm off
      digitalWrite(BUZZER_PIN, LOW);        // write to the buzzer to turn sound off of the buzzer
    }
  }
}

void alert() {      // creates a sinusoidal wave of sound and outputs it
  float sinVal;
  int toneVal;
  for (int x = 0; x < 360; x += 1) {
    sinVal = sin(x * (PI / 180));
    toneVal = 2000 + sinVal * 500;
    timerAlarmWrite(timer, 500000 / toneVal, true);
    delay(1);
  }
}