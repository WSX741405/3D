#include <Servo.h>

Servo myservo;  // 建立一個 servo 物件，最多可建立 12個 servo

short dir = 0;      // Motor轉的方向
short distance = 0; // Motor轉的單位
int pos = 0;    // 設定 Servo 位置的變數

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // 將 servo 物件連接到 pin 9
}

void loop() {
  Serial.println(".");
  while(Serial.available() <=0); // wait for incoming serial data
  if (Serial.available() >= 2)  // wait for 4 bytes. 
  {
      dir = Serial.read();
      distance = Serial.read();
      Serial.println(dir);
      Serial.println(distance);
      if(dir = 0)
      {
          pos +=1;
          myservo.write(pos);               // 告訴 servo 走到 'pos' 的位置
          delay(15);                        // 等待 15ms 讓 servo 走到指定位置
      }
      else
      {
          pos -= 1;
          myservo.write(pos);               // 告訴 servo 走到 'pos' 的位置
          delay(15);                        // 等待 15ms 讓 servo 走到指定位置
      }
  }
}
