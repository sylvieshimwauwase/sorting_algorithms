#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_quicksort - Implement the quicksort algorithm using the Lomuto partition scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: This function sorts a subset of the array using the Lomuto partition scheme
 * and calls itself recursively to sort the remaining partitions.
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
 * quick_sort - Sort an array of integers in ascending order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quicksort(array, size, 0, size - 1);
}
