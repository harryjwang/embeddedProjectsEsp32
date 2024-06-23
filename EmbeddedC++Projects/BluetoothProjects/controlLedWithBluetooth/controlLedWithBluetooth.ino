#include "BluetoothSerial.h"
#include "string.h"
#define LED 2
BluetoothSerial SerialBT;
char buffer[20];
static int count = 0;

void setup() {
 pinMode(LED, OUTPUT);
 SerialBT.begin("ESP32test");
 Serial.begin(115200);
 Serial.println("\The device started, now you can pair it with Bluetooth! ");
}

void loop() {
  while(SerialBT.available()){
    buffer[count] = SerialBT.read();
    count++;
  }
  if(count>0){
    Serial.print(buffer);
    if(strncmp(buffer,"led_on",6)==0){
      digitalWrite(LED,HIGH);
    }
    if(strncmp(buffer,"led_off",7)==0){
      digitalWrite(LED,LOW);
    }
    count=0;
    memset(buffer,0,20);
  }
}