#include <Servo.h> //Comienzo de trabajo en comandos 
#include <SoftwareSerial.h>
SoftwareSerial BT (2,3);
 
 Servo motorBase;
 Servo motorDerecho;
 Servo motorIzquierdo;
 Servo motorMano;
 void Abrir (void);
void Agarrar (void);
void GirarCentro(void);
void Descender (void);
void Agachar (void);
void Subir (void);
void Ascender (void);
void GirarLadoIzquierdo(void);

 void setup ()
 {
  BT.begin (9600);
  /*Serial.begin (9600);*/
  motorBase.attach (12);
  motorDerecho.attach (11);
  motorIzquierdo.attach (10);
  motorMano.attach (9);
 }
 int m,j,c;
 char s[4];
 
void loop (){
  if (BT.available ()>0&& BT.available ()<4)
   BT.readBytes (s,4);
   { 
    switch (s[0])
  {
    case'p':
    Abrir ();
    GirarCentro ();
    Descender ();
    Agachar ();
    Agarrar();
    Subir ();
    Ascender ();
    GirarLadoIzquierdo();
    Descender();
    Agachar();
    Abrir();
    Subir();
    Ascender();
    delay(4000);
    break;

    case'o':
    Abrir();
    motorBase.write(140);
    delay(1000);
    motorDerecho.write(160);
    delay(1000);
    motorIzquierdo.write(100);
    Agarrar();
    Subir();
    Ascender();
    GirarLadoIzquierdo();
    Descender();
    Agachar();
    Abrir();
    Subir();
    Ascender();
    delay(4000);
    break;

    case'u':
    Abrir();
    motorBase.write(80);
    delay(1000);
    motorDerecho.write(150);
    delay(1000);
    motorIzquierdo.write(60);
    delay(1000);
    Agarrar();
    Subir();
    Ascender();
    GirarLadoIzquierdo();
    Descender();
    Agachar();
    Abrir();
    Subir();
    Ascender();
    delay(4000);
    break;
    
    
   case 'b':
   m= ((s[1]-48)*100)+((s[2]-48)*10)+((s[3]-48));
   motorBase.write (m);
   break; 
   
   case 'g':
   m= ((s[1]-48)*100)+((s[2]-48)*10)+((s[3]-48));
   motorMano.write (m);
   break;
   
   case 'd':
   m= ((s[1]-48)*100)+((s[2]-48)*10)+((s[3]-48));
   motorDerecho.write (m);
   break;
   
   case 'i':
   m= ((s[1]-48)*100)+((s[2]-48)*10)+((s[3]-48));
   motorIzquierdo.write (m);
   break;

   
  }
}
}
void Abrir (void)
{
  motorMano.write(0);
  delay(1000);
}
void Agarrar (void)
{
  motorMano.write(110);
  delay(1000);
}
void GirarCentro (void)
{
  motorBase.write(90);
  delay(1000);
}
void Descender (void)
{
  motorDerecho.write(140);
  delay(1000);
}
void Agachar (void)
{
motorIzquierdo.write(50);
delay(1000);
}
void Subir (void)
{
  motorIzquierdo.write(90);
  delay(1000);
}
void Ascender (void)
{
  motorDerecho.write(90);
  delay(1000);
}
void GirarLadoIzquierdo (void)
{
  motorBase.write(180);
  delay(1000);
}
