#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 15;
IRrecv irrecv(recvPin);
decode_results results;
int ledPin = 14;
int buzzerPin = 13;

void setup() {
  ledcSetup(0,1000,8);
  ledcAttachPin(ledPin,0); 
  pinMode(buzzerPin, OUTPUT); 
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    handleControl(results.value); 
    irrecv.resume(); 
  }
}

void handleControl(unsigned long value) {

  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);

  switch (value) {
    case 0xFF6897:
      ledcWrite(0, 0);
      break;
    case 0xFF30CF: 
      ledcWrite(0, 7); 
      break;
    case 0xFF18E7: 
      ledcWrite(0, 63); 
      break;
    case 0xFF7A85: 
      ledcWrite(0, 255); 
      break;
  }
}
