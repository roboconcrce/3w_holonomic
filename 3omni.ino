#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX
int data;
const int ENA = 11;
const int IN1 = 12;
const int IN2 = 13;
const int ENB = 3;
const int IN3 = 2;
const int IN4 = 4;
const int ENC = 10;
const int IN5 = 9;
const int IN6 = 8;

void plsstop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
}


void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }


  //Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
  while (!mySerial){
    ;
  }
  //mySerial.println("Hello, world?");
   //Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  //pinMode(SER, OUTPUT);
}

void setRobotSpeed (float xSpeed, float ySpeed, float wSpeed){
  setMotorSpeed(ENA, float(-0.22*xSpeed), float(0.60*ySpeed), float(0.33*wSpeed));
  setMotorSpeed(ENB, float(-0.18*xSpeed), float(-0.63 *ySpeed), float(0.33*wSpeed));
  setMotorSpeed(ENC, float(-0.96*xSpeed), 0, float(0.33*wSpeed));
}

void setMotorSpeed(int motorEnable, float pwmx, float pwmy, float pwmw){
  float all = pwmx + pwmy + pwmw;
  float unall;
  if (all > 0)
    unall = all;
  else 
    unall = -all;
    
  
  switch(motorEnable)
  {
  case ENA:
    if (pwmx > 0){
      analogWrite(ENA, unall);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }else if (pwmx < 0){
            analogWrite(ENA, unall);
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
           }
    if (pwmy > 0){
      analogWrite(ENA, unall);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }else if (pwmy < 0){
            analogWrite(ENA, unall);
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
           }
     if (pwmw > 0){
      analogWrite(ENA, unall);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }else if (pwmw < 0){
            analogWrite(ENA, unall);
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
           }
     break;
   case ENB:
    if (pwmx > 0){
      analogWrite(ENB, unall);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }else if (pwmx < 0){
            analogWrite(ENB, unall);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
           }
    if (pwmy > 0){
      analogWrite(ENB, unall);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }else if (pwmy < 0){
            analogWrite(ENB, unall);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
           }
     if (pwmw > 0){
      analogWrite(ENB, unall);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }else if (pwmw < 0){
            analogWrite(ENB, unall);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
           }
     break;
   case ENC:
   if (pwmx > 0){
      analogWrite(ENC, unall);
      digitalWrite(IN5, LOW);
      digitalWrite(IN6, HIGH);
    }else if (pwmx < 0){
            analogWrite(ENC, unall);
            digitalWrite(IN5, HIGH);
            digitalWrite(IN6, LOW);
           }
    if (pwmy > 0){
      analogWrite(ENC, unall);
      digitalWrite(IN5, HIGH);
      digitalWrite(IN6, LOW);
    }else if (pwmy < 0){
            analogWrite(ENC, unall);
            digitalWrite(IN5, LOW);
            digitalWrite(IN6, HIGH);
           }
     if (pwmw > 0){
      analogWrite(ENC, unall);
      digitalWrite(IN5, HIGH);
      digitalWrite(IN6, LOW);
    }else if (pwmw < 0){
            analogWrite(ENC, unall);
            digitalWrite(IN5, LOW);
            digitalWrite(IN6, HIGH);
           }
     break;
  }
}

void loop() // run over and over
{
  if (mySerial.available())
  {
  char c = (mySerial.read());
  Serial.print("c");
  Serial.print(c);
  int d = (int)(c - '0');
  Serial.print("d");
  Serial.print(d);
  //delay(1000);
  //Serial.print("lol \n");
  //Serial.print(mySerial.read());
  //data = (mySerial.read());
  //Serial.print("data \n");
  //Serial.print(data);
  if ((d == 1))
  {
    Serial.print("Go Forward");
    for (int i = 0; i<251; i++){
      setRobotSpeed(0,i,0);
      //delay(10);
    }
    
  }
   if ((d == 2))
  {
    Serial.print("Go Right");
        for (int i = 0; i<251; i++){
      setRobotSpeed(i,0,0);
      //delay(10);
    }
  }
   if ((d == 3))
  {
    Serial.print("Go Left");
        for (int i = 0; i>(-251); i--){
      setRobotSpeed(i,0,0);
     // delay(10);
    }
  }
   if ((d == 4))
  {
    Serial.print("Go Back");
        for (int i = 0; i<251; i++){
      setRobotSpeed(0,-i,0);
      //delay(50);
    }
  }
   if ((d == 5))
  {
    Serial.print("Stop");
    plsstop();
  }
  //delay(500);
  }
}
    //data = (mySerial.read());
    //Serial.println("data");
    //Serial.println(data);
    //int cond = mySerial.read();
    //Serial.println(cond);
 // if (Serial.available())
   // mySerial.write(Serial.read());
