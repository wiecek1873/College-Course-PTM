#define przycisk 7
#define led 8
void setup() 
{
  pinMode(przycisk,INPUT_PULLUP);
  pinMode(led, OUTPUT);

  digitalWrite(led,LOW);
}

void loop() 
{
  if(digitalRead(przycisk) == LOW)
    digitalWrite(led,HIGH);
  else
    digitalWrite(led,LOW);

}
