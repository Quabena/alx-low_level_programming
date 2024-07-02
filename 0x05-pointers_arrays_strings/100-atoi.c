#include "main.h"

/**
* _atoi - A function that converts a string to an integer
* @s: The pointer to convert
* Return: An integer
*/

int _atoi(char *s)
{
int a = 0;
unsigned int i = 0;
int min = 1;
int b = 0;

while (s[a])
{
if (s[a] == 45)
{
min *= -1;
}

while (s[a] >= 48 && s[a] <= 57)
{
b = 1;
i = (i * 10) + (s[a] - '0');
a++;
}

if (b == 1)
{
break;
}

a++;
}
i *= min;

return (i);
}
