byte led_pins[] = {15, 2, 0, 4, 5, 18, 19, 21, 22, 23};
int led_count;

void setup() {
  // put your setup code here, to run once:
  led_count = sizeof(led_pins);
  for (int i; i < led_count; i++){
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int led_num = 0; led_num < led_count; led_num++){
    digitalWrite(led_pins[led_num], HIGH);
    delay(100);
    digitalWrite(led_pins[led_num], LOW);
  }
  
  for (int led_num = led_count - 1; led_num >=  0; led_num--){
    digitalWrite(led_pins[led_num], HIGH);
    delay(100);
    digitalWrite(led_pins[led_num], LOW);
  }
}
