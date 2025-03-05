int latch_pin = 12;
int data_pin = 13;
int clock_pin = 14;
int common_pins[] = {4, 0, 2, 15};

byte num[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};

void setup() {
  pinMode(latch_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);




  
  for(int i = 0; i < 4; i++){
    pinMode(common_pins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++){
    singleDisplay(i);
    writeData(num[i]);
    delay(5);
    writeData(0xff);
  }
}

void singleDisplay(byte com){
  for (int i = 0; i < 4; i++){
    digitalWrite(common_pins[i], LOW);
  }
  digitalWrite(common_pins[com], HIGH);
}

void writeData(int value){
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, value);
  digitalWrite(latch_pin, HIGH);
} 