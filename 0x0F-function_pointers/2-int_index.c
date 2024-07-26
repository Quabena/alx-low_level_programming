#include "function_pointers.h"

/**
* int_index - A function that searches for an integer.
* @array: The integer array
* @size: The size of the array
* @cmp: Pointer to the function to compare values
* Return: Index of first element, or -1 if no element matches or
* if size is less than or equal to 0
*/

int int_index(int *array, int size, int (*cmp)(int))
{
int itrt;

if (array == NULL || cmp == NULL || size <= 0)
{
return (-1);
}

for (itrt = 0; itrt < size; itrt++)
{
if (cmp(array[itrt]) != 0)
{
return (itrt);
}
}

return (-1);
}
