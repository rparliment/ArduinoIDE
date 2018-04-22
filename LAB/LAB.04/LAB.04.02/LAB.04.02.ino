void setup() {
  pinMode(9,OUTPUT);    //blue
  pinMode(10,OUTPUT);   //green
  pinMode(11,OUTPUT);   //red
  pinMode(5,OUTPUT);    //gnd
  digitalWrite(5, HIGH);    //sets gnd to 0v
}

void doLED(int blue, int green, int red){

  red = red & 0xFF;
  green = green & 0xFF;
  blue = blue & 0xFF;

  analogWrite(11, 255-red);
  analogWrite(10, 255-green);
  analogWrite(9, 255-blue);

  }

void loop() {
  
    doLED(0,0,0);   //off
  delay(500);
  
    doLED(255,0,0); //red  
  delay(500);

    doLED(200,20,0); //orange  
  delay(500);

    doLED(200,75,0); //yellow  
  delay(500);

    doLED(0,255,0); //green  
  delay(500);
  
    doLED(0,200,100); //cyan  
  delay(500);

    doLED(0,0,255); //blue  
  delay(500);

    doLED(255,0,255); //purple 
  delay(500);

    doLED(100,20,100); //magenta
  delay(500);

    doLED(255,240,240); //white  
  delay(500);
}

