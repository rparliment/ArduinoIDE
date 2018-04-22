void setup()
{  
pinMode(8,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop()
{
static int state=0;
if(digitalRead(8)==LOW)
{
  if(state==0)
  {
    digitalWrite(13,LOW);
  }
  else(digitalWrite(13,HIGH));
}

if(digitalRead(8)==HIGH)
{
  delay(10);
  if(state==0,digitalRead(13)==LOW)
  {
    state=1;
  }
  else(state=0);
}

}


