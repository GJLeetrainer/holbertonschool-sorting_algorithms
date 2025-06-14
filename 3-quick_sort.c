#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	if (a != b)
	{
		int temp = *a;

		*a = *b;
		*b = temp;
	}
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: The array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Array size (for printing)
 *
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}

	swap(&array[i], &array[high]);
	if (array[i] != array[high])
		print_array(array, size);

	return (i);
}

/**
 * quick_sort_recursive - Recursively applies quicksort
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Array size (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using Quick sort (Lomuto)
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
