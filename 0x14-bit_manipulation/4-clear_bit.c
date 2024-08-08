#include "main.h"

/**
* clear_bit - A function that sets the value of a bit to 0
* at a given index
* @n: Pointer to the number to be modified
* @index: The index of the bit to clear
*
* Return: 1 if succesful, -1 if error
*/

int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned int maximum_bits = sizeof(unsigned long int) * 8;

if (index >= maximum_bits)
{
return (-1);
}

*n &= ~(1UL << index);

return (1);
}
