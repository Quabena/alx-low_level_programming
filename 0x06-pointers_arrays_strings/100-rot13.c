#include "main.h"

/**
 * rot13 - A function that encodes a string using ROT13 cipher.
 * @str: Pointer to the string to encode.
 *
 * Return: Pointer to the modified string str.
 */
char *rot13(char *str)
{
int i, j;

char data1[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

char datarot[] =
"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

for (i = 0; str[i] != '\0'; i++)
{
for (j = 0; j < 52; j++)
{
if (str[i] == data1[j])
{
str[i] = datarot[j];
break;
}
}
}

return (str);
}
