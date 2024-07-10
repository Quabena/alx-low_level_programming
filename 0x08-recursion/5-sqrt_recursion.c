#include "main.h"
#include <stdio.h>

int _sqrt(int n, int i);

/**
* _sqrt_recursion - returns the natural square root of a number
* @n: the number to find the square root of
*
* Return: the natural square root of n, or -1 if n does not
* have a natural square root
*/

int _sqrt_recursion(int n)
{
return (_sqrt(n, 1));
}

/**
* _sqrt - A function that calculates natural square root
* @n: number to calculate the square root of
* @i: iteration number
* Return: the natural square root
*/

int _sqrt(int n, int i)
{
int sqrt = i * i;

if (sqrt > n)
return (-1);

if (sqrt == n)
return (i);

return (_sqrt(n, i + 1));
}
