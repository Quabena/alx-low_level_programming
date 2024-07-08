#include "main.h"

/**
* _strspn - gets the length of a prefix substring
* @s: string to search
* @accept: string containing the characters to match
*
* Return: number of bytes in the initial segment of s which consist only of
* bytes from accept
*/

unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int match;

while (*s != '\0')
{
match = 0;
while (*accept != '\0')
{
if (*s == *accept)
{
count++;
match = 1;
break;
}
accept++;
}
if (!match)
{
break;
}
s++;
accept -= count;
}
return (count);
}
