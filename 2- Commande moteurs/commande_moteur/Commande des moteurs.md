# Commande des moteurs

> Rappeler dans un tableau les principaux différents type de moteurs. Donner les avantages et inconvénients de chaque type de moteur. Préciser dans un colonne le domaine d’utilisation

| Type              | Avantages               | Inconvenients
| ----------------- |----------------------- |----
| Moteur Electrique |0% d'émission de Co2, peu de bruit,acceleration rapide, bon rendement (80%) | Besoin d'une batterie : non renouvelable
| Moteur Thermique  |Comparé au moteur thermique, il n'y a pas d'avantages| Emissions de co2, utilise du pétrole, rare, faible rendement

> Rappeler le principe de fonctionnement des 3 principaux types de moteurs

| Type              | Fonctionnement
| ----------------- |----------------------- 
| Moteur Electrique | Une batterie alimente un moteur qui fait tourner les roues. En décélération, la batterie se recharge
| Moteur Thermique  | De l'essence est injectée dans un moteur. Se passe une reaction chimique faisant tourner des pistons, le tout relié à un vilbrequin, qui au final fait tourner les roues
|Moteur Hybride     | Le moteur hybride comprend le fonctionnement du moteur Electrique et du moteur Thermique : en dessous d'une certaine vitesse est utilisé uniquement le moteur Electrique, puis le moteur Thermique s'active

> Enumérer les paramètres physique à prendre en compte pour le dimensionnement d’un moteur

Les parametres a prendre en compte sont: 
- Le poids du vehicule
- Le volume disponible pour son stockage

> Quel composant permet de connaître le déplacement angulaire d’un moteur CC

C'est la roue optique qui permet de connaitre le déplacement angulaire

> Proposer un schéma d’expérimentation pour un moteur CC avec une carte de pilotage


> Présenter le programme ou permettant de controleret  connaître le déplacement effectué par les moteurs
```cpp=1
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#define left 2
//Variables
int lent = 50;
int moyen = 120;
int rapide = 200;
int arret = 0;
int oldspeed;
int intmot = 0 ;
// On instancie nos moteurs
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
    Serial.print(" sur la roue de droite");
    leftMotor->setSpeed(oldspeed);
    rightMotor->setSpeed(oldspeed-(oldspeed/2));
    }
    
  else{
      Serial.println("Chiffre");
  leftMotor->setSpeed(intmot);
  rightMotor->setSpeed(intmot);    
      }
   }  
}
```


###### ~Théophile FOUILLET