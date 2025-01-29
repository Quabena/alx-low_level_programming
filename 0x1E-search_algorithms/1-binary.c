#include "search_algos.h"

/**
 * binary_search - A function that searches for a value in a sorted array
 * using binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is found, or -1 if not found
 */

int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid, i;

	if (!array)
		return (-1);

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
			printf("%d%s", array[i], i == right ? "\n" : ", ");

		mid = left + (right - left) / 2;
		if (array[mid] == value)
			return ((int)mid);
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
