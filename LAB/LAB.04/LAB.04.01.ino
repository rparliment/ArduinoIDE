void setup() {
  pinMode(A2,INPUT);
  Serial.begin(9600);

}

void loop() {
  analogRead(A2);
  float lux = analogRead(A2)*5.0/1023;
  
  if(lux>4){
    Serial.println("it spooky time");
    delay(100);
    }
    else{
      if(lux>3){
        Serial.println("wow so dark");
        delay(100);
      }
      else{
        if(lux>2){
          Serial.println("spongebob is still on tv atm");
          delay(100);
        }
        else{
        if(lux>1){
          Serial.println("babbys first bedtime");
          delay(100);
        }
        else{
          Serial.println("Lux is the SI unit for Illuminance");
          delay(100);
        }
      }
     
  }
}
}
