#define PIN_LED   2
#define PRESS_VAL 14	//Set a threshold to judge touch
#define RELEASE_VAL 25	//Set a threshold to judge release

bool isProcessed = false;
void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
}
void loop() {
  if (touchRead(T0) < PRESS_VAL) {      // if the value of the touch sensor is less than 14 (sensor is pressed)
    if (!isProcessed) {                 // and if the led is processed, set it to processed and then reverse the GPIO (turn on the LED)
      isProcessed = true;
      Serial.println("Touch detected! ");
      reverseGPIO(PIN_LED);
    }
  }

  if (touchRead(T0) > RELEASE_VAL) {      // once the value of the touch sensor is greater than 25 (not touched anymore)
    if (isProcessed) {                    // if the led has been processed, set it back to led not processed to repeat the steps and reverse the GPIO again the next cycle
      isProcessed = false;
      Serial.println("Released! ");
    }
  }
}

void reverseGPIO(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}
