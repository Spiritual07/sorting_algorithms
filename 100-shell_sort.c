#include "sort.h"

/**
 * shell_sort - A function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: Pointer to the array to be sorted
 * @size: Size of the array to be sorted
 */

void shell_sort(int *array, size_t size)
{
	size_t x, y, gap = 0;
	int temp;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	for (; gap > 0; gap = gap / 3)
	{
		for (x = gap; x < size; x++)
		{
			temp = array[x];
			for (y = x; y >= gap && array[y - gap] > temp; y = y - gap)
			{
				if (y < gap)
				{
					break;
				}
				if (array[y] != array[y - gap])
				{
					array[y] = array[y - gap];
				}
			}
			if (array[y] != temp)
			{
				array[y] = temp;
			}
		}
		print_array(array, size);
	}
}
