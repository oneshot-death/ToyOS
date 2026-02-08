#include "stdint.h"
#include "stdarg.h"
#include "uart.h"

static int read_string(char *buffer,int position, const char *string) {
    int index=0;
    for (index=0; string[index]!='\0'; index++) {
        buffer[position++]=string[index];
    }
    return index; //returns the number of characters being copied
}

int printk(const char *format, ...) {
    char buffer[1024]; //ensure that the value printed is not larger than thisx
    int buffer_size=0;
    int64_t integer=0; //holds the value we want to show on screen
    char *string=0
    va_list args;

    va_start(args,format);

    for (int i=0;format[i]!='\0';i++) {
        if (format[i]!='%') { //if the character is a regular string
            buffer[buffer_size++]=format[i]; 
        }
        else {
            switch (format[++i]) {
                case 'x':
                    break;
                case 'u':
                    break;
                case 'd':
                    break;
                case 's':
                    string= va_arg(args,char*);
                    buffer_size+=read_string(buffer,buffer_size,string);
                break;
                    default:
                    buffer[buffer_size++]='%'
                i--;
            } 
        }
    }
}