#include "main.h"

/**
 * leet - A function that Encodes a string into "1337".
 * @str: Pointer to the string to encode.
 *
 * Return: Pointer to the modified string str.
 */
char *leet(char *str)
{
char *ptr = str;
char leet_map[] = "4433007711";
int i;

while (*ptr != '\0')
{

for (i = 0; "aAeEoOtTlL"[i] != '\0'; i++)
{
if (*ptr == "aAeEoOtTlL"[i])
{
*ptr = leet_map[i];
break;
}
}
ptr++;
}

return (str);
}
