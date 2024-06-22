#include <stdio.h>
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
int alphabet = 122;

while (alphabet >= 97)
{
putchar(alphabet);
alphabet--;
}

putchar('\n');

return (0);
}
