#include <MPU6050_tockn.h>
#include <Wire.h>

#define SDA 13
#define SCL 14

MPU6050 mpu6050(Wire);

int16_t ax,ay,az;
int16_t gx,gy,gz;
long timer = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA, SCL); 
  mpu6050.begin(); 
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  if(millis() - timer > 1000){ 
    mpu6050.update();getMotion6();
    Serial.print("\na/g:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.print("\t");
    Serial.print(gx); Serial.print("\t\t");
    Serial.print(gy); Serial.print("\t\t");
    Serial.println(gz);
    Serial.print("a/g:\t");
    Serial.print((float)ax / 16384); Serial.print("g\t");
    Serial.print((float)ay / 16384); Serial.print("g\t");
    Serial.print((float)az / 16384); Serial.print("g\t");
    Serial.print((float)gx / 131); Serial.print("d/s \t");
    Serial.print((float)gy / 131); Serial.print("d/s \t");
    Serial.print((float)gz / 131); Serial.print("d/s \n");
    timer = millis();
  }
}

void getMotion6(void){
  ax=mpu6050.getRawAccX();
  ay=mpu6050.getRawAccY();
  az=mpu6050.getRawAccZ();
  gx=mpu6050.getRawGyroX();
  gy=mpu6050.getRawGyroX();
  gz=mpu6050.getRawGyroX();
}