#include "PCA9685.h"
#include <Wire.h>

ServoDriver servo;
const int ledPin = 13;

void setup() {
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();
  servo.init(0x7f);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

}

void loop() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    Serial.print("Received: ");
    Serial.println(incomingByte);

    if (incomingByte == 'A') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED turned ON");
      alltoopen();
      delay(1000);
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("LED turned OFF");
      alltoclosed();
      delay(500);  
    }
  }
}

void alltoopen(){
        
        servo.setAngle(1, 40);
        //delay(1000);
        servo.setAngle(2,40);
        //delay(1000);
        servo.setAngle(3,20);
        //delay(1000);
        servo.setAngle(4,30);
        //delay(1000);
        servo.setAngle(5,40);
        //delay(1000);
      

}  

void alltoclosed(){
        
        servo.setAngle(1, 130);
        //delay(1000);
        servo.setAngle(2,130);
        //delay(1000);
        servo.setAngle(3,130);
        //delay(1000);
        servo.setAngle(4,130);
        //delay(1000);
        servo.setAngle(5,140);
        //delay(1000);
        
}  