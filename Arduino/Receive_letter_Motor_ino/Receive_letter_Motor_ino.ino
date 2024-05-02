#include "PCA9685.h"
#include <Wire.h>
#include "ISL_Servo_Library.h"

void setup() {
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();
  servo.init(0x7f);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    Serial.println(incomingByte);

    if (incomingByte == 'A') {
      isl_a();
      delay(2000);
    } 
    if (incomingByte == 'B' ) {
      isl_b();
      delay(2000);
    }
    if (incomingByte == 'D') {
      isl_d();
      delay(2000);
    } 
    if (incomingByte == 'F' ) {
      isl_f();
      delay(2000);
    }
    if (incomingByte == 'G') {
      isl_g();
      delay(2000);
    } 
    if (incomingByte == 'H' ) {
      isl_h();
      delay(2000);
    }
    if (incomingByte == 'I') {
      isl_i();
      delay(2000);
    } 
    if (incomingByte == 'K' ) {
      isl_k();
      delay(2000);
    }
     if (incomingByte == 'L' ) {
      isl_l();
      delay(2000);
    }
    if (incomingByte == 'O') {
      isl_o();
      delay(2000);
    } 
    if (incomingByte == 'P' ) {
      isl_p();
      delay(2000);
    }
      if (incomingByte == 'Q' ) {
      isl_q();
      delay(2000);
    }
    if (incomingByte == 'S') {
      isl_s();
      delay(2000);
    } 
    if (incomingByte == 'U' ) {
      isl_u();
      delay(2000);
    }
    if (incomingByte == 'Y') {
      isl_y();
      delay(2000);
    } 
    if (incomingByte == '#' ) {
      alltoopen();
      delay(2000);
    }
  }
}
