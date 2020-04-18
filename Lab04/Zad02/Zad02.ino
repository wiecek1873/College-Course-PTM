#include "TM1637.h"
#define CLK 2
#define DIO 3

TM1637 tm1637(CLK,DIO);

void setup()
{
  tm1637.init();
  tm1637.set(5);//Range 0~7
}

void loop()
{
  int arr[] = {0,0,0,0};
  
  for(arr[3] = 0; arr[3] < 11; ++arr[3])
  {
    if(arr[3] == 10)
    {
      arr[2] += 1;
      arr[3] = 0;
    }
    if(arr[2] == 6)
    {
      arr[2] = 0;
      arr[1] += 1;
    }
    if(arr[1] == 10)
    {
      arr[0] += 1;
      arr[1] = 0; 
    }
    tm1637.point(true);
    tm1637.display(0,arr[0]);
    tm1637.display(1,arr[1]);
    tm1637.display(2,arr[2]);
    tm1637.display(3,arr[3]);
    delay(1000);
  }
}
