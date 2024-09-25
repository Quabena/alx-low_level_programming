#include "main.h"

/**
* _isupper - A C program that checks for uppercase character
* @c: Character to check
*
* Return: Always 0 (Sucess)
*
*/

int _isupper(int c)
{
if (c >= 'A' && c <= 'Z')
{
return (1);
}
else
{
return (0);
}
}
