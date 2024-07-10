#include "main.h"

/**
* wildcmp - compares two strings and considers them identical
* @s1: the first string to compare
* @s2: the second string to compare, can contain *
* Return: 1 if strings can be considered identical, 0 otherwise
*/

int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
return (1);

if (*s2 == '\0')
return (0);

if (*s1 == *s2 || *s2 == '*')
{

if (*s1 == *s2)
return (wildcmp(s1 + 1, s2 + 1));

if (*s2 == '*')
return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));

return (0);
}

return (0);
}
