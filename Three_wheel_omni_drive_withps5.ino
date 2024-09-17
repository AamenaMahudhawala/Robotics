//THIS IS A THREE WHEELED DRIVE WITH OMNI WHEELS USING ESP32 AND A PS5 CONTROLLER
//-------------------------------------------------------------------------------
//Ps5controller library refer: https://github.com/rodneybakiskan/ps5-esp32 
#include <ps5Controller.h>

//PINOUTS ON ESP32 
//FM -> FRONT MOTOR,LM-> LEFT MOTOR,RM->RIGHT MOTOR
//PWM-> PINS FOR PWM,DIR-> PINS FOR DIRECTION
int FMpwm=16,FMdir=4,LMpwm=23,LMdir=22,RMpwm=19,RMdir=21; //Replace with respective pinouts 
  //assign the stick values to float variables
  float lx=ps5.LStickX();
  float ly=ps5.LStickY();
  float rx=ps5.RStickX();

//-------------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  //Begin connection
  ps5.begin("88:03:4C:93:FE:13"); //replace with MAC address of your controller
  
 
    while (ps5.isConnected()==0) {
    Serial.println("Connecting...");
    }
  Serial.println("Ready.");

  //defining pin outs
  pinMode(FMpwm,OUTPUT);
  pinMode(LMpwm,OUTPUT);
  pinMode(RMpwm,OUTPUT);
  pinMode(FMdir,OUTPUT);
  pinMode(LMdir,OUTPUT);
  pinMode(RMdir,OUTPUT);
  delay(1000);
  }
//function to map the values recieved from the joysticks to pwm values as per motor requirement 
float mapp(float control){
  float z;
  if((-128<=control)&&(control<=-30))
  {
    z=map(control,-30,-128,0,225);
  }
  else if((30<=control)&&(control<=128))
  {
    z=map(control,30,128,0,225);
  }
  else
  z =0;
  return z;
}
 //Functions for movement:
//-------------------------------------------------------------------------------
  void forward(float control){

    float z = mapp(control);
    
    analogWrite(FMpwm,0);
    digitalWrite(LMdir,HIGH);
    analogWrite(LMpwm,z);
    digitalWrite(RMdir,LOW);
    analogWrite(RMpwm,z);
    Serial.println("IAM IN FORWARD");
    delay(300);
    Serial.printf("Left Stick x at %d\n", ps5.LStickX());
    Serial.printf("Left Stick y at %d\n", ps5.LStickY());
    Serial.printf("Right Stick x at %d\n", ps5.RStickX());
    Serial.printf("Right Stick y at %d\n", ps5.RStickY());


  }

  void back(float control){
    float z = mapp(control);
    
    analogWrite(FMpwm,0);
    digitalWrite(LMdir,LOW);
    analogWrite(LMpwm,z);
    digitalWrite(RMdir,HIGH);
    analogWrite(RMpwm,z);
    Serial.println("IAM IN BACK");
    delay(300);
    Serial.printf("Left Stick x at %d\n", ps5.LStickX());
    Serial.printf("Left Stick y at %d\n", ps5.LStickY());  
    Serial.printf("Right Stick x at %d\n", ps5.RStickX());
    Serial.printf("Right Stick y at %d\n", ps5.RStickY());
  }

  void right (float control)
  {     float z = mapp(control);
    digitalWrite(FMdir,HIGH);
    analogWrite(LMpwm,z);
    digitalWrite(RMdir,LOW);
    analogWrite(RMpwm,z);
    digitalWrite(LMdir,LOW);
    analogWrite(LMpwm,z);
        Serial.println("IAM IN RIGHT");
    delay(300);
    Serial.printf("Left Stick y at %d\n", ps5.LStickY());
    Serial.printf("Left Stick y at %d\n", ps5.LStickY());
    Serial.printf("Right Stick x at %d\n", ps5.RStickX());
    Serial.printf("Right Stick y at %d\n", ps5.RStickY());

  }

  void left(float control){
    float z = mapp(control);
    digitalWrite(FMdir,LOW);
    analogWrite(FMpwm,z);
    digitalWrite(RMdir,HIGH);
    analogWrite(RMpwm,z);
    digitalWrite(LMdir,HIGH);
    analogWrite(LMpwm,z);
        Serial.println("IAM IN LEFT");
    delay(300);
    Serial.printf("Left Stick x at %d\n", ps5.LStickX());
    Serial.printf("Left Stick y at %d\n", ps5.LStickY());
    Serial.printf("Right Stick x at %d\n", ps5.RStickX());
    Serial.printf("Right Stick y at %d\n", ps5.RStickY());
  }

void stop(){
    digitalWrite(FMdir,LOW);
    analogWrite(FMpwm,0);
    digitalWrite(RMdir,HIGH);
    analogWrite(RMpwm,0);
    digitalWrite(LMdir,HIGH);
    analogWrite(LMpwm,0);
        Serial.println("IAM IN STOP");
    delay(300);
    Serial.printf("Left Stick x at %d\n", ps5.LStickX());
    Serial.printf("Left Stick y at %d\n", ps5.LStickY());
        Serial.printf("Right Stick x at %d\n", ps5.RStickX());
    Serial.printf("Right Stick y at %d\n", ps5.RStickY());
}

  void Clk(float control){
    float z = mapp(control);
    digitalWrite(FMdir,HIGH);
    analogWrite(FMpwm,z);
    digitalWrite(RMdir,HIGH);
    analogWrite(RMpwm,z);
    digitalWrite(LMdir,HIGH);
    analogWrite(LMpwm,z);
        Serial.println("IAM IN CLOCK");
    delay(300);
    Serial.printf("Right Stick x at %d\n", ps5.RStickX());
    Serial.printf("Right Stick y at %d\n", ps5.RStickY());
    Serial.printf("Left Stick x at %d\n", ps5.LStickX());
    Serial.printf("Left Stick y at %d\n", ps5.LStickY());
  
    }

    void antiClk(float control){
    float z = mapp(control);
    digitalWrite(FMdir,LOW);
    analogWrite(FMpwm,z);
    digitalWrite(RMdir,LOW);
    analogWrite(RMpwm,z);
    digitalWrite(LMdir,LOW);
    analogWrite(LMpwm,z);
        Serial.println("IAM IN ANTICLOCK");
    delay(300);
    Serial.printf("Right Stick x at %d\n", ps5.RStickX());
    Serial.printf("Right Stick y at %d\n", ps5.RStickY());
    Serial.printf("Left Stick x at %d\n", ps5.LStickX());
    Serial.printf("Left Stick y at %d\n", ps5.LStickY());
  }
//-------------------------------------------------------------------------------

//main loop
void loop() {
  //update stick values
  lx=ps5.LStickX();
 ly=ps5.LStickY();
 rx=ps5.RStickX();

 //based on controls and movement of joystick  move the drive 
 if (ly < -30) {
    forward(ly);
  } else if (ly > 30) {
    back(ly);
  } else if (lx > 30) {
    right(lx);
  } else if (lx < -30) {
    left(lx);
  } else if (rx < -30) {
    Clk(rx);
  } else if (rx > 30) {
    antiClk(rx);
  } else {
    stop(); //if no data/signal recieved stop moving
  }
}
