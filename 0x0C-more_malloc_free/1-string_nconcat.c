#include <stdlib.h>
#include "main.h"

/**
* string_nconcat - A function that concatenates two strings.
* @s1: First string.
* @s2: Second string.
* @n: Number of bytes from s2 to concatenate.
* Return: Pointer to newly allocated memory containing s1 followed by the
* first n bytes of s2, and null terminated. NULL if memory allocation fails.
*/

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *concat;
unsigned int i, j, len1, len2;

if (s1 == NULL)
{
s1 = "";
}

if (s2 == NULL)
{
s2 = "";
}

for (len1 = 0; s1[len1] != '\0';
len1++);
for (len2 = 0; s2[len2] != '\0';
len2++);

if (n >= len2)
n = len2;

concat = malloc(len1 + n + 1);
if (concat == NULL)
return (NULL);

for (i = 0; i < len1; i++)
concat[i] = s1[i];
for (j = 0; j < n; j++, i++)
concat[i] = s2[j];

concat[i] = '\0';

return (concat);
}
