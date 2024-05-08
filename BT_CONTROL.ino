#include "deneyap.h"
#include "BluetoothSerial.h";

char gelen;

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
  SerialBT.begin("MOR");
  pinMode(D0,OUTPUT);
    pinMode(D1,OUTPUT);//SOL
  pinMode(D8,OUTPUT);
    pinMode(D9,OUTPUT);//SAğ
}

void loop() {
  // put your main code here, to run repeatedly:

if(SerialBT.available()){
  gelen=SerialBT.read();
  if(gelen=='F')
  {
    digitalWrite(D0,HIGH);
    digitalWrite(D1,LOW);
    
    digitalWrite(D8,HIGH);
    digitalWrite(D9,LOW);
    }

  else if(gelen=='B'){
    digitalWrite(D0,LOW);
    digitalWrite(D1,HIGH);
    
    digitalWrite(D8,LOW);
    digitalWrite(D9,HIGH);
    }
   else if(gelen=='L'){
    digitalWrite(D0,HIGH);
    digitalWrite(D1,LOW);
    
    digitalWrite(D8,LOW);
    digitalWrite(D9,LOW);
    } 

       else if(gelen=='R'){
    digitalWrite(D0,LOW);
    digitalWrite(D1,LOW);
    digitalWrite(D8,HIGH);
    digitalWrite(D9,LOW);
    } 

    else {
          digitalWrite(D0,LOW);
    digitalWrite(D1,LOW);
    digitalWrite(D8,LOW);
    digitalWrite(D9,LOW);
      }
  }
}
