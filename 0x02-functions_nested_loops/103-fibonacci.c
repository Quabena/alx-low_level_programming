#include <stdio.h>

/**
* main - Entry point
*
* Description: Prints the sum of Even Fibonnaci numbers
* less than 4000000
*
* Return: Always 0 (Success)
*/

int main(void)
{
int i = 0;
long n = 1, p = 2, sum = p;

while (p + n < 4000000)
{
p += n;
if (p % 2 == 0)
sum += p;
n = p - n;
++i;
}
printf("%ld\n", sum);

return (0);
}
