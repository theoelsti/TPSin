float nvalue=0;
float qt=0;
float Uve=0;

void setup(){
    Serial.begin(9600);
    }
         
void loop(){ 
     nvalue = analogRead(A2);
     qt = 0.004882813;
     Serial.println(qt,20);
     delay(5000);
     Uve = nvalue*qt;
     Serial.println(Uve);
     delay(5000);
}
