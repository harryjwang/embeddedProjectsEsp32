#define echo_pin 14
#define trig_pin 13
#define MAX_DISTANCE 700

float time_out = MAX_DISTANCE * 58.2;  // Time-out calculation adjusted for distance in cm
int sound_velocity = 340;  // Not needed in this calculation since pulseIn already gives time in microseconds

void setup() {
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  delay(1000);
  Serial.print("Distance: ");
  Serial.print(getSonar());
  Serial.println(" cm");
}

float getSonar() {
  unsigned long pingTime;
  float distance;
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  pingTime = pulseIn(echo_pin, HIGH, time_out);
  if (pingTime == 0) {
    return 0;  // Indicates out of range
  }
  distance = pingTime / 58.2;  // Convert time to distance
  return distance;
}