double getDistance(unsigned char triggerPin, unsigned char echoPin); // This is a "Function 

void setup() {   
  
    Serial.begin(9600); 
          
    pinMode(8, OUTPUT);
    pinMode(7, INPUT); 
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
  }                     
void loop() {  
  
  double targetDistance;  
  targetDistance = getDistance(8, 7);      
  Serial.println(targetDistance);            
  delay(500);          
}
  double getDistance(unsigned char triggerPin, unsigned char echoPin){    
  unsigned long int startTime, endTime;         
  double in;
  digitalWrite(triggerPin, HIGH);              
  delayMicroseconds(20);                        
  digitalWrite(triggerPin, LOW);              
  startTime = micros();
  while(digitalRead(echoPin)==LOW && micros()-startTime<100000){
    delayMicroseconds(20);  
    }
  while(digitalRead(echoPin)==HIGH && micros()-startTime<100000){    
  delayMicroseconds(1);         
    }
  endTime = micros();
  if (endTime>startTime){  
  in = (endTime-startTime)/164.9476;      
    }
  delay(100);  
  if(in>12){
    digitalWrite(A0,HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
  }
  else{
    if(in>8){
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    }
    else{
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    }
  }   

  return(in);
  }                  


