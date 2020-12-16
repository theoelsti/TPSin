#include <Servo.h>

Servo servo_gauche;
Servo servo_droite;

#define angle_defaut_gauche 20  
#define angle_defaut_droite 89

void setup() {
   Serial.begin(9600); 
  
  servo_gauche.attach(3);
  servo_droite.attach(5);
  
  servo_gauche.write(angle_defaut_gauche);
  servo_droite.write(angle_defaut_droite);

}

void loop() {
  if(Serial.available() > 0){
    String incomingString = Serial.readString();
    

    String m1 = incomingString.substring(3,6);
    String m2= incomingString.substring(10,13);
    Serial.println(m1);
    Serial.println(m2);
    servo_gauche.write(m1.toInt());
    servo_droite.write(m2.toInt());
    }

}
