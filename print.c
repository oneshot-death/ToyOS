#include "stdint.h"
#include "stdarg.h"
#include "uart.h"

int printk(const char *format, ...) {
    char buffer[1024]; //ensure that the value printed is not larger than thisx
    int buffer_size=0;
    int64_t integer=0; //holds the value we want to show on screen
}