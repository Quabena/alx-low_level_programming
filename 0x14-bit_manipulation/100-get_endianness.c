#include "main.h"

/**
* get_endianness - A function that checks the endianness of the system
*
* union - A system function call
* Return: 0 if big endian or 1 if little endian
*/

int get_endianness(void)
{
int m;
char *n;

m = 1;
n = (char *)&m;

return (*n);
}
