#include <Servo.h>

#define pinBase 12
#define pinDerecho 11
#define pinIzquierdo 10
#define pinMano 9

Servo motorBase;
Servo motorDerecho;
Servo motorIzquierdo;
Servo motorMano;

void setup() {

 motorBase.attach(pinBase);
 motorDerecho.attach(pinDerecho);
 motorIzquierdo.attach(pinIzquierdo);
 motorMano.attach(pinMano);

 
 motorBase.write(0);
 delay(2000);
 motorDerecho.write(0);
 delay(2000);
 motorMano.write(60);
 delay(2000);
 motorBase.write(90);
 delay(2000);
 motorDerecho.write(180);
 delay(2000);
 motorIzquierdo.write(30);
 delay(2000);
 motorBase.write(180);
 delay(2000);
 motorDerecho.write(90);
 delay(2000);
 motorIzquierdo.write(180);
 delay(2000);
 motorMano.write(180);


}

void loop() {
  // put your main code here, to run repeatedly:

}
