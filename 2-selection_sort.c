#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array to be sorted
 */

void selection_sort(int *array, size_t size)
{
	size_t x, y, min, temp;

	if (array == NULL || size == 0)
	{
		return;
	}
	for (x = 0; x < size - 1; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
			{
				min = y;
			}
		}
		if (min != x)
		{
			temp = array[min];
			array[min] = array[x];
			array[x] = temp;
			print_array(array, size);
		}
	}
}
