#include "sort.h"

/**
* selection_sort - Sorts an array of integers in ascending order
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;

		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
