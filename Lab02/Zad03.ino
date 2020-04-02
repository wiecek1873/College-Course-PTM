#include <Keypad.h>

const byte RZEDOW = 1;
const byte KOLUMN = 4;

char przyciski[RZEDOW][KOLUMN] = {'1','2','3','4'};

byte pinyLedow[] = {14,15,16,17};
byte pinyRzedow[RZEDOW] = {7};
byte pinyKolumn[KOLUMN] = { 8,9,10,11 }; 

Keypad kpd = Keypad( makeKeymap(przyciski), pinyRzedow, pinyKolumn, RZEDOW, KOLUMN );

void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 4; i++)
  {
    pinMode(pinyLedow[i],OUTPUT);
    digitalWrite(pinyLedow[i],LOW);
  }

}

void loop()
{
  char key = kpd.getKey();
  switch (key)
  {
    case '1':
      digitalWrite(pinyLedow[0],HIGH);
      while(digitalRead(8) == HIGH) {}
      digitalWrite(pinyLedow[0],LOW);
    break;
    
    case '2':
      digitalWrite(pinyLedow[1],HIGH);
      while(digitalRead(9) == HIGH) {}
      digitalWrite(pinyLedow[1],LOW);
    break;
    
    case '3':
      digitalWrite(pinyLedow[2],HIGH);
      while(digitalRead(10) == HIGH) {}
      digitalWrite(pinyLedow[2],LOW);
    break;
    
    case '4':
      digitalWrite(pinyLedow[3],HIGH);
      while(digitalRead(11) == HIGH) {}
      digitalWrite(pinyLedow[3],LOW);
    break;
     
    default:
    break;
    }
    Serial.println(key);
}
