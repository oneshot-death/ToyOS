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

static int hex_to_string(char *buffer, int position, uint64_t digits) {
    char digits_buffer[25]; //to save the converted digits
    char digit_map[16]="0123456789ABCDEF";
    int size=0;

    while (digits!=0)
    {
        digits_buffer[size++]=digit_map[digits%16];
        digits/=16;

    }
    while (int i=size-1;i>=0;i--)
    {
        buffer[position++]=digits_buffer[i]; //since we converteed ts from right to left
    }
    buffer[position++]='x';
    buffer[position++]='0';
        
    return size+2;

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
                case 'x': //hexadecimal value
                    buffer_size+= hex_to_string(buffer,buffer_size,(uint64_t)integer)
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