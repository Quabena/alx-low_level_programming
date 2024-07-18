#include "main.h"
#include <stdlib.h>

/**
* _calloc - A function that allocates memory for an array
* and initializes it to zero.
* @nmemb: Number of elements.
* @size: Size of each element.
* Return: Pointer to the allocated memory, initialized to zero. NULL if
* nmemb or size is 0 or if malloc fails.
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
char *ptr;
unsigned int total_size, i;

if (nmemb == 0 || size == 0)
{
return (NULL);
}

total_size = nmemb * size;

ptr = malloc(total_size);
if (ptr == NULL)
{
return (NULL);
}

for (i = 0; i < total_size; i++)
{
ptr[i] = 0;
}

return (ptr);
}
