#include <DHTesp.h>

DHTesp dht;
int dhtpin = 13;

void setup() {
  Serial.begin(115200);
  dht.setup(dhtpin, DHTesp::DHT11);
}

void loop() {
  flag:TempAndHumidity newValues = dht.getTempAndHumidity();
  if (dht.getStatus() != 0){
    goto flag;
  }
  Serial.println("Temperature:" + String(newValues.temperature) + " Humidity: " + String(newValues.humidity));
  delay(2000);
}
