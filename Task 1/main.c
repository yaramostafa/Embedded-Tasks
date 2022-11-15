#include "types.h"
#include "tmc4.h"
#include "DIO.h"
#include "bitwise_operation.h"

#include <stdio.h>
#include <time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 100 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
 


int main()
{
  
  DIO_init();
  while(1){ 
  DIO_WritePort(&GPIO_PORTF_DATA_R,0x02);
  delay(1);
  printf("%d",DIO_ReadPin(&GPIO_PORTF_DATA_R,0x1));
  DIO_WritePort(&GPIO_PORTF_DATA_R,0x04);
  delay(1);
  printf("%d",DIO_ReadPin(&GPIO_PORTF_DATA_R,0x2));
  DIO_WritePort(&GPIO_PORTF_DATA_R,0x08);
   delay(1);
  printf("%d",DIO_ReadPin(&GPIO_PORTF_DATA_R,0x3));
  DIO_WritePin(&GPIO_PORTF_DATA_R,3,2);
  printf("%d",DIO_ReadPort(&GPIO_PORTF_DATA_R));}
  
  return 0;
}
