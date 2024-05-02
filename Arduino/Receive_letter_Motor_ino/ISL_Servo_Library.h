int pinky_f=5;
int ring_f=4;
int middle_f=3;
int index_f=2;
int thumb_f=1;
int wrist=7;

ServoDriver servo;

void neutralpos(){

  servo.setAngle(pinky_f,90);
  servo.setAngle(ring_f,90);
  servo.setAngle(middle_f,90);
  servo.setAngle(index_f,90);
  servo.setAngle(thumb_f,90);
  servo.setAngle(wrist,30);
}

void wristcenter(){
  servo.setAngle(wrist,30);
}

void wristright(){
  servo.setAngle(wrist,115);
}

void wristleft(){
  servo.setAngle(wrist,0);
}

void alltoclosed(){
  
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  servo.setAngle(thumb_f,140);
       
}  

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

void isl_a(){
  
  servo.setAngle(wrist,30);       
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  servo.setAngle(thumb_f,55);
}

void isl_b(){
  
  servo.setAngle(wrist,30);     
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,10);
  servo.setAngle(thumb_f,160);
}
  
void isl_d(){
  
  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,30);
  delay(500);
  servo.setAngle(thumb_f,140);
}  

void isl_f(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,140);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

void isl_g(){

  servo.setAngle(wrist,120); 
  servo.setAngle(thumb_f,150);
  delay(500);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,90);
} 

void isl_h(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

void isl_i(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

void isl_k(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

void isl_l(){

  servo.setAngle(wrist,30);     
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  servo.setAngle(thumb_f,20);

}  

void isl_o(){
  
  servo.setAngle(thumb_f,150);
  delay(500);
  servo.setAngle(wrist,120);     
  servo.setAngle(pinky_f,90);
  servo.setAngle(ring_f,90);
  servo.setAngle(middle_f,90);
  servo.setAngle(index_f,90);
}     

void isl_p(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,20);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,140);     
}

void isl_q(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,150);     
}

void isl_s(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  delay(500);
  servo.setAngle(thumb_f,150);     
}

void isl_u(){

servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,150);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,10);
  servo.setAngle(index_f,20);
  delay(500);
  servo.setAngle(thumb_f,150);    
}

void isl_y(){

  servo.setAngle(wrist,30);
  servo.setAngle(pinky_f,30);
  servo.setAngle(ring_f,140);
  servo.setAngle(middle_f,150);
  servo.setAngle(index_f,140);
  servo.setAngle(thumb_f,20);    
}