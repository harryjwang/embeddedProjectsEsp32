#define PIN_LED 2
// the setup function runs once when you press reset or power the board
void setup() {
 // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_LED, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(5000); // wait for a second
  digitalWrite(PIN_LED, LOW); // turn the LED off by making the voltage LOW
  delay(1000);
}