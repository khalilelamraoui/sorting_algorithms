#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order
* using the Quick sort algorithm
*
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
* quick_sort_recursive - Sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: Non-sorted array
* @lo: Lowest index of @array
* @hi: Highest index of @array
* @size: Number of elements in @array
*/
void quick_sort_recursive(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_recursive(array, lo, p - 1, size);
		quick_sort_recursive(array, p + 1, hi, size);
	}
}

/**
* partition - Sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: Non-sorted array
* @lo: Lowest index of @array
* @hi: Highest index of @array
* @size: Number of elements in @array
*
* Return: Index of the pivot
*/
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];

	int i = lo - 1;

	int j, tmp;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = tmp;
	if (i + 1 != hi)
		print_array(array, size);
	return (i + 1);
}
