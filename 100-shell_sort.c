#include "sort.h"

/**
 * shell_sort - This function sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 * @array: The array of integers
 * @size: The size of @array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
				int swap = array[b];

				array[b] = array[b - gap];
				array[b - gap] = swap;
				b -= gap;
			}
		}
		print_array(array, size);
	}
}
