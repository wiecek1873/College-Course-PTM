#include <Keypad.h>
#include <LiquidCrystal.h>
#define inputSize 16

int number1 = 0;
int number2 = 0;
char input[16];
byte counter = 0;
char operation;

const byte ROWS = 4;
const byte COLS = 4;

char buttons[ROWS][COLS] = 
{
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

byte pinyRzedow[ROWS] = { A2,A3,A4,A5};
byte pinyKolumn[COLS] = { 8,9,10,11 }; 

Keypad kpd = Keypad( makeKeymap(buttons), pinyRzedow, pinyKolumn, ROWS, COLS);
LiquidCrystal lcd(2,3,4,5,6,7);

void inputClear()
{
    for(int i = 0; i < inputSize; ++i)
    {
      input[i] = 0;
    }
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.cursor();
  lcd.write("Kalkulator");
  delay(1000);
  lcd.clear();
}

void loop()
{
  input[counter] = kpd.waitForKey();
  lcd.write(input[counter]);
  if(input[counter] == 'C' )
  {
    counter = -1;
    inputClear();
    number1 = 0;
    number2 = 0;
    lcd.clear();
    lcd.setCursor(0,0);
  }
  
  if(input[counter] == '+' || input[counter] == '-' || input[counter] == '/' || input[counter] == '*')
  {
    operation = input[counter];
    counter = -1;
    number1 = atoi(input);
    inputClear();
    lcd.setCursor(0,1);
  }

  if(input[counter] == '=')
  {
    counter = 0;

    number2 = atoi(input);
    
    int result = 0;
    char resultArr[16];
    switch(operation)
    {
      case '+':
        result = number1 + number2;
        break;
      case '-':
        result = number1 - number2;
        break;
      case '*':
        result = number1 * number2;
        break;
      case '/':
        result = number1 / number2;
        break;
      default:
      break;
    }

    lcd.clear();
    lcd.write("=");
    Serial.println(result);
    itoa(result,resultArr,10);
    lcd.write(resultArr);

    inputClear();
    number1 = 0;
    number2 = 0;
    
    input[counter] = kpd.waitForKey();
    lcd.clear();
    lcd.write(input[counter]);
    
  }
  ++counter;
}
