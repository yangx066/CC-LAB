

import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

color off = color(198,198,198);
color on = color(255,80,80);
Boolean high3 = false;
Boolean high4 = false;
Boolean high5 = false;

//int[] values = { Arduino.LOW, Arduino.LOW, Arduino.LOW };

void setup() {
  size(400, 200);
  
  println(Arduino.list());
  
 
  arduino = new Arduino(this, Arduino.list()[1], 57600);
  
  

    arduino.pinMode(3, Arduino.OUTPUT);
    arduino.pinMode(4, Arduino.OUTPUT);
    arduino.pinMode(5, Arduino.OUTPUT);
}

void draw() {
  background(0);
  stroke(0);
  
  if (high3 == true){
    fill(on);
  }else{
    fill(off);
  }  
    ellipse(100, 100,20,20);
    
    
  if (high4 == true){
    fill(on);
  }else{
    fill(off);
  }  
    ellipse(200, 100, 20, 20);
    
    
    if (high5 == true){
    fill(on);
  }else{
    fill(off);
  }  
    ellipse(300, 100, 20, 20);
}


void mousePressed(){
  if (90<mouseX && mouseX<110){
    if (high3 == false){
      high3 = true;
   } else {
      high3 = false;
   }
  }
  if (high3 == true){
    arduino.digitalWrite(3,Arduino.HIGH);
  }else{
    arduino.digitalWrite(3,Arduino.LOW);
  }
  
  
  if (190<mouseX && mouseX<210){
    if (high4 == false){
      high4 = true;
   } else {
      high4 = false;
   }
  }
  if (high4 == true){
    arduino.digitalWrite(4,Arduino.HIGH);
  }else{
    arduino.digitalWrite(4,Arduino.LOW);
  }
  
    
  
  if (290<mouseX && mouseX<310){
    if (high5 == false){
      high5 = true;
   } else {
      high5 = false;
   }
  }
  if (high5 == true){
    arduino.digitalWrite(5,Arduino.HIGH);
  }else{
    arduino.digitalWrite(5,Arduino.LOW);
  }
}