#include "main.h"

/**
* reverse_array - A function that reverses the content of an of integers
* @a: Pointer to the array of integers
* @n: Number of elements in the array
*/

void reverse_array(int *a, int n)
{
int i, temp;

for (i = 0; i < n / 2; i++)
{
temp = a[i];
a[i] = a[n - i - 1];
a[n - i - 1] = temp;
}
}
