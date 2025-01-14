// C++ code
//
int ledVermelho = 5;
int ledAmarelo = 4;
int ledVerde = 3;
int buzz = 2;
int trig = 9;
int echo = 8;
int duracao, cm;
void setup()
{

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duracao = pulseIn(echo, HIGH);
  cm = (duracao/2) / 29.1;
  
  if(cm <= 35){
   digitalWrite(ledVermelho, HIGH);
   digitalWrite(ledVerde, LOW);
   digitalWrite(ledAmarelo, LOW);
   tone(buzz, 700, 80); 
    delay(100);
  }
  else if(cm > 35 && cm < 60){
   digitalWrite(ledVermelho, LOW);
   digitalWrite(ledVerde, LOW);
   digitalWrite(ledAmarelo, HIGH);
   tone(buzz, 500, 200); 
    delay(300);
  }
  else{
   digitalWrite(ledVermelho, LOW);
   digitalWrite(ledAmarelo, LOW);
   digitalWrite(ledVerde, HIGH);
   tone(buzz, 400, 250);
   delay(500);
  }
  
 
  delay(300);
  noTone(buzz);
}
