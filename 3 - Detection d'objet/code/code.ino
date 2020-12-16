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
