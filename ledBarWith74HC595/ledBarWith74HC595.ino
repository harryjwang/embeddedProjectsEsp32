int latch_pin = 12;
int clock_pin = 13;
int data_pin = 14;

void setup() {
  pinMode(latch_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
}

void loop() {
  byte x = 0x01;
  for (int i = 0; i < 8; i++){
    write_to_595(LSBFIRST, x);
    x <<= 1;
    delay(50);
  }
  delay(1000);

  x = 0x80;
  for (int i = 0; i < 8; i++){
    write_to_595(LSBFIRST, x);
    x >>= 1;
    delay(50);
  }
  delay(1000);
}

void write_to_595(int order, byte _data){
  digitalWrite(latch_pin, LOW);                           // ouput low level to the latch pin (disables parallel output)
  shiftOut(data_pin, clock_pin, order, _data);            // sends serial data to the 74HC595
  digitalWrite(latch_pin, HIGH);                          // output high level to the latch pin (enables paralle output)
}