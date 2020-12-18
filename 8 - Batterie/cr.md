# 8 - Afficher le niveau de la *batterie*

## Préambule
##### Ressources
| Features          | Tutorials               |
| ----------------- |:----------------------- |
| Ressource | [:link:][https://www.regenebatt.com/batterie-world/techniques-batterie/tableau-comparatif-des-differentes-technologies.html] |
## Diagramme des cas d'utilisation 

##### Proposer un diagramme de cas d’utilisation correspondant à votre problématique
![]()

--- 
## Etude de cas
---
##### Donner les différentes technologie de stockage de l’énergie 

Pour stocker de l'énergie, on peut utiliser 
- Des piles Li-ion
- Des batteries au lithium
- Des batteries Li-Po
- Des piles alcalines

##### Comparer dans un tableau les différentes techniques de stockage. Choisir au minimum 4 critères de comparaison
||Pile alcalines|Li-Po| Li-ion
| --|:-------  |:-|:--
|Tension (en V)|1,5-1,65 V|3,7 V |3,6 V
|Rechargeable| variable| oui|oui
|Durée de vie (recharges)|25 à 500 |200 à 300 |500 à 1000
|Auto-décharge/mois| < 0,3 %|10 % | 10 %

##### Donner les différents moyens permettant de détecter niveau de charge d’une batterie
## Représentation
---

##### Proposer un schéma d’expérimentation basé vos recherches
![]()

##### Représenter la chaîne d’information et d’énergie du système.


## Manipulation 
#### Présenter le programme ou partie permettant d’assurer le contrôle du niveau de charge des batteries
```cpp=1
float nvalue=0;
float qt=0.004882813;
float Uve=0;

void setup(){
    Serial.begin(9600);
    }
         
void loop(){ 
     nvalue = analogRead(A2);
     Uve = nvalue*qt;
     Serial.println(Uve);
     delay(5000);
}
// ~Théophile
```
~Théophile
