#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE , SCL, SDA);

  float num1;
  float num2;
  float num3;
  float float1;
  float float2;
  float float3;
  
void setup(void) {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  
  u8g2.setFont(u8g2_font_logisoso54_tf);
  u8g2.setFontPosTop();
  post();
  Serial.begin(9600);
}

 void OLED0(void){
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  u8g2.setDisplayRotation(U8G2_R2);
  }
  void OLED1(void){
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  u8g2.setDisplayRotation(U8G2_R2);
  }
  void OLED2(void){
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  u8g2.setDisplayRotation(U8G2_R0);
  }

  void post(void){
  OLED0(); //initializes and clear OLED buffers
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.drawStr(0,5,"POST");
  u8g2.sendBuffer();
  u8g2.clearBuffer();
  delay(1);
  OLED1();
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.drawStr(0,5,"POST");
  u8g2.sendBuffer();
  u8g2.clearBuffer();
  delay(1);
  OLED2();
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.drawStr(0,5,"POST");
  u8g2.sendBuffer();
  u8g2.clearBuffer();
  delay(1);
  }
  
void loop(void) {
  num1 = random(1,1000);
  float1 = num1/100;
  num2 = random(1000,10000);
  float2 = num2/100;
  num3 = random(10000,100000);
  float3 = num3/100;
  
  //pass one
  OLED0();
  u8g2.clearBuffer();
  u8g2.setCursor(0, 5);
  u8g2.print(float1,2);
  u8g2.sendBuffer();
  delay(10);
  
  OLED1();
  u8g2.clearBuffer();
  u8g2.setCursor(0, 5);
  u8g2.print(float2,1);
  u8g2.sendBuffer();
  delay(10);

  OLED2();
  u8g2.clearBuffer();
  u8g2.setCursor(0, 5);
  u8g2.print(float3,0);
  u8g2.sendBuffer();
  delay(10);

}

