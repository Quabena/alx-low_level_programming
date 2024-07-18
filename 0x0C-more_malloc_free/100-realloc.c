#include "main.h"
#include <stdlib.h>

/**
* _realloc - Reallocates a memory block.
* @ptr: Pointer to the memory previously allocated with malloc.
* @old_size: Size of the allocated space for ptr.
* @new_size: New size of the new memory block.
* Return: Pointer to the newly allocated memory block, or NULL if new_size
* is zero and ptr is not NULL, or if malloc fails.
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr;
char *old_ptr;
unsigned int i;

if (new_size == old_size)
{
return (ptr);
}
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
if (ptr == NULL)
{
return (malloc(new_size));
}
new_ptr = malloc(new_size);
if (new_ptr == NULL)
{
return (NULL);
}
old_ptr = (char *)ptr;
if (new_size < old_size)
{
for (i = 0; i < new_size; i++)
{
new_ptr[i] = old_ptr[i];
}
}
else
{
for (i = 0; i < old_size; i++)
{
new_ptr[i] = old_ptr[i];
}
}
free(ptr);
return (new_ptr);
}
