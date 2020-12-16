#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#define left 2
int lent = 50;
int moyen = 120;
int rapide = 200;
int arret = 0;
int oldspeed;
int intmot = 0 ;
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *rightMotor = AFMS.getMotor(1);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);
void setup() {
  Serial.begin(9600);
  AFMS.begin();
  rightMotor->run(FORWARD);
  rightMotor->setSpeed(1);
  leftMotor->run(FORWARD);
  leftMotor->setSpeed(1);
}
void loop(){
  
  if(Serial.available() > 0){
    
  String mot = Serial.readString();
  oldspeed = intmot;
  intmot = mot.toInt();
  if( intmot == 1){
    Serial.println("Lent");
      rightMotor->setSpeed(lent);
      leftMotor->setSpeed(lent);
      }
  else if(intmot == 2){
    Serial.println("Moyen");
    rightMotor->setSpeed(moyen);
    leftMotor->setSpeed(lent);
    }
  else if( intmot == 3){
    Serial.println("Rapide");
    rightMotor->setSpeed(rapide);
    leftMotor->setSpeed(lent);
   }
  else if( intmot == 0){
    Serial.println("Arret");
  rightMotor->setSpeed(arret);
  leftMotor->setSpeed(arret);
    }
  else if( intmot == 4){
    Serial.println("Gauche");
    Serial.println("Je passe de ");
    Serial.print(oldspeed);
    Serial.print(" à ");
    Serial.print(oldspeed/10);
    Serial.print(" sur la route de gauche");
    rightMotor->setSpeed(oldspeed);
    leftMotor->setSpeed(oldspeed-(oldspeed/2));
    }
  else if( intmot == 6){
    Serial.println("Droite");
    Serial.println("Je passe de ");
    Serial.print(oldspeed);
    Serial.print(" à ");
    Serial.print(oldspeed/10);
    Serial.print(" sur la route de droite");
    leftMotor->setSpeed(oldspeed);
    rightMotor->setSpeed(oldspeed-(oldspeed/2));
    }
    
  else{
      Serial.println("Chiffre");
  leftMotor->setSpeed(intmot);
  rightMotor->setSpeed(intmot);
  //for(int i=0;i<10;i++){
  //vitesse = intmot - i*2;
  //leftMotor->setSpeed(vitesse);
  //rightMotor->setSpeed(vitesse);
  //delay(100);
  //  }
    
      }
   }  
}
