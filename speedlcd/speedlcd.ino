#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);   //defining lcd pins

const int dataIN = 2; //IR sensor INPUT

unsigned long prevmillis; // To store time
unsigned long duration; // To store time difference
unsigned long lcdrefresh; // To store time for lcd to refresh

int rpm1; // RPM value
int rpm2;

boolean currentstate; // Current state of IR input scan
boolean prevstate; // State of IR sensor in previous scan

void setup()
{
  pinMode(dataIN,INPUT);
  lcd.begin(16,2);     
  prevmillis = 0;
  prevstate = LOW;  
}

void loop()
{
 // RPM Measurement
  currentstate = digitalRead(dataIN); // Read IR sensor state
 if( prevstate != currentstate) // If there is change in input
   {
     if( currentstate == HIGH ) // If input only changes from LOW to HIGH
       {
         duration = ( micros() - prevmillis ); // Time difference between revolution in microsecond
         rpm1 = (60000000/duration); // rpm = (1/ time millis)*1000*1000*60;
         prevmillis = micros(); // store time for next revolution calculation
         rpm2=((2*3.14*0.3937*rpm1)/60)*3.6;
       }
   }
  prevstate = currentstate; // store this scan (prev scan) data for next scan
  // LCD Display
  if( ( millis()-lcdrefresh ) >= 100 )
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("RPM =");
      lcd.print(rpm1);
      lcd.setCursor(0,1);
      lcd.print("km/h = ");
      lcd.print(rpm2);         
      lcdrefresh = millis();   
    }

}