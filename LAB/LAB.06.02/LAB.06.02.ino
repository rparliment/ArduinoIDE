void setup()
{  
pinMode(8,INPUT);
pinMode(13,OUTPUT);
pinMode(A2,INPUT);
Serial.begin(9600);
}

void loop()
{
static int state=0;
analogRead(A2);
float lux = analogRead(A2)*5.0/1023;
static int count;

if(lux<1)
{
  count=0;
  state=0;
}
if(state==1)
{
  count++;
  if(count>1000)
  {
    state=0;
    count=0;
  }
}

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

Serial.println(lux);
}


