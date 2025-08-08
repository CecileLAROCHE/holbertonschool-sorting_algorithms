#include "sort.h"

/**
 * swap - A function that swap 2 integers
 *
 * @a: First integer
 * @b: Second integer
 */

void swap(int *a, int *b)
{
	int tmp;

	if (a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}


/**
 * lomuto - Partitions the array using the Lomuto
 * partition scheme.
 * @array: The array to be partitioned.
 * @low: The starting index of the sub-array.
 * @high: The ending index of the sub-array.
 * @size: The total size of the array.
 */

static int lomuto(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}


/**
 * quick_sort_rec - Recursively sorts the array using Quick sort.
 * @array: The array to be sorted.
 * @low: The starting index of the sub-array.
 * @high: The ending index of the sub-array.
 * @size: The total size of the array.
 *
 */

static void quick_rec(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
		{
		pivot_index = lomuto(array, low, high, size);
		quick_rec(array, low, pivot_index - 1, size);
		quick_rec(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_rec(array, 0, size - 1, size);

}

