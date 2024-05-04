#include "PCA9685.h"
#include <Wire.h>
#include "ISL_Servo_Library.h"

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();
    Serial.begin(9600);
    servo.init(0x7f);
}
void loop() {

      //wristcenter();
     neutralpos(); 
    
}




