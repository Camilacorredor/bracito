#include <Servo.h>
#include <SoftwareSerial.h>

#define pinBase 12 
#define pinDerecho 11 
#define pinIzquierdo 10 
#define pinMano 9 


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


SoftwareSerial BT(3,2);

void setup() 

{

motorBase.attach(pinBase);
motorDerecho.attach(pinDerecho); 
motorIzquierdo.attach(pinIzquierdo); 
motorMano.attach(pinMano); 

Serial.begin(9600);
BT.begin(9600); 
motorMano.write(5);
motorBase.write(90); 

}

int t;

char s[6];
void loop() 

{
  
if(Serial.available()>0&&Serial.available()<=6)

 {
  
  BT.readBytes(s,6);
  BT.println(s);
  switch(s[0])
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
    
    case'b':
    t=((s[1]-48)*100)+((s[2]-48)*10)+(s[3]-48);
    
    motorBase.write(t);
    Serial.println(t);
    break;
    
    case'd':
    t=((s[1]-48)*100)+((s[2]-48)*10)+(s[3]-48);
    
    motorDerecho.write(t);
    Serial.println(t);
    break;
    
    case'i':
    t=((s[1]-48)*100)+((s[2]-48)*10)+(s[3]-48);
    
    motorIzquierdo.write(t);
    Serial.println(t);
    break;

    case'g':
    t=((s[1]-48)*100)+((s[2]-48)*10)+(s[3]-48);
    
    motorMano.write(t);
    Serial.println(t);
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
  motorMano.write(30);
  delay(1000);
}
void GirarCentro (void)
{
  motorBase.write(105);
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
