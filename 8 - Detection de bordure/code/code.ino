#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#define left 2
#define right 3
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *rightMotor = AFMS.getMotor(1);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);
void setup() {
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  Serial.begin(9600);

  AFMS.begin();
  rightMotor->setSpeed(75);
  leftMotor->setSpeed(75);
}
void loop(){
  Serial.println(digitalRead(left));
  Serial.println(digitalRead(right));
  if(digitalRead(left)==0 && digitalRead(right)==0){
    //ON ROULE ON ROULE ON ROULEEEEE
     rightMotor->run(RELEASE);
     leftMotor->run(RELEASE);
  }
  //LIGNE A GAUCHE CAPITAINEEEE
  else if(digitalRead(left)==0 && !analogRead(right)==0){
    //turn left
     rightMotor->run(FORWARD);
     leftMotor->run(RELEASE);
    
  }
  //OBSTACLE A TRIBORDDDDDDDDDDDDDDDDDDDDDDDdd
  else if(!digitalRead(left)==0 && digitalRead(right)==0){
    rightMotor->run(RELEASE);
     leftMotor->run(FORWARD);
   
  }
  //ZBIIII ON A PLUS RIEN
  else if(!digitalRead(left)==0 && !digitalRead(right)==0){
     rightMotor->run(BACKWARD);
     leftMotor->run(FORWARD);
     delay(500) ;
     rightMotor->(FORWARD) ;
   
  }
  
}
