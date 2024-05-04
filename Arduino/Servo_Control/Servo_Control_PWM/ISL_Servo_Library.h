// Define pins for each finger and the wrist
int pinky_f = 5;
int ring_f = 4;
int middle_f = 3;
int index_f = 2;
int thumb_f = 1;
int wrist = 7;

// Initialize the ServoDriver object
ServoDriver servo;

// Function to set all servos to a neutral position
void neutralpos() {
  servo.setAngle(pinky_f, 90);
  servo.setAngle(ring_f, 90);
  servo.setAngle(middle_f, 90);
  servo.setAngle(index_f, 90);
  servo.setAngle(thumb_f, 90);
  servo.setAngle(wrist, 115);
}

// Function to set the wrist to the center position
void wristcenter() {
  servo.setAngle(wrist, 30);
}

// Function to set the wrist to the right position
void wristright() {
  servo.setAngle(wrist, 115);
}

// Function to set the wrist to the left position
void wristleft() {
  servo.setAngle(wrist, 0);
}

// Function to set all fingers to the closed position
void alltoclosed() {
  servo.setAngle(pinky_f, 150);
  servo.setAngle(ring_f, 140);
  servo.setAngle(middle_f, 150);
  servo.setAngle(index_f, 140);
  servo.setAngle(thumb_f, 140);
}

// Function to set all fingers to the open position
void alltoopen() {
  servo.setAngle(thumb_f, 20);
  delay(500);
  servo.setAngle(pinky_f, 30);
  delay(500);
  servo.setAngle(ring_f, 20);
  delay(500);
  servo.setAngle(middle_f, 10);
  delay(500);
  servo.setAngle(index_f, 20);
  delay(500);
}

// Function to set the fingers to the ISL Alphabet gesture 'A'
void isl_a() {
  servo.setAngle(wrist, 30);
  servo.setAngle(pinky_f, 150);
  servo.setAngle(ring_f, 140);
  servo.setAngle(middle_f, 150);
  servo.setAngle(index_f, 140);
  servo.setAngle(thumb_f, 55);
}

// Function to set the fingers to the ISL Alphabet gesture 'B'
void isl_b(){
  
  servo.setAngle(wrist,30);     
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,10);
  servo.setAngle(thumb_f,160);
}
  
// Function to set the fingers to the ISL Alphabet gesture 'D'
void isl_d(){
  
  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,30);
  delay(500);
  servo.setAngle(thumb_f,140);
}  

// Function to set the fingers to the ISL Alphabet gesture 'F'
void isl_f(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,140);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

// Function to set the fingers to the ISL Alphabet gesture 'G'
void isl_g(){

  servo.setAngle(wrist,120); 
  servo.setAngle(thumb_f,150);
  delay(500);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,90);
} 

// Function to set the fingers to the ISL Alphabet gesture 'H'
void isl_h(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

// Function to set the fingers to the ISL Alphabet gesture 'I'
void isl_i(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

// Function to set the fingers to the ISL Alphabet gesture 'K'
void isl_k(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

// Function to set the fingers to the ISL Alphabet gesture 'L'
void isl_l(){

  servo.setAngle(wrist,30);     
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  servo.setAngle(thumb_f,20);

}  

// Function to set the fingers to the ISL Alphabet gesture 'O'
void isl_o(){
  
  servo.setAngle(thumb_f,150);
  delay(500);
  servo.setAngle(wrist,120);     
  servo.setAngle(pinky_f,90);
  servo.setAngle(ring_f,90);
  servo.setAngle(middle_f,90);
  servo.setAngle(index_f,90);
}     

// Function to set the fingers to the ISL Alphabet gesture 'P'
void isl_p(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

// Function to set the fingers to the ISL Alphabet gesture 'Q'
void isl_q(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,150);     
}

// Function to set the fingers to the ISL Alphabet gesture 'S'
void isl_s(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  delay(500);
  servo.setAngle(thumb_f,150);     
}

// Function to set the fingers to the ISL Alphabet gesture 'U'
void isl_u(){

servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,150);    
}

// Function to set the fingers to the ISL Alphabet gesture 'Y'
void isl_y(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  servo.setAngle(thumb_f,20);    
}