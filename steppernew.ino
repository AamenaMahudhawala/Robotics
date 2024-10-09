#include <ps5.h>
#include <ps5Controller.h>
#include <ps5_int.h>


int count = 1000;

int z = 2000;
#define stepPin1 25 //esp 32 pins
#define dirPin1 26 

void setup() {
  pinMode(stepPin1,OUTPUT);
  pinMode(dirPin1,OUTPUT);

ps5.begin("88:03:4C:93:FE:13");
}

void loop() {

  if (ps5.Square()) {
    digitalWrite(dirPin1, HIGH); 
   while (ps5.Square()) {
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(z);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(z);
   }
  }
 if ( ps5.Circle()) {
   digitalWrite(dirPin1, LOW); 
   while ( ps5.Circle()) {
       
      digitalWrite(stepPin1, HIGH);       
      delayMicroseconds(z);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(z);
    }
  }
}