#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: void
 */
void swap_ints(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

/**
 * lomuto_quicksort - Implement the quicksort algorithm using
 * the Lomuto partition scheme
 * @array: The array of integers to sort
 * @size: The size of @array
 * @left: The starting index of @array
 * @right: The ending index of @array
 *
 * Return: void
 */
void lomuto_quicksort(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int above = left, below;

	if (right <= left)
		return;

	for (below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	lomuto_quicksort(array, size, left, above - 1);
	lomuto_quicksort(array, size, above + 1, right);
}

/**
 * quick_sort - This function sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array of integers to sort
 * @size: The size of @array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quicksort(array, size, 0, size - 1);
}
