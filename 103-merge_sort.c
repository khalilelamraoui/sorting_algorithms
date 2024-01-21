#include "sort.h"

/**
* merge_sort - Sorts an array of integers in ascending order
* using the Merge sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void merge_sort(int *array, size_t size)
{
	int *tmp = NULL;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_sort_recursive(array, tmp, 0, size - 1);
	free(tmp);
}

/**
* merge_sort_recursive - Sorts an array of integers in ascending order
* using the Merge sort algorithm
* @array: Non-sorted array
* @tmp: Temporary array
* @lo: Lowest index of @array
* @hi: Highest index of @array
*/
void merge_sort_recursive(int *array, int *tmp, int lo, int hi)
{
	int mid = 0;

	if (lo < hi)
	{
		mid = (lo + hi) / 2;
		merge_sort_recursive(array, tmp, lo, mid);
		merge_sort_recursive(array, tmp, mid + 1, hi);
		merge(array, tmp, lo, mid, hi);
	}
}

/**
* merge - Sorts an array of integers in ascending order
* using the Merge sort algorithm
* @array: Non-sorted array
* @tmp: Temporary array
* @lo: Lowest index of @array
* @mid: Middle index of @array
* @hi: Highest index of @array
*/
void merge(int *array, int *tmp, int lo, int mid, int hi)
{
	int i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + lo, mid - lo + 1);
	printf("[right]: ");
	print_array(array + mid + 1, hi - mid);

	for (i = lo, j = mid + 1, k = lo; k <= hi; k++)
	{
		if (i <= mid && (j > hi || array[i] <= array[j]))
		{
			tmp[k] = array[i];
			i++;
		}
		else
		{
			tmp[k] = array[j];
			j++;
		}
	}

	for (k = lo; k <= hi; k++)
		array[k] = tmp[k];

	printf("[Done]: ");
	print_array(array + lo, hi - lo + 1);
}
