#ifndef _LIB_H //if the library is not defined, define it (will not be necessary if you run it later on)
#define _LIB_H

#include "stdint.h"

void delay(uint64_t value);
void out_word(uint64_t addr, uint32_t value);
uint32_t in_word(uint64_t addr);

#endif

