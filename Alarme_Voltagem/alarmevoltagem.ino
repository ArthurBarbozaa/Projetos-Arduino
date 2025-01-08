// C++ code
//
float volt = A0;
int del = 400;
int pVermelho = 4;
int pAmarelo = 3;
int pVerde = 2;
int buzz = 5;
void setup()
{

  pinMode(pVerde, OUTPUT);
  pinMode(pAmarelo, OUTPUT);
  pinMode(pVermelho, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop()
{
  volt = analogRead(A0)*(5.0/1023.0);
  
  if(volt < 2.5){
    digitalWrite(pAmarelo,LOW);
    digitalWrite(pVermelho,LOW);
    digitalWrite(pVerde, HIGH);
  }
  else if(volt >=2.5 && volt <=3.75){
    digitalWrite(pAmarelo,HIGH);
    digitalWrite(pVermelho,LOW);
    digitalWrite(pVerde, LOW);
  }
  else{
    digitalWrite(pAmarelo,LOW);
    digitalWrite(pVermelho,HIGH);
    digitalWrite(pVerde, LOW);
    tone(buzz,500,100);
    delay(del);
  }
  delay(200);
}
