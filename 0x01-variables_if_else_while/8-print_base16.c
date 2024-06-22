#include <stdio.h>
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
int value = 48;

while (value <= 57)
{
putchar(value);
value++;
}

value = 97;

while (value <= 102)
{
putchar(value);
value++;
}
putchar('\n');

return (0);
}
