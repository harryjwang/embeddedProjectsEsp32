#define PIN_LED     2         // Pin for output of LED
#define PIN_BUTTON  13        // Pin for input Push button

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
  if (digitalRead(PIN_BUTTON) == LOW){        // if button is pressed
    digitalWrite(PIN_LED, HIGH);              // LED turns on
  } else {                                    // if button isn't pressed
    digitalWrite(PIN_LED, LOW);               // LED stays off
  }
}
