#include "main.h"

/**
* get_bit - A function that returns the value of a bit at
* a given index
* @n: The number to search
* @index: The index of the bit to retrieve
*
* Return: The value of the bit, or -1 if error occured
*/

int get_bit(unsigned long int n, unsigned int index)
{
unsigned int maximum_bits;

maximum_bits = sizeof(unsigned long int) * 8;

if (index >= maximum_bits)
{
return (-1);
}

return ((n >> index) & 1);
}
