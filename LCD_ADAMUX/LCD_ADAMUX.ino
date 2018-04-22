#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <StopWatch.h>
#define TCAADDR 0x70
#define R0  U8G2_R0
#define R90  U8G2_R1
#define R180  U8G2_R2
#define R270  U8G2_R3

// OLED complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE , SCL, SDA);
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE , SCL, SDA); //if errors try this constructor

//random numbers to test code, delete later
 
float rpmspeed;
float rpmdist;
float braketime;
StopWatch sw_millis;
StopWatch sw_millis.stop();
float elapse = float(sw_millis.elapsed())/1000;

//mux channel select
void muxsel(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void setup(void) {
  Serial.begin(9600);//del when done debug

  Wire.begin(); //initialize i2c interface

  pinMode(A0, INPUT); //'core' thermocouple analog input
  pinMode(A1, INPUT); //'inner' thermocouple analog input
  pinMode(A2, OUTPUT); //unused analog pin
  pinMode(A3, OUTPUT); //unused analog pin
  pinMode(7, OUTPUT); //mux reset pin
  pinMode(8, OUTPUT); //i2c voltage reference

  digitalWrite(A2, LOW); //prevents A2 acting as an antenna
  digitalWrite(A3, LOW); //prevents A3 acting as an antenna

  //reset the mux on setup
  digitalWrite(7, LOW);
  delay(10);
  digitalWrite(7, HIGH);
  delay(200);

  digitalWrite(8, HIGH); //i2c pullup reference

  //initializes the displays
  for (uint8_t i = 0; i < 7; i++) {
    muxsel(i);
    u8g2.begin();
    u8g2.setFont(u8g2_font_logisoso54_tf);
    u8g2.setFontPosTop();
    u8g2.clearBuffer();
    u8g2.drawStr(-3, 5, "POST");
    u8g2.sendBuffer();
  }
}

// tc amp select & output in celsius based on 5v logic
float tcamp(String probe) {
  if (probe == "core") {
    return (((((analogRead(A0) * 5.0) / 1023.0)) - 1.25) / 0.005);
  }
  if (probe == "inner") {
    return (((((analogRead(A1) * 5.0) / 1023.0)) - 1.25) / 0.005);
  }
}

//calling oled displays for output
void oled(uint8_t i, float data, int rotate = R0) {
  muxsel(i);
  u8g2.clearBuffer();
  u8g2.setCursor(0, 5);
  u8g2.setDisplayRotation(rotate);
  if (data >= 0.01 && data <= 9.99) {
    u8g2.print(data, 2);
  }
  else if (data >= 10.0 && data <= 99.9) {
    u8g2.print(data, 1);
  }
  else if (data >= 100 && data <= 999) {
    u8g2.print(data, 0);
  }
  else if (data > 999) {
    u8g2.drawStr(0, 5, "O/L");
  }
  else {
    u8g2.print(0.00, 2);
  }
  u8g2.sendBuffer();
}

void loop(void) {
  if (elapse == 0.00) {
    sw_millis.start();
  }
  if (rpmspeed == braketime) {
    sw_millis.reset();
  }
  rpmspeed = random(0, 1000);
  braketime = random(0, 1000);
  oled(0, elapse);
  oled(2, tcamp("core"), R180);
  oled(1, rpmspeed);
  Serial.println(sw_millis.elapsed());
}

