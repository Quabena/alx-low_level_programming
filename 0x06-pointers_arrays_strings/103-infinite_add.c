#include "main.h"

/**
 * infinite_add - A function that adds two numbers represented as strings.
 * @n1: The first number string.
 * @n2: The second number string.
 * @r: The buffer to store the result.
 * @size_r: The buffer size.
 *
 * Return: Pointer to the result if it fits in the buffer, otherwise 0.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int len1 = 0, len2 = 0, i, j, k, carry = 0, digit_sum;

while (n1[len1] != '\0') len1++;
while (n2[len2] != '\0') len2++;

i = len1 - 1;
j = len2 - 1;
k = 0;

while (i >= 0 || j >= 0 || carry)
{
if (k >= size_r - 1)

return (0);

digit_sum = carry;
if (i >= 0) digit_sum += n1[i--] - '0';
if (j >= 0) digit_sum += n2[j--] - '0';

carry = digit_sum / 10;
r[k++] = (digit_sum % 10) + '0';
}

if (k >= size_r)

return (0);

r[k] = '\0';

for (i = 0, j = k - 1; i < j; i++, j--)
{
char temp = r[i];
r[i] = r[j];
r[j] = temp;
}

return (r);
}
