//INCLUDING LIBRARIES
#include<Ps3Controller.h>

//DEFINING VARIABLES
int pwmF=27,pwmLB=33,pwmRB=26,DirF=13,DirLB=32,DirRB=25;
float Lx,Rx,Ly,Ry;
//SETUP
void setup() {
  Serial.begin(115200);
  Ps3.begin("00:00:00:00:00:0a");
  Serial.println("Ready.");

  pinMode(pwmF,OUTPUT);
  
  pinMode(pwmLB,OUTPUT);
  pinMode(pwmRB,OUTPUT);
  pinMode(DirF,OUTPUT);
  
  pinMode(DirLB,OUTPUT);
  pinMode(DirRB,OUTPUT);

}
//CONTROLS
void Controls()
{
  Lx=Ps3.data.analog.stick.lx;
  Ly=Ps3.data.analog.stick.ly; 
  Ry=Ps3.data.analog.stick.ry;
  Rx=Ps3.data.analog.stick.rx;
}
//FUNCTIONS FOR DIRECTION
void front()
{
  
  analogWrite(pwmF,0);
  
  
  digitalWrite(DirLB,HIGH);
  analogWrite(pwmLB,150);
  digitalWrite(DirRB,HIGH);
  analogWrite(pwmRB,150);
}


void back()
{
  
  analogWrite(pwmF,0);
  digitalWrite(DirLB,LOW);
  analogWrite(pwmLB,150);
  digitalWrite(DirRB,LOW);
  analogWrite(pwmRB,150);
}

void clockwise()
{

  digitalWrite(DirF,HIGH);
  analogWrite(pwmF,150);

  digitalWrite(DirLB,LOW);
  analogWrite(pwmLB,150);
  digitalWrite(DirRB,HIGH);
  analogWrite(pwmRB,150);
}

void anticlockwise()
{

  digitalWrite(DirF,LOW);
  analogWrite(pwmF,150);

  digitalWrite(DirLB,HIGH);
  analogWrite(pwmLB,150);
  digitalWrite(DirRB,LOW);
  analogWrite(pwmRB,150);
}


void stop()
{
  analogWrite(pwmF,0);
  
  analogWrite(pwmLB,0);
  analogWrite(pwmRB,0);
} 

void Left()
{

  digitalWrite(DirF,LOW);
  analogWrite(pwmF,254);

  digitalWrite(DirLB,LOW);
  analogWrite(pwmLB,127);
  digitalWrite(DirRB,HIGH);
  analogWrite(pwmRB,127);
}

void Right()
{

  digitalWrite(DirF,HIGH);
  analogWrite(pwmF,254);

  digitalWrite(DirLB,HIGH);
  analogWrite(pwmLB,127);
  digitalWrite(DirRB,LOW);
  analogWrite(pwmRB,127);
}


void loop() {
  
  Controls();
  while(Ly<-30)
  {
    front();
    Serial.println(Ly);
    Controls();

  }
  while(Ly>30)
  {
    back();
    Serial.println(Ly);
    Controls();
    
  }
  
  while(Lx<-30)
  {
    Left();
    Serial.println(Lx);
    Controls();

  }
  while(Lx>30)
  {
    Right();
    Serial.println(Lx);
    Controls();
    
  }
  while(Lx==-1.00 && Ly==-1.00)
  {
     stop();
     Serial.println(Lx,Ly);
     Controls();


   }
  while(Rx<-30)
  {

    anticlockwise();
    Serial.println(Rx);
    Controls();

  }

  while(Rx>30)
  {

    clockwise();
    Serial.println(Rx);
    Controls();

  }
  stop();

}
