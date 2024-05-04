/********************************************************************
Project Title: ISL_Alphabet Translator Motor Control
Description: Receive input data over serial connection and control motor positions using ISL_Servo_Library.h 
By Deirdre Deeney 
Date: 04/05/2024
********************************************************************/

#include "PCA9685.h" // include PWM driver board library
#include <Wire.h>  // include wire library for I2C Communication
#include "ISL_Servo_Library.h" //Include custom servo position library for ISL

void setup() {
  // Initialize I2C bus
  Wire.begin();
  
  // Initialize servo and set its I2C address
  servo.init(0x7f);
  
  // Initialize serial communication
  Serial.begin(9600);
  
  // Perform initial motor positions setup
  alltoopen();
  delay(1000);

  // Sign Hi at startup
  isl_h();
  delay(2000);
  isl_i();
  delay(2000);
  alltoopen();
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available() > 0) {
    // Read incoming byte from serial port
    char incomingByte = Serial.read();
    Serial.println(incomingByte); // Print incoming byte for debugging

    // Switch case to handle different commands
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
        // Reset all motors to open positions and move wrist to center
        alltoopen();
        wristcenter();
        break;
      default:
        // Handle unrecognized command
        break;
    }
    
    // Delay to prevent rapid processing of consecutive commands
    delay(2000);
  }
}
