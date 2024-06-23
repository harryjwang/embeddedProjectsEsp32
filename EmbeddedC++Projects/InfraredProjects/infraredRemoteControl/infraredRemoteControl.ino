#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 15;
IRrecv irrecv(recvPin);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();
  while(!Serial)
    delay(50);
  Serial.println();
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin");
  Serial.print(recvPin);
}

void loop() {
  if (irrecv.decode(&results)){
    serialPrintUint64(results.value, HEX);
    Serial.println("");
    irrecv.resume();
  }
  delay(1000);
}