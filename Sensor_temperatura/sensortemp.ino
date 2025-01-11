// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int led1 = 11;
int led2 = 10;
int buzz = 8;
float volt;
float sens;
float temp;
Adafruit_LiquidCrystal lcd(0);

void setup()
{
  pinMode(buzz,OUTPUT);
  lcd.begin(16,2);
  pinMode(led2,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{ 
  
 sens = analogRead(A0);
 volt = sens * (5.0/1024.0);
 temp = (volt - 0.5) * 100;
  
 if(temp >= 40){
 digitalWrite(led2, LOW);
 digitalWrite(led1, HIGH);
 lcd.setCursor(0,0);
 lcd.print("Temperatura:");
 lcd.print(temp);
 lcd.setCursor(4,1);
 lcd.print("CUIDADO!"); 
 noTone(buzz);
 tone(buzz,600,50);
 
 }else{
 digitalWrite(led1, LOW);
 digitalWrite(led2, HIGH);
 lcd.setCursor(2,0);
 lcd.print("Temperatura:");
 lcd.setCursor(5,1);
 lcd.print(temp);
 }
  delay(100);
}
