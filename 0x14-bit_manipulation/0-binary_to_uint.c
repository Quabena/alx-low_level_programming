#include "main.h"

/**
* binary_to_uint - A function that converts a binary number to
* an unsigned int.
* @b: A string of 0 and 1 characters.
* Return: The converted number, or 0 for invalid inputs
*/

unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0;

if (b == NULL)
{
return (0);
}

for (; *b != '\0'; b++)
{
if (*b != '0' && *b != '1')
{
return (0);
}

result = (result << 1) | (*b - '0');
}

return (result);
}
