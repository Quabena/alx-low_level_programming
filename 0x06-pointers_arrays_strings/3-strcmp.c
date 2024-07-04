#include "main.h"

/**
* _strcmp - Function that compares two strings s1 and s2
* @s1: Pointer to the first string
* @s2: Pointer to the second string
*
* Return: Negative integer if s1 < s2
* 0 if s1 == s2
* Positive integer if s1 > s2
*/

int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
{
i++;
}

return (s1[i] - s2[i]);
}
