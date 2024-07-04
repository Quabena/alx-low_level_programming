#include "main.h"

/**
 * rot13 - A function that encodes a string using ROT13 cipher.
 * @str: Pointer to the string to encode.
 *
 * Return: Pointer to the modified string str.
 */
char *rot13(char *str)
{
char *ptr = str;
int i;

while (*ptr != '\0')
{

for (i = 0; i < 26; i++)
{
if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z'))
{
if ((*ptr >= 'a' && *ptr <= 'm') || (*ptr >= 'A' && *ptr <= 'M'))
{
*ptr = *ptr + 13;
}
else
{
*ptr = *ptr - 13;
}
}
}
ptr++;
}

return (str);
}
