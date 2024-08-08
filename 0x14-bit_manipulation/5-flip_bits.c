#include "main.h"

/**
* flip_bits - A function that returns the number of bits you
* would need to flip to get from one number to another
* @n: First number
* @m: Second number
*
* Return: The number of bits to flip to get from n to m
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int xor_res;
unsigned int count = 0;

xor_res = n ^ m;

while (xor_res)
{
count += xor_res & 1;
xor_res >>= 1;
}

return (count);
}
