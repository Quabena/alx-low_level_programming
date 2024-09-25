#include "main.h"

/**
* _strspn - gets the length of a prefix substring
* @s: string to search
* @accept: string containing the characters to match
*
* Return: number of bytes in the initial segment of s which consist
* only of bytes from accept
*/

unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int match;
char *temp_accept;

while (*s != '\0')
{
match = 0;
temp_accept = accept;

while (*temp_accept != '\0')
{
if (*s == *temp_accept)
{
count++;
match = 1;
break;
}
temp_accept++;
}

if (!match)
{
break;
}

s++;
}

return (count);
}
