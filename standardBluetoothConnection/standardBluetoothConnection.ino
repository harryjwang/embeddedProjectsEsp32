#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
String buffer;
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32 Test");
  Serial.println("\nThe Device has started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()){
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()){
    Serial.write(SerialBT.read());
  }
  delay(20);
}