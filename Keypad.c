#include "DIO.h"
#include "tm4c123gh6pm.h"

void KeyPad_Init(void)
{
  SYSCTL_RCGCGPIO_R|=0x10; //clk =1 at port E
  while((SYSCTL_PRGPIO_R & 0x10)!= 0x10); //actual clk value check 
  GPIO_PORTE_LOCK_R = 0x4C4E434B;
  GPIO_PORTE_CR_R |= 0xF; 
  GPIO_PORTE_DIR_R|= 0xF;
  GPIO_PORTE_DEN_R|= 0xF;
  
  SYSCTL_RCGCGPIO_R|=0x4; //clk =1 at port C
  while((SYSCTL_PRGPIO_R & 0x4)!= 0x4); //actual clk value check 
  GPIO_PORTC_LOCK_R = 0x4C4E434B;
  GPIO_PORTC_CR_R = 0xF0; 
  GPIO_PORTC_DIR_R= 0x00;
  GPIO_PORTC_PDR_R|= 0xF0;
  GPIO_PORTC_DEN_R|= 0xFF;
  
  SYSCTL_RCGCGPIO_R|=0x2; //clk =1 at port B
  while((SYSCTL_PRGPIO_R & 0x2)!= 0x2); //actual clk value check 
  GPIO_PORTB_LOCK_R = 0x4C4E434B; 
  GPIO_PORTB_CR_R |= 0x7F;
  GPIO_PORTB_DIR_R|= 0x7F;
  //GPIO_PORTB_PDR_R|= 0x8;
  GPIO_PORTB_DEN_R|= 0x7F;
}

uint8 KeyPad_Read(void)
{
  uint8 table[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'E','0','F','D'}
  };
  
 
  for(int i=0;i<4;i++){
    
    DIO_WritePort(&GPIO_PORTE_DATA_R,(1<<i));
    uint32 port = DIO_ReadPort(&GPIO_PORTC_DATA_R)&0xF0;
    
    if(port == 0x10){return table[3-i][3];}
    else if(port == 0x20){return table[3-i][2];}
    else if(port == 0x40){return table[3-i][1];}
    else if(port == 0x80){return table[3-i][0];}
    
  }
  return '0';
}

void SevenSegment_Display()
{
  uint8 port = KeyPad_Read();
  switch(port){
  case 'A':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x77);
    break;
  case 'B':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x7C);
    break;
  case 'C':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x39);
    break;
  case 'D':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x5E);
    break;
  case 'E':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x79);
    break;
  case 'F':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x71);
    break;
  case '0':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x3F);
    break;
  case '1':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x06);
    break;
  case '2':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x5B);
    break;
  case '3':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x4F);
    break;
  case '4':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x66);
    break;
  case '5':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x6D);
    break;
  case '6':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x7D);
    break;
  case '7':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x07);
    break;
  case '8':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x7F);
    break;
  case '9':
    DIO_WritePort(&GPIO_PORTB_DATA_R,0x6F);
    break;
  }
}
