// C++ code
//
int luz = 13;
int sensor = 4;
int state = 0;
void setup()
{
  pinMode(luz, OUTPUT);
  pinMode(sensor,INPUT);
}

void loop()
{
  state = digitalRead(sensor);
  if(state == HIGH){
   digitalWrite(luz, HIGH); 
   delay(7000);
  }
  else{
   digitalWrite(luz, LOW); 
  }
  delay(100); 
}
