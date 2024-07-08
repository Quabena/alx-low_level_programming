#include "main.h"
#include <stdio.h>

/**
* print_diagsums - A function that prints the sum of the diagonals
* of a square matrix
* @a: pointer to the square matrix
* @size: size of the matrix (number of rows or columns)
*/

void print_diagsums(int *a, int size)
{
int sum1 = 0, sum2 = 0;
int i;

for (i = 0; i < size; i++)
{
sum1 += *(a + i * size + i);
}

for (i = 0; i < size; i++)
{
sum2 += *(a + i * size + (size - 1 - i));
}

printf("%d, %d\n", sum1, sum2);
}
