# Bus can 1 
#### Theophile FOUILLET

---

# Question 1 
> Quelles-sont les grandeurs physiques présentes en entrée et en sortie du capteur de luminosité ?

La grandeur physique en entrée est de la **Lumiere**, en lumens, et en sortie des valeurs analogiques, exprimant une valeur approximative en **Lumens**

# Question 2
 > Sur la documentation du constructeur du capteur GL5528, la figure présentant la réponse spectrale fait apparaître trois courbes. A quoi correspondent-elles ?

![](https://i.imgur.com/8D3Bfkv.png)

La courbe Cds correspond à la résistance au sulfure de cadmium ou résistance dépendante de la lumière. 

La courbe CdSe à là resistance au séléniure de cadmium.

Cd(S.Se) est la moyenne des deux valeurs, correspondant à l'approximation de la valeurs en lumens 
> 
> La résistance est inversement dépendante de la quantité de lumière qui la frappe, est connue sous de nombreux noms tels que résistance photo, photorésistance, photoconducteur ou simplement cellule photoélectrique.

# Question 3 

> Déterminer pour quelle longueur d’onde le capteur GL5528 a la meilleure sensibilité.

Le capteur **GL5528** a une meilleure sensibilité sur le jaune/orange

# Question 4

> Quelles-sont les longueurs d’ondes que le capteur de lumière GL5528 est capable de détecter en présentant une atténuation de sa sensibilité comprise entre 0dB et 6dB ?

Entre 550 et 800 nm

# Question 5 
> La figure 2 détaille la décomposition spectrale de la lumière. Quelles-sont les couleurs que le capteur de lumière GL5528 est capable de détecter en présentant une atténuation de sa sensibilité comprise entre 0dB et 6dB ?

2854k couleurs sont detectables par le capteur GL5528

# Question 6
> A l’aide du document fourni en annexe 0, déterminer quel-est le flux lumineux moyen présent dans une salle de classe ?

Il est de 500 lux.

# Question 7

> A l’aide la documentation constructeur du GL5528, estimer quelle sera la résistance présente aux bornes du capteur de lumière pour ce flux lumineux ?

Nous ne pouvons pas mesurer au dessus de 100 lux pour la résistance. La resistance sera au dessus de 1000kΩ

---
*Afin de fournir au filtre CAN de la carte ARDUINO une tension qui soit représentative du niveau d’éclairement reçu par le capteur de luminosité, on met en œuvre le circuit de conditionnement représenté en figure 5.*

![](https://i.imgur.com/lzmEGLm.png)


# Question 8 
> Exprimer la relation qui lie la tension V+ à la tension Vcc en fonction de Ph1 et R1.
$$
V+ = Vcc *  R1 / RPh1 + R1
$$
# Question 9 
> L’amplificateur opérationnel TL082 est monté en suiveur. Donner à présent la relation qui lie la tension Vs à la tension Vcc en fonction de Ph1 et R1.

$$
Vs = Vcc * R1 / RPh1 + R1
$$
# Question 10 
> Quel-est l’intérêt d’utiliser un montage suiveur en électronique ?

Un montage suiveur (en electronique) prend son interet lorsqu'un circuit recoit une alimentation trop faible, risquant alors que la rension sécroule du à une charge trop elevée. Le circuit avec l'aop a alors une impédance d'entreée quasi infinie.  

###### ~Fadeath

