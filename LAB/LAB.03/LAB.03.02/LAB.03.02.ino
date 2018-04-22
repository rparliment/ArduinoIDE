const int NUMFLOORS=5;
int delayTimes[NUMFLOORS+1];

int currentFloor=1;

void setup() {

pinMode(3, OUTPUT);

delayTimes[1]= 575;
delayTimes[2] = 1050;
delayTimes[3] = 1500;
delayTimes[4] = 1950;
delayTimes[5] = 2325;

Serial.begin(9600);
}

void loop() {
  
 char myChar;
 unsigned long int highTime = 1500;
 unsigned long int lowTime = 18500;
 
 while(1){

  if(Serial.available()>0){
  myChar = Serial.read();
 }
if(myChar>='1' && myChar <='0'+NUMFLOORS){
  currentFloor = myChar - '0';
}
highTime = delayTimes[currentFloor];
lowTime = 20000 - highTime;

digitalWrite(3, HIGH);
delayMicroseconds(highTime);

digitalWrite(3, LOW);
delayMicroseconds(lowTime);
}
}

