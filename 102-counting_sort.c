#include "sort.h"

/**
  * counting_sort - A function that sorts an array using counting algorithm.
  * @array: Pointer to the array to sort.
  * @size: Size of the array.
  */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *counter = NULL, k = 0, j = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	counter = malloc(sizeof(int) * (k + 1));
	if (counter == NULL)
		return;

	for (j = 0; j <= k; j++)
		counter[j] = 0;
	for (i = 0; i < size; i++)
		counter[array[i]] += 1;
	for (j = 0; j < k; j++)
	{
		counter[j + 1] += counter[j];
		printf("%d, ", counter[j]);
	}
	counter[j + 1] += counter[j];
	printf("%d\n", counter[j + 1]);
	for (i = 0; i < size; i++)
	{
		j = counter[array[i]] - 1;
		if (array[i] != array[j])
		{
			k = array[i];
			array[i] = array[j];
			array[j] = k;
		}
	}
	free(counter);
}
