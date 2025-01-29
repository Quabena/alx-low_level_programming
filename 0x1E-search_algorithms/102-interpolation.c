#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array using
 *                        the Interpolation Search algorithm.
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in the array
 * @value: value to search for
 * Return: first index where value is located or -1 if not found
 */

int interpolation_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	size_t low = 0, high = size - 1;
	size_t pos;

	while (low <= high && value >= array[low] && value <= array[high])
	{
		/* Calculate the probe position */
		pos = low + (((double)(high - low) / (array[high] -
						      array[low])) * (value - array[low]));

		/* Check for out of range position */
		if (pos >= size)
		{
			printf("Value checked array[%zu] is out of range\n", pos);
			break;
		}

		printf("Value checked array[%zu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	return (-1);
}
