#include "PCA9685.h"
#include <Wire.h>
#include "ISL_Servo_Library.h"

void setup() {
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();
  servo.init(0x7f);
  Serial.begin(9600);
  alltoopen();
  delay(1000);
  isl_h();
  delay(2000);
  isl_i();
  delay(2000);
  alltoopen();

}
void loop() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    Serial.println(incomingByte);

    switch (incomingByte) {
          case 'A':
            isl_a();
            break;
          case 'B':
            isl_b();
            break;
          case 'D':
            isl_d();
            break;
          case 'F':
            isl_f();
            break;
          case 'G':
            isl_g();
            break;
          case 'H':
            isl_h();
            break;
          case 'I':
            isl_i();
            break;
          case 'K':
            isl_k();
            break;
          case 'L':
            isl_l();
            break;
          case 'O':
            isl_o();
            break;
          case 'P':
            isl_p();
            break;
          case 'Q':
            isl_q();
            break;
          case 'S':
            isl_s();
            break;
          case 'U':
            isl_u();
            break;
          case 'Y':
            isl_y();
            break;
          case '#':
            alltoopen();
            wristcenter();
            break;
          default:
            // Handle unrecognized command
            break;
        }
    
    delay(2000);
  }
}