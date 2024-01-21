#include "sort.h"

/**
* merge_sort - Sorts an array of integers in ascending order
* using the Merge sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
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
	int mid;

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
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + lo, mid - lo + 1);
	printf("[right]: ");
	print_array(array + mid + 1, hi - mid);

	for (i = lo, j = mid + 1, k = lo; k <= hi; k++)
	{
		if (i == mid + 1)
		{
			tmp[k] = array[j];
			j++;
		}
		else if (j == hi + 1)
		{
			tmp[k] = array[i];
			i++;
		}
		else if (array[i] < array[j])
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

	for (i = lo; i <= hi; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(tmp + lo, hi - lo + 1);
}
