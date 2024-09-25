#include "main.h"

/**
* _memset - A function that fills memmory with a constant byte
* @s: pointer to the memory area
* @b: the byte to fill the memory
* @n: the number of bytes to fill
* Return: pointer (s) to the memory
*/

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
s[i] = b;
}

return (s);
}
