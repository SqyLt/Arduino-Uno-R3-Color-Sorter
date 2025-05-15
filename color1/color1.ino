#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Servo.h>

// 初始化TCS34725传感器
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

Servo topServo; 
Servo bottomServo;
int color = 0;

void setup() {
  Serial.begin(9600);
  // 初始化颜色传感器
  if (!tcs.begin()) {
    Serial.println("TCS34725未连接!");
    while (1);
  }
  // 舵机初始化
  topServo.attach(7);
  bottomServo.attach(8);
  topServo.write(175);
  delay(5000); // 等待系统稳定
}

void loop() {
  topServo.write(175);
  delay(300);
  
  // 舵机到检测位置
  for(int i = 175; i >= 100; i -= 2) {
    topServo.write(i);
    delay(20);
  }
  delay(300);
  
  // 检测颜色并分拣
  color = readColor();
  delay(300);  
  switch (color) {
    case 1:
      bottomServo.write(10); // 棕色分拣位置
      break;
    case 2:
      bottomServo.write(40); // 蓝色分拣位置
      break; 
    case 3:
      bottomServo.write(70); // 橙色分拣位置
      break; 
    case 4:
      bottomServo.write(100); // 绿色分拣位置
      break; 
    case 5:
      bottomServo.write(130); // 红色分拣位置
      break; 
    case 6:
      bottomServo.write(160); // 黄色分拣位置
      break;  
    case 0:
      break; // 未知颜色不动作
  }
  delay(300);
  
  // 转动并复位
  for(int i = 75; i >= 5; i -= 2) {
    topServo.write(i);
    delay(20);
  } 
  delay(200);
  for(int i = 5; i <= 175; i += 2) {
    topServo.write(i);
    delay(20);
  }
  color = 0;
}

// 颜色检测函数
int readColor() {
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c); // 读取RGB值

  Serial.print("R="); Serial.print(r);
  Serial.print(" G="); Serial.print(g);
  Serial.print(" B="); Serial.println(b);

  // 阈值
  if (r > 400 && r < 600 && g > 400 && g < 620 && b >300 && b < 500) return 1;//棕
  if (r > 350 && r < 500 && g > 650 && g < 850 && b >680 && b < 880) return 2;//蓝
  if (r > 1000 && r < 1550 && g > 680 && g < 850 && b >370 && b < 550) return 3;//橙
  if (r > 630 && r < 880 && g > 980 && g < 1500 && b >480 && b < 700) return 4;//绿
  if (r > 600 && r < 880 && g > 470 && g < 630 && b >330 && b < 530) return 5;//红
  if (r > 1000  && g > 1000  && b >450 ) return 6;//黄
  return 0;
}