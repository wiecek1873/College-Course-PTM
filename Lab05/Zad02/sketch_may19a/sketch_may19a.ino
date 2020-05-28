#include <LiquidCrystal.h>
#include <stdlib.h>
LiquidCrystal lcd(2,3,4,5,6,7);

unsigned int inputA0 = 0;
char output[16];

int countDigits(char *str)
{
  int counter = 0;
  while(str[counter] != '\0')
  {
    ++counter;
  }
  return counter;
}


void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.cursor();
  lcd.write("Woltomierz");
  delay(100);
  lcd.clear();
}

void loop()
{
  for(int i = 0; i < 16; ++i)
  {
    output[i] = '0';
  }
  inputA0 = analogRead(A0);
  inputA0 *= 49;
  sprintf(output,"%u",inputA0);
  int numberOfZeros = 5 - countDigits(output);
  int i = 0;
  while(output[i] != '\0')
  {
    ++i;
  }
  --i;
  while(i != 0)
  {
    output[i+numberOfZeros] = output[i];
    --i;
  }
  while(i < numberOfZeros)
  {
    output[i] = '0';
    i++;
  }
  
  lcd.print(output[0]);
  lcd.print(",");
  lcd.print(output[1]);
  lcd.print(output[2]);
  lcd.print(output[3]);
  lcd.print(output[4]);

    Serial.println(output);
        

  delay(100);
  lcd.clear();
}
