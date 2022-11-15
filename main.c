#include "types.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "bitwise_operation.h"
#include <stdio.h>
#include <time.h>
#include "tasks.h"
#include "Keypad.h"
 
volatile int counter = 0;

int main()
{
  int counter1 = 0;
  //KeyPad_Init();
  while(1)
  { 
    //printf("%d \n",x);
    int i ;
    for(i=0;i<5;i++){
      counter++;
      counter1++;
    }
  }
  return 0;
}

