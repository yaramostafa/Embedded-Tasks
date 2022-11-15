#include "types.h"
#include "tmc4.h"
#include "bitwise_operation.h"
void DIO_init(void)
{
  SYSCTL_RCGCGPIO_R|=0x20; // 
  while((SYSCTL_PRGPIO_R & 0x20)!= 0x20);
  GPIO_PORTF_LOCK_R = 0x4C4E434B;
  GPIO_PORTF_CR_R |= 0x0E;
  GPIO_PORTF_DIR_R|= 0x0E;
  GPIO_PORTF_DEN_R|= 0x0E;
}

void DIO_WritePort(ulong32_ptr port,ulong32 value)
{
  *port = value;
}

void DIO_WritePin(ulong32_ptr port,uint8 pin,uint8 value)
{
  //*port &= (value << pin);
  if(value == 1)
  {
    setBit(*port , pin);
  }
  else if (value == 0)
  {
    clearBit(*port, pin);
  }
}

uint8 DIO_ReadPin(ulong32_ptr port,uint8 pin)
{
  return getBit(*port,pin);
}

uint32 DIO_ReadPort(ulong32_ptr port)
{
  return *(port);
}
