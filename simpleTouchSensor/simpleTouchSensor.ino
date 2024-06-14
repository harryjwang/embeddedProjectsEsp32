void setup () {
  Serial.begin(115200);
}

void loop () {
  Serial.printf("Touch Value: %d \n", touchRead(T0));
  delay(1000);
}