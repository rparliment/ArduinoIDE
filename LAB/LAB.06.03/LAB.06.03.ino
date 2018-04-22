void setup()
{  
pinMode(13,OUTPUT);
Serial.begin(9600);
}
void loop()
{
static int count=0;
count ++;
if(count>200)
{
  digitalWrite(13,HIGH);
  if(count>400)
  {
    count=0;
    digitalWrite(13,LOW);
  }
}
}


