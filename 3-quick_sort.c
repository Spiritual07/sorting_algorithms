#include "sort.h"

/**
 * partition - A function performs the partitioning step
 * of the Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @low: Index of the low end of the subarray to partition.
 * @high: Index of the high end of the subarray to partition.
 * @size: Size of the array.
 * Return: The index of the pivot after partitioning.
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], temp1, temp2;
	int x = low - 1, y;

	for (y = low; y < high; y++)
	{
		if (array[y] < pivot)
		{
			x++;
			if (x != y)
			{
				temp1 = array[x];
				array[x] = array[y];
				array[y] = temp1;
				print_array(array, size);
			}
		}
	}
	if ((x + 1) != high)
	{
		temp2 = array[x + 1];
		array[x + 1] = array[high];
		array[high] = temp2;
		print_array(array, size);
	}

	return (x + 1);
}

/**
 * quick_sort_recursive - A recursive helper function for Quick Sort.
 * @array: Pointer to the array to be sorted.
 * @low: Index of the low end of the subarray to partition.
 * @high: Index of the high end of the subarray to partition.
 * @size: Size of the array.
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p_index;

	if (low < high)
	{
		p_index = partition(array, low, high, size);
	/* Recursively sort the elements before and after the partition */
		quick_sort_recursive(array, low, p_index - 1, size);
		quick_sort_recursive(array, p_index + 1, high, size);
	}
}

/**
 * quick_sort - A function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array to be sorted
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1, size);
}
