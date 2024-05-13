
//INCLUDING LIBRARIES
#include<Ps3Controller.h>

//Variables initialized
int pwmLF=33,pwmRF=27,pwmLB=19,pwmRB=17,DirLF=32,DirRF=26,DirLB=18,DirRB=16;
float Lx,Rx,Ly,Ry,i,k;

//SETUP
void setup() {
  //SERIAL MONITOR COMMUNICATION
  Serial.begin(115200);
  Ps3.begin("00:00:00:00:00:0a");//CONNECT WITH THE PS3 CONTROLLER
  Serial.println("Ready.");

  pinMode(pwmLF,OUTPUT);
  pinMode(pwmRF,OUTPUT);
  pinMode(pwmLB,OUTPUT);
  pinMode(pwmRB,OUTPUT);
  pinMode(DirLF,OUTPUT);
  pinMode(DirRF,OUTPUT);
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

void Map()
{
   i = Ry;
   k = map(-1,128,0,255);
}

//FUNCTIONS FOR MOVEMENT
void front()
{
  digitalWrite(DirLF,HIGH);
  analogWrite(pwmLF,k);
  digitalWrite(DirRF,HIGH);
  analogWrite(pwmRF,k);
  digitalWrite(DirLB,HIGH);
  analogWrite(pwmLB,k);
  digitalWrite(DirRB,HIGH);
  analogWrite(pwmRB,k);
  Ry=Ps3.data.analog.stick.ry;
}


void back()
{
  digitalWrite(DirLF,LOW);
  analogWrite(pwmLF,k);
  digitalWrite(DirRF,LOW);
  analogWrite(pwmRF,k);
  digitalWrite(DirLB,LOW);
  analogWrite(pwmLB,k);
  digitalWrite(DirRB,LOW);
  analogWrite(pwmRB,k);
  Ry=Ps3.data.analog.stick.ry;
}

void clockwise()
{

  digitalWrite(DirLF,HIGH);
  analogWrite(pwmLF,k);
  digitalWrite(DirRF,LOW);
  analogWrite(pwmRF,k);
  digitalWrite(DirLB,HIGH);
  analogWrite(pwmLB,k);
  digitalWrite(DirRB,LOW);
  analogWrite(pwmRB,k);
  Ry=Ps3.data.analog.stick.ry;
}

void anticlockwise()
{

  digitalWrite(DirLF,LOW);
  analogWrite(pwmLF,k);
  digitalWrite(DirRF,HIGH);
  analogWrite(pwmRF,k);
  digitalWrite(DirLB,LOW);
  analogWrite(pwmLB,k);
  digitalWrite(DirRB,HIGH);
  analogWrite(pwmRB,k);
  Ry=Ps3.data.analog.stick.ry;
}


void stop()
{
  analogWrite(pwmLF,0);
  analogWrite(pwmRF,0);
  analogWrite(pwmLB,0);
  analogWrite(pwmRB,0);
} 

void Left()
{

  digitalWrite(DirLF,LOW);
  analogWrite(pwmLF,k);
  digitalWrite(DirRF,HIGH);
  analogWrite(pwmRF,k);
  digitalWrite(DirLB,HIGH);
  analogWrite(pwmLB,k);
  digitalWrite(DirRB,LOW);
  analogWrite(pwmRB,k);
  Ry=Ps3.data.analog.stick.ry;
}

void Right()
{
  digitalWrite(DirLF,HIGH);
  analogWrite(pwmLF,k);
  digitalWrite(DirRF,LOW);
  analogWrite(pwmRF,k);
  digitalWrite(DirLB,LOW);
  analogWrite(pwmLB,k);
  digitalWrite(DirRB,HIGH);
  analogWrite(pwmRB,k);
  Ry=Ps3.data.analog.stick.ry;
}

//MAIN PROGRAM
void loop() {
  
  Controls();
  Map();
  
  if(Ly<-30)
  {while(Ly<-30)
  {
    front();
    Serial.println(Ly);
    Controls();
    Map();

  }}
  else if(Ly>30)
  {
  while(Ly>30)
  {
    back();
    Serial.println(Ly);
    Controls();
    Map();
    
  }}
  else if(Lx<-30){
  while(Lx<-30)
  {
    Left();
    Serial.println(Lx);
    Controls();
    Map();

  }}
  else if (Lx>30){
  while(Lx>30)
  {
    Right();
    Serial.println(Lx);
    Controls();
    Map();    
  }}
 
  else if(Rx<-30)
  {
  while(Rx<-30)
  {
    anticlockwise();
    Serial.println(Rx);
    Controls();
    Map();
  }}
  else if(Rx>30)
  {
  while(Rx>30)
  {
    clockwise();
    Serial.println(Rx);
    Controls();
    Map();
  }}
  else
  stop();

}