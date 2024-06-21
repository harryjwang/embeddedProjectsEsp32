int output_ports[] = {14, 27, 26, 25};

void setup() {
  for (int i = 0; i < 4; i++){
    pinMode(output_ports[i], OUTPUT);
  }
}

void loop() {
  moveSteps(true, 32 * 64, 3);
  delay(1000);
  moveSteps(false, 32 * 64, 3);
  delay(1000);
}

void moveSteps(bool dir, int steps, byte ms) {
  for (unsigned long i = 0; i < steps; i++) {
    moveOneStep(dir); // Rotate a step
    delay(constrain(ms,3,20)); // Control the speed
  }
}
void moveOneStep(bool dir) {
 // Define a variable, use four low bit to indicate the state of port
  static byte out = 0x01;
  // Decide the shift direction according to the rotation direction
  if (dir) { // ring shift left
    out != 0x08 ? out = out << 1 : out = 0x01;
  } else { 
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  // Output singal to each port
  for (int i = 0; i < 4; i++) {
    digitalWrite(output_ports[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

void moveAround(bool dir, int turns, byte ms){
  for(int i=0;i<turns;i++)
    moveSteps(dir,32*64,ms);
  }

void moveAngle(bool dir, int angle, byte ms){
  moveSteps(dir,(angle*32*64/360),ms);
}
