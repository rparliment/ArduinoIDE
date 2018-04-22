double getDistance(unsigned char triggerPin, unsigned char echoPin);
void setup() {  
  
   Serial.begin(9600);      
   pinMode(8, OUTPUT);
   pinMode(7, INPUT); 

  }                     

void loop() {  
 
  double targetDistance;  
  targetDistance = getDistance(8, 7);      
  Serial.println(targetDistance);            
  delay(500);  
        
}

  double getDistance(unsigned char triggerPin, unsigned char echoPin){ 
  unsigned long int startTime, endTime;        
  double mm;
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
    mm = (endTime-startTime)/6.496;     
    }
  delay(100);        
  
  return(mm);
  }                  

