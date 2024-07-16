#include "main.h"
#include <stdlib.h>

/**
* _strdup - A function that returns a pointer to a newly
* allocated space in memory,
* which contains a copy of the string given as a parameter.
* @str: string to duplicate
* Return: pointer to the duplicated string, or NULL if str is NULL or
* if memory allocation fails
*/

char *_strdup(char *str)
{
char *dup_str;
unsigned int i, length = 0;

if (str == NULL)
return (NULL);

while (str[length] != '\0')
length++;

dup_str = malloc(sizeof(char) * (length + 1));

if (dup_str == NULL)
return (NULL);

for (i = 0; i < length; i++)
dup_str[i] = str[i];

dup_str[length] = '\0';

return (dup_str);
}
