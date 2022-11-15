#ifndef KEY_H
  #define KEY_H

#include "types.h"
#include "DIO.h"
void KeyPad_Init(void);
uint8 KeyPad_Read(void);
void SevenSegment_Display();
#endif