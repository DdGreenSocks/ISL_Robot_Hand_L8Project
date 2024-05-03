// PCA9685 pin set up for hand motors
int pinky_f=5;
int ring_f=4;
int middle_f=3;
int index_f=2;
int thumb_f=1;
int wrist=7;

// Intialising servo 
ServoDriver servo;

// Hand at rest position
void neutralpos(){

  servo.setAngle(pinky_f,90);
  servo.setAngle(ring_f,90);
  servo.setAngle(middle_f,90);
  servo.setAngle(index_f,90);
  servo.setAngle(thumb_f,90);
  servo.setAngle(wrist,30);
}

// Wrist at center position 
void wristcenter(){   	    
  servo.setAngle(wrist,30);
}

// Wrist at furthest right position
void wristright(){
  servo.setAngle(wrist,115);
}

//Wrist at furthest left position
void wristleft(){
  servo.setAngle(wrist,0);
}

// Fingers at fully closed position
void alltoclosed(){
  
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  servo.setAngle(thumb_f,140);
       
}  

//Fingers at fully open position
void alltoopen(){
  servo.setAngle(thumb_f,20);
  delay(500);      
  servo.setAngle(pinky_f,30);
  delay(500);
  servo.setAngle(ring_f,20);
  delay(500);
  servo.setAngle(middle_f,10);
  delay(500);
  servo.setAngle(index_f,20);
  delay(500);
  

}  

// Servo positions for ISL A 
void isl_a(){
  
  servo.setAngle(wrist,30);       
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  servo.setAngle(thumb_f,55);
}

// Servo positions for ISL B
void isl_b(){
  
  servo.setAngle(wrist,30);     
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,10);
  servo.setAngle(thumb_f,160);
}

// Servo positions for ISL D
void isl_d(){
  
  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,140);
}  

// Servo positions for ISL F
void isl_f(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,140);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

// Servo positions for ISL G
void isl_g(){

  servo.setAngle(wrist,120); 
  servo.setAngle(thumb_f,150);
  delay(500); //Delay needed as thumb should rest under the fingers for this sign
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,90);
} 

// Servo positions for ISL H
void isl_h(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,20);
  delay(500); //Delay needed as thumb should rest above the fingers for this sign
  servo.setAngle(thumb_f,140);     
}

// Servo positions for ISL I
void isl_i(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  delay(500); //Delay needed as thumb should rest above the fingers for this sign
  servo.setAngle(thumb_f,140);     
}

// Servo positions for ISL K
void isl_k(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,20);
  delay(500); //Delay needed as thumb should rest above the fingers for this sign
  servo.setAngle(thumb_f,140);     
}

// Servo positions for ISL L
void isl_l(){

  servo.setAngle(wrist,30);     
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  servo.setAngle(thumb_f,20);

}  

// Servo positions for ISL O
void isl_o(){
  
  servo.setAngle(thumb_f,150);
  delay(500); //Delay needed as thumb should rest below the fingers for this sign
  servo.setAngle(wrist,120);     
  servo.setAngle(pinky_f,90);
  servo.setAngle(ring_f,90);
  servo.setAngle(middle_f,90);
  servo.setAngle(index_f,90);
}     

// Servo positions for ISL P
void isl_p(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  delay(500); //Delay needed as thumb should rest above the fingers for this sign
  servo.setAngle(thumb_f,140);     
}

// Servo positions for ISL Q
void isl_q(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  delay(500); //Delay needed as thumb should rest above the fingers for this sign
  servo.setAngle(thumb_f,150);     
}

// Servo positions for ISL S
void isl_s(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  delay(500); //Delay needed as thumb should rest above the fingers for this sign
  servo.setAngle(thumb_f,150);     
}

// Servo positions for ISL U
void isl_u(){

servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  delay(500); //Delay needed as thumb should rest above the fingers for this sign
  servo.setAngle(thumb_f,150);    
}

// Servo positions for ISL Y
void isl_y(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  servo.setAngle(thumb_f,20);    
}