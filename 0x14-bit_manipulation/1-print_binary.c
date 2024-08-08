#include "main.h"

/**
* print_binary - A function that prints the binary representation
* of a number.
* @n: The number to be printed in binary
*/

void print_binary(unsigned long int n)
{
int bit_idx;
int started = 0;

unsigned long int current_bit;

for (bit_idx = sizeof(n) * 8 - 1; bit_idx >= 0; bit_idx--)
{
current_bit = n >> bit_idx;

if (current_bit & 1)
{
_putchar('1');
started = 1;
}
else if (started)
{
_putchar('0');
}
}

if (!started)
{
_putchar('0');
}
}
