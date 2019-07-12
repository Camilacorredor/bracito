#include <Servo.h>

#define pinBase 12
#define pinDerecho 11
#define pinIzquierdo 10
#define pinMano 9

Servo motorBase;
Servo motorDerecho;
Servo motorIzquierdo;
Servo motorMano;

void Agarrar (void);
void Abrir (void);
void GirarDerecha (void);
void GirarIzquierda (void);
void GirarCentro (void);

void setup() {




}

void loop() {
    motorMano.attach(pinMano);
  Agarrar ();
  delay(2000);
  Abrir ();
  delay(2000);
}
void Agarrar (void)
{
  motorMano.attach(pinMano);
  motorMano.write(120);
}
void Abrir (void)
{
  motorMano.attach(pinMano);
  motorMano.write(90);
}
void GirarDerecha (void)
{
  motorBase.attach(pinBase);
  motorBase.write(0);
}
void GirarIzquierda (void)
{
  motorBase.attach(pinBase);
  motorBase.write(180);
}
void GirarCentro (void)
{
  motorBase.attach(pinBase);
  motorBase.write(90);
}
