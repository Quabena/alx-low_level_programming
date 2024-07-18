#include "main.h"
#include <stdlib.h>

/**
* _realloc - A function that reallocates a memory block.
* @ptr: Pointer to the memory previously allocated with malloc.
* @old_size: Size of the allocated space for ptr.
* @new_size: New size of the new memory block.
* Return: Pointer to the newly allocated memory block, or NULL if new_size
* is zero and ptr is not NULL, or if malloc fails.
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr;
unsigned int i, size_to_copy;

if (new_size == 0)
{
if (ptr != NULL)
{
free(ptr);
}
return (NULL);
}

if (ptr == NULL)
{
return (malloc(new_size));
}

if (new_size == old_size)
{
return (ptr);
}

new_ptr = malloc(new_size);
if (new_ptr == NULL)
{
return (NULL);
}

size_to_copy = (new_size < old_size) ? new_size : old_size;
for (i = 0; i < size_to_copy; i++)
{
new_ptr[i] = ((char *)ptr)[i];
}

free(ptr);

return (new_ptr);
}
