int xyzPins[] = {14, 12, 13};
int xValue, yValue, zValue;

void setup() {
  Serial.begin(115200);
  pinMode(xyzPins[2], INPUT_PULLUP);  // Have to do this b/c z axis is represented by a button
}

void loop() {
  xValue = analogRead(xyzPins[0]);
  yValue = analogRead(xyzPins[1]);
  zValue = analogRead(xyzPins[2]);
  Serial.printf("X,Y,Z: %d, \t%d, \t%d,\n", xValue, yValue, zValue);
  delay(500);
}