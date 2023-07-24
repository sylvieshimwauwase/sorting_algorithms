#include "sort.h"

/**
 * swap - function to swap two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
/**
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}*/

/**
 * bubble_sort - bubble sort algorithm
 * @array: pointer to array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped, temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
		}
		/**printf("%ld", i + 1);*/
		print_array(array, size);

		if (swapped == 0)
			break;
	}
}
