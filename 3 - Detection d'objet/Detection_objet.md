# 3 - Détection d'objet

## Préambule
##### Ressources
| Doc          | Lien               |
| ----------------- |:----------------------- |
| HC-SR04 | [:link:][https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/] |
| Browser Extension | [:link:][https://www.adafruit.com/product/157] |
## Diagramme des cas d'utilisation 

##### Proposer un diagramme de cas d’utilisation correspondant à votre problématique
![](https://i.imgur.com/YZt5mNU.png)

--- 
## Etude de cas
---
##### Donner dans un tableau les principaux types de capteurs d’obstacles, leur technologies, mode de fonctionnement, distance de détection et degré de précision dans un tableau. 

||Capteur à Ultrason|Détecteur Infrarouge
| --|:-------  |:-
|Moyen utilisé|Ultrasons|Infrarouge 
|Distance max (en mètres)|4|0.1
|Degré de précision|0.03|40°

##### Dresser un tableau pour chaque type de capteurs en précisant dans chaque colonne la référence du capteur, la tension de fonctionnement, le type de signal en sortie du capteur, et si il y a lieu la présence d’un CAN intégré
||Capteur à Ultrason|Détecteur Infrarouge
| --|:-------  |:-
|Référence du capteur|HC-SR04|TSOP38238 
|Tension de fonctionnement|5V | 5V
|Signal en sortie|Digital|Digital



## Représentation
---

##### Proposer un schéma d’expérimentation permettant de trouver les obstacles basé sur un des capteurs présent dans la salle de TP
![](https://i.imgur.com/F8m2Hcm.png)

#### 


## Manipulation 
#### Présenter le programme permettant de piloter le détecteur d’obstacles
```cpp=1
#include "Ultrasonic.h"
 
Ultrasonic ultrasonic(7);
void setup()
{
    Serial.begin(9600);
}
void loop()
{
    
    long distanceCM;
 
    Serial.println("La distance avec l'objet devant est de ");
    distanceCM = ultrasonic.MeasureInCentimeters(); 
    Serial.print(distanceCM);//0~400cm
    Serial.println(" cm");
    delay(250);
}
```
#### Présenter le programme ou partie permettant de trouver l’emplacement des obstacles
????
#### Présenter les limites de fonctionnement de votre capteur et axe d’améliorations possible

Le principal probleme est le suivant : si notre robot se trouve face à une surface absorbant les ondes acoustiques, il ne pourra pas déterminer la distance avec celle-ci.
Aussi, si un obstacle se trouve a droite ou a gauche du robot, il ne pourra pas le détécter
~Théophile FOUILLET
