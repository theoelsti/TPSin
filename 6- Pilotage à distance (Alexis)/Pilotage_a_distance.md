
# 6 | Pilotage à distance | A finir

## Diagramme des cas d'utilisation 

##### Proposer un diagramme de cas d’utilisation correspondant à votre problématique
![](https://i.imgur.com/YuEZwHi.png)
--- 
## Etude de cas
---
##### Donner les différents moyens permettant de transmettre des informations sans fil au robot

| Moyen          | Utilisation               |
| ----------------- |:----------------------- |
| Bluetooth      | Communiquer avec le robot sur une dizaine de mètres   |
| Wifi      | Communiquer avec le robot dans un reseau local sur une vingtaine de mètres|
| Radio      | Communiquer avec le robot sur une grande distance   |

#### Comparer dans un tableau les différentes techniques de transmission de l’information sans fils. Choisir au minimum 4 critères de comparaison.

|           | Bluetooth | Wifi| Radio
| - |:- |:---|:---
| Type|   Ondes radioéléctriques | Ondes radioéléctriques | Ondes Radio
| Distance max (en mètres) | 10| 20-50| Variable, ici 1000 max
| Portée      | Courte| Moyenne| Grande
|Usages|Communication entre périphériques|Transport de paquets, communication entre machines sur un reseau|Transport de signaux,  issus de la voix et de l'image, ou commandes d'un appareil maitre sur esclave |

#### Donner les différents moyens permettant de détecter le bord de la piste dans un tableau. Donner 3 critères de comparaisons.

|| Inductif | Magnetique
| - |:- |:---
| Distance max en mètres|0.1| 0.5| Ondes Radio
| Utilisation sur :| Métal| Element composé d'un aimant
|Fonctionnement | Lorsqu'un objet s'approche, le champ éléctromagnétique va diminuer. A partir de mesures fréquentes, on peut déterminer la distance| Un champ magnétique est envoyé sous forme de période. Si le champ recu est superieur a celui envoyé, cela signifie que la distance augmente
|Utilisation |Vérifier si un élément passe devant le capteur|Vérifier si un élément composé d'un aimant est près du capteur


## Représentation
---

#### Proposer un schéma d’expérimentation basé sur le bluetooth, il faudra 2 micro-contrôleurs pour votre expérimentation.

#### Représenter la chaîne d’information et d’énergie du système.


## Manipulation 

#### Présenter le programme ou partie permettant d’assurer la transmission coté émetteur et récepteur
> Il nous faut **2** programmes : 

- Un pour l'esclave

```cpp=1
#include <SoftwareSerial.h>
#define RxD         7
#define TxD         6
#define PINLED      3
#define LEDON()     digitalWrite(PINLED, HIGH)
#define LEDOFF()    digitalWrite(PINLED, LOW)
#define DEBUG_ENABLED  1
SoftwareSerial blueToothSerial(RxD,TxD);

void setup()
{
    Serial.begin(9600);
    pinMode(RxD, INPUT);
    pinMode(TxD, OUTPUT);
    pinMode(PINLED, OUTPUT);
    LEDOFF();

    setupBlueToothConnection();
}

void loop()
{
    char recvChar;

    while(1)
    {
        if(blueToothSerial.available())
        {
            recvChar = blueToothSerial.read();


            if(recvChar == '1')
            {
                Serial.println("On Avance");
                LEDON();
            }
            else if(recvChar == '2')
            {
                Serial.println("A gauche");
                LEDOFF();
            }
            else if(recvChar == '3')
            {
                Serial.println("On recule");
                LEDOFF();
            }
            else if(recvChar == '4')
            {
                Serial.println("A Droite");
                LEDOFF();
            }
        }
    }
}


void setupBlueToothConnection()
{
/*
configuration du bt en plusieurs etapes, changement du nom de host etc... Utile !

*/

  blueToothSerial.begin(9600);

  blueToothSerial.print("AT");
  delay(400); 

  blueToothSerial.print("AT+DEFAULT");
  delay(2000); 

  blueToothSerial.print("AT+NAMESeeedBTSlave");
  delay(400);

  blueToothSerial.print("AT+PIN0000");
  delay(400);
 
  blueToothSerial.print("AT+AUTH1");
  delay(400);

  blueToothSerial.flush();

}
```
- Un pour le maître
```cpp=1
#include <SoftwareSerial.h>

#define RxD         7
#define TxD         6
#define PINBUTTON   3
#define DEBUG_ENABLED  1

String incomingData;
String readString;
SoftwareSerial blueToothSerial(RxD, TxD);

void setup()
{
  Serial.begin(9600);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(PINBUTTON, INPUT);
  setupBlueToothConnection();
  delay(1000);
  Serial.flush();
  blueToothSerial.flush();
}

void loop()
{
  while (Serial.available()) {
    char c = Serial.read(); 
    readString += c;
    delay(2); 
  }

 if (readString.length() > 0) { 
    int n = readString.toInt(); 
    blueToothSerial.print(n);
    readString="";
  } 
}

/*
configuration du bt en plusieurs etapes, changement du nom de host etc... Utile !

*/
void setupBlueToothConnection()
{


  blueToothSerial.begin(9600);

  blueToothSerial.print("AT");
  delay(400);

  blueToothSerial.print("AT+DEFAULT");
  delay(2000);

  blueToothSerial.print("AT+NAMESeeedMaster");
  delay(400);

  blueToothSerial.print("AT+ROLEM");
  delay(400);


  blueToothSerial.print("AT+AUTH1");
  delay(400);

  blueToothSerial.print("AT+CLEAR");
  delay(400);

  blueToothSerial.flush();


}
```
~Théophile FOUILLET & Alexis Fourquier
