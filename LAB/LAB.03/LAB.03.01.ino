#include <Servo.h>
Servo myservo;
int pos = 0;
const int MINPULSE = 575;
const int MAXPULSE = 2325;

void setup() {

  myservo.attach(3, MINPULSE, MAXPULSE);

}

void loop() {

  myservo.write(0);
  delay(2000);

  myservo.write(180);
  delay(2000);

}
