#include "deneyap.h"
#include "BluetoothSerial.h"
#include <Deneyap_Servo.h>      // Deneyap Servo kütüphanesi eklenmesi 

char gelen;
BluetoothSerial  SerialBT;
Servo servo1;                   // 1. servo motor için class tanımlanması
Servo servo2;                   // 2. servo motor için class tanımlanması
Servo servo3;                   // 3. servo motor için class tanımlanması
Servo servo4;                   // 4. servo motor için class tanımlanması

int servo1Angle = 90; // 1. servo motorun açısı
int servo2Angle = 90; // 2. servo motorun açısı
int servo3Angle = 90; // 3. servo motorun açısı
int servo4Angle = 90; // 4. servo motorun açısı

void setup() {
  SerialBT.begin("MOR");
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);

  servo1.attach(D3);            // 1. servo motorun D3 pinin ve 0 kanal ayarlanması
  servo2.attach(D4, 1);         // 2. servo motorun D4 pinin ve 1 kanal ayarlanması
  servo3.attach(D5, 2);         // 3. servo motorun D5 pinin ve 2 kanal ayarlanması
  servo4.attach(D6, 3);         // 4. servo motorun D6 pinin ve 3 kanal ayarlanması

  servo1.write(servo1Angle);    // 1. servo motorun başlangıç değerinin atanması
  servo2.write(servo2Angle);    // 2. servo motorun başlangıç değerinin atanması
  servo3.write(servo3Angle);    // 3. servo motorun başlangıç değerinin atanması
  servo4.write(servo4Angle);    // 4. servo motorun başlangıç değerinin atanması
}

void loop() {
  if(SerialBT.available()){
    gelen = SerialBT.read();

    if(gelen == 'T') {
      servo1Angle += 5; // 1. servo motorun açısını 5 derece artır
      servo1.write(servo1Angle);
    } else if (gelen == 'G') {
      servo1Angle -= 5; // 1. servo motorun açısını 5 derece azalt
      servo1.write(servo1Angle);
    } else if (gelen == 'Y') {
      servo2Angle += 5; // 2. servo motorun açısını 5 derece artır
      servo2.write(servo2Angle);
    } else if (gelen == 'H') {
      servo2Angle -= 5; // 2. servo motorun açısını 5 derece azalt
      servo2.write(servo2Angle);
    } else if (gelen == 'U') {
      servo3Angle += 5; // 3. servo motorun açısını 5 derece artır
      servo3.write(servo3Angle);
    } else if (gelen == 'J') {
      servo3Angle -= 5; // 3. servo motorun açısını 5 derece azalt
      servo3.write(servo3Angle);
    } else if (gelen == 'I') {
      servo4Angle += 5; // 4. servo motorun açısını 5 derece artır
      servo4.write(servo4Angle);
    } else if (gelen == 'K') {
      servo4Angle -= 5; // 4. servo motorun açısını 5 derece azalt
      servo4.write(servo4Angle);
    } else if (gelen == 'F') {
      digitalWrite(D0, HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D8, HIGH);
      digitalWrite(D9, LOW);
    } else if (gelen == 'B') {
      digitalWrite(D0, LOW);
      digitalWrite(D1, HIGH);
      digitalWrite(D8, LOW);
      digitalWrite(D9, HIGH);
    } else if (gelen == 'L') {
      digitalWrite(D0, LOW);
      digitalWrite(D1, LOW);
      digitalWrite(D8, HIGH);
      digitalWrite(D9, LOW);
    } else if (gelen == 'R') {
      digitalWrite(D0, HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D8, LOW);
      digitalWrite(D9, LOW);
    } else {
      digitalWrite(D0, LOW);
      digitalWrite(D1, LOW);
      digitalWrite(D8, LOW);
      digitalWrite(D9, LOW);
    }
  }
}
