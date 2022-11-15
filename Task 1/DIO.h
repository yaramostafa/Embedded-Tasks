#ifndef DIO_H
  #define DIO_H

void DIO_init(void);
void DIO_WritePort(ulong32_ptr port,ulong32 value);
void DIO_WritePin(ulong32_ptr port,uint8 pin,uint8 value);
uint8 DIO_ReadPin(ulong32_ptr port,uint8 pin);
uint32 DIO_ReadPort(ulong32_ptr port);

#endif