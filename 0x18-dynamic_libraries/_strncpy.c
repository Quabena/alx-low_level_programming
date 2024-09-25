#include "main.h"

/**
* _strncpy - Copies at most n bytes from src to dest
* @dest: Pointer to the destination string
* @src: Pointer to the source string copy
* @n: Maximum number of bytes to copy from src
* Return: Pointer to the resulting string dest
*/

char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[i] = src[i];
}

for (; i < n; i++)
{
dest[i] = '\0';
}

return (dest);
}
