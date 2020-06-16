#define LED_R 8
#define LED_B 12
#define BUTTON 2
 
void setup() 
{
  pinMode(LED_R, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_B, LOW);
  attachInterrupt(digitalPinToInterrupt(BUTTON), blink, LOW);
}
 
void loop() 
{
    digitalWrite(LED_B, HIGH);
    delay(1000);
    digitalWrite(LED_B, LOW);
    delay(1000);  
}
 
void blink()
{
    digitalWrite(LED_R, HIGH);
    delay(20);
    digitalWrite(LED_R, LOW);
    delay(20);  
}
