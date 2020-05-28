#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

float inputA0 = 0;
float inputA1 = 0;
float output = 0;

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
  inputA0 = analogRead(A0);
  inputA1 = analogRead(A1);
  output = inputA0 - inputA1;
  if(output < 0)
    output *= -1;
  output = output * 0.0049;
  lcd.print(output);
  delay(200);
  lcd.clear();
}
