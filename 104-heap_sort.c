#include "sort.h"

/**
* heapify - A recursive function that performs the heapify
* operation on a subtree of the array.
* @array: Pointer to the array to sort
* @heap: Size of heap data
* @i: Index
* @size: Size of array
*/

void heapify(int *array, int heap, int i, int size)
{
	int index = i, left = 2 * i + 1, right = 2 * i + 2, t;

	if (left < heap && array[left] > array[index])
	{
		index = left;
	}
	if (right < heap && array[right] > array[index])
	{
		index = right;
	}
	if (index != i)
	{
		t = array[i], array[i] = array[index], array[index] = t;
		print_array(array, size);
		heapify(array, heap, index, size);
	}
}

/**
* heap_sort - A function to sorts array with heap sort algorithm
* @array: Pointer to the array to sort
* @size: Size of array to sort
*/

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
		{
			print_array(array, size);
		}
		heapify(array, i, 0, size);
	}

}
