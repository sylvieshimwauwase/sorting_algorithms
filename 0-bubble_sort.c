#include "sort.h"

/**
 * swap - function to swap two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - bubble sort algorithm
 * @array: pointer to array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, l = size;

	if (array == NULL || size < 2)
		return;

	while (1)
	{

		swapped = 0;
		for (i = 0; i < l - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}
		l--;

		if (swapped == 0)
			break;
	}
}
