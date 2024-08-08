#include "main.h"

/**
* set_bit - A function that sets the value of a bit to 1
* at a given index.
* @n: Pointer to the number to modify
* @index: The index of the bit to set
*
* Return: 1 if success, or -1 if error.
*/

int set_bit(unsigned long int *n, unsigned int index)
{
unsigned int maximum_bits = sizeof(unsigned long int) * 8;

if (index >= maximum_bits)
{
return (-1);
}

*n |= (1UL << index);

return (1);
}
