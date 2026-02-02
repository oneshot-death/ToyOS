#include "uart.h"
#include "lib.h"

void write_char(unsigned char c)
{
    while (in_word(UART0_FR) & (1 << 5)) { } //wait until the transmit fifo is not full
    out_word(UART0_DR, c); //sends data to the register
}

unsigned char read_char(void)
{
    while (in_word(UART0_FR) & (1 << 4)) { } //wait until data is in the recieve buffer (essentially checking for flags)
    return in_word(UART0_DR);
}

void write_string(const char *string) //sends string onto the console
{
    for (int i = 0; string[i] != '\0'; i++) {
        write_char(string[i]); //loops by char
    }
}

void init_uart(void)
{
    out_word(UART0_CR, 0);
    out_word(UART0_IBRD, 26);
    out_word(UART0_FBRD, 0);
    out_word(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));
    out_word(UART0_IMSC, 0); //masks interrupts for this example
    out_word(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9)); //enables reciever and transmitter of rpi3
}
