#include <Servo.h>

#define MAX 180
#define MIN 10

Servo myservo;  // 建立一個 servo 物件，最多可建立 12個 servo

short dir = 0;      // Motor轉的方向
short degree = 0; // Motor轉的單位
int pos = 10;    // 設定 Servo 位置的變數

void setup() {
  Serial.begin(9600);
  myservo.attach(9, 500, 2400);
}

void loop() {
  if(Serial.available() >= 2)
  {
    dir = Serial.read() - 48;
    degree = Serial.read() - 48;
    Serial.println(dir);
    Serial.println(degree);
    if(dir == 0 and (pos + degree) <= MAX)
    {
      pos += degree;
    }
    else if(dir == 1 and (pos - degree) > MIN)
    {
      pos -= degree;
    }
    else if(dir == 2)
    {
      pos = 90;
    }
    myservo.write(pos);
    Serial.println(pos);
    delay(15);
  }
}
