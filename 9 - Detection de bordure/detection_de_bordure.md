# 9 - Détection de bordure
###### tags: `TP tournant`, `détection`
## Préambule
##### Ressources
| Doc          | Lien               
| ----------------- |:----------------------- 
| Documentation diverse | [:link:][https://www.instructables.com/Arduino-Color-Detection/] 
| Documentation diverse | [:link:][https://randomnerdtutorials.com/arduino-color-sensor-tcs230-tcs3200/] 
| Documentation diverse | [:link:][https://www.arduino.cc/en/Tutorial/LibraryExamples/RobotLineFollowing] 
## Diagramme des cas d'utilisation 

##### Proposer un diagramme de cas d’utilisation correspondant à votre problématique
![](https://i.imgur.com/3WbuYEM.png)


--- 
## Etude de cas
---
##### Donner les différents moyens permettant de détecter une bordure.
Pour détecter une bordure, on peut utiliser une caméra, un capteur de couleur ou encore un capteur infrarouge

##### Expliquer le fonctionnement et technologie des capteurs trouvés. 
-	La caméra servirait à détecter une certaine couleur cependant la puissance de l’Arduino ne nous permettrais pas d’acquérir des images aussi rapidement
-	Le capteur de couleur dispose de 4 projetant de la lumière, puis un capteur à photodiodes vérifie les niveaux d’intensité de bleu, rouge et vert. 
-	Le capteur infrarouge permet de detecter un obstacle proche ou une presence de couleur noire
##### Dans un tableau préciser pour au moins 2 capteurs les informations essentielles (tension de fonctionnement, consommation électrique, plage de captation, mode de transmission de l’information.)

| Doc          | Capteur de couleur | Camera | Capteur IR
| ----------------- |:-------------------- |:---|:---
| Tension de fonctionnement | 3.3V à 5.5V | 2.5 à 3.0V| 3.3v-5v
| Consommation Electrique | moyenne| moyenne| faible
| Plage de captation | 10 cm max | ~5m pour une bonne qualité| 10 cm max
| Mode de transmission de l’information| Analogue| Image| Digital

## Représentation
---

##### Proposer un schéma d’expérimentation permettant de détecter les bordures du terrain.
![](https://i.imgur.com/8uxXmkD.png)


##### Représenter la chaîne d’information et d’énergie du système.
![](https://i.imgur.com/xrqt6Pp.png)


## Manipulation 
#### Présenter le programme ou partie permettant de détecter et transmettre l’information de détection de bordure.
```cpp=1
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
    rightMotor->setSpeed(150);
    leftMotor->setSpeed(150);
}
void loop(){
    Serial.println(digitalRead(left));
    Serial.println(digitalRead(right));
    if(digitalRead(left)==0 && digitalRead(right)==0){
        //on roule
        rightMotor->run(RELEASE);
        leftMotor->run(RELEASE);
    }
    //a gauche
    else if(digitalRead(left)==0 && !digitalRead(right)==0){
        //turn left
        rightMotor->run(FORWARD);
        leftMotor->run(RELEASE);

    }
    //droite
    else if(!digitalRead(left)==0 && digitalRead(right)==0){
        rightMotor->run(RELEASE);
        leftMotor->run(FORWARD); 
	}
	  //droit devant
    else if(!digitalRead(left)==0 && !digitalRead(right)==0){

      rightMotor->run(BACKWARD);
      leftMotor->run(FORWARD);
      Delay(500) ;
      rightMotor->(FORWARD) ;

    }
}
```
~Théophile FOUILLET
