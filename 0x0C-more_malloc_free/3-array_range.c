#include <stdlib.h>
#include "main.h"

/**
* array_range - A function that creates an array of integers
* from min to max inclusive.
* @min: The minimum value to include in the array.
* @max: The maximum value to include in the array.
* Return: Pointer to the newly created array, or NULL if min > max
* or if malloc fails.
*/

int *array_range(int min, int max)
{
int *array;
int i, size;

if (min > max)
{
return (NULL);
}

size = max - min + 1;
array = malloc(size *sizeof(int));
if (array == NULL)
{
return (NULL);
}

for (i = 0; i < size; i++)
{
array[i] = min + i;
}

return (array);
}
