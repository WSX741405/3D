#include <Servo.h>

#define MAX 180

Servo myservo;  // 建立一個 servo 物件，最多可建立 12個 servo

short dir = 0;      // Motor轉的方向
short dis = 0; // Motor轉的單位
int pos = 5;    // 設定 Servo 位置的變數

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // 將 servo 物件連接到 pin 9
}

void loop() {
  if(Serial.available() >= 2)
  {
    dir = Serial.read() - 48;
    dis = Serial.read() - 48;
    Serial.println(dir);
    Serial.println(dis);
    if(dir == 0 and (pos + dis) < MAX)
    {
      pos += dis;
    }
    else if(dir == 1 and (pos - dis) > 5)
    {
      pos -= dis;
    }
    else if(dir == 2)
    {
      pos = 5;
    }
  }
  myservo.write(pos);
  delay(15);
  Serial.println(pos);
}
