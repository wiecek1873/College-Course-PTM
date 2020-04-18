#include "TM1637.h"
#define CLK 2
#define DIO 3

TM1637 tm1637(CLK,DIO);

void checkValues(int *arr)
{
  for(int counter = 3; counter > 0 ; --counter)
  {
    if(arr[counter] == 10)
    {
      arr[counter] = 0; 
      arr[counter - 1] += 1; 
    } 
  }
}

void setup()
{
  tm1637.init();
  tm1637.set(2);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop()
{
  int arr[] = {0,0,0,0};
  
  for(arr[3] = 0; arr[3] < 11; ++arr[3])
  {
    checkValues(arr);
    tm1637.display(0,arr[0]);
    tm1637.display(1,arr[1]);
    tm1637.display(2,arr[2]);
    tm1637.display(3,arr[3]);
    delay(100);
  }
}
