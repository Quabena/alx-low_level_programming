#include "main.h"

/**
* more_numbers - a function that prints 10 times the numbers,
* from 0 to 14
*
*/

void more_numbers(void)
{
int a, b;

for (a = 0; a < 10; a++)
{
for (b = 0; b < 15; b++)
{
if (b >= 10)

_putchar(b / 10 + '0');
_putchar(b % 10 + '0');

}
_putchar('\n');
}
}
